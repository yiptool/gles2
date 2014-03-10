/* vim: set ai noet ts=4 sw=4 tw=115: */
//
// Copyright (c) 2014 Nikolay Zapolnov (zapolnov@gmail.com).
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
#include "gl_resource_manager.h"

const std::string GLResourceManager::m_DefaultTextureName = "<texture>";
const std::string GLResourceManager::m_DefaultShaderName = "<shader>";
const std::string GLResourceManager::m_DefaultProgramName = "<program>";

GLResourceManager::GLResourceManager()
{
}

GLResourceManager::~GLResourceManager()
{
	for (const GLResourceWeakPtr & resourceWeakPtr : m_AllResources)
	{
		std::shared_ptr<GLResource> resource = resourceWeakPtr.lock();
		if (resource)
			resource->destroy();
	}
}

void GLResourceManager::collectGarbage()
{
	collectGarbageIn(m_Textures);
	collectGarbageIn(m_Shaders);
	collectGarbageIn(m_Programs);
	collectGarbageIn(m_AllResources);
}

GLTexturePtr GLResourceManager::createTexture(const std::string & name)
{
	GLTexturePtr texture = std::make_shared<GLTexture>(name);
	m_AllResources.push_back(texture);
	return texture;
}

GLTexturePtr GLResourceManager::getTexture(const std::string & name, bool * isNew)
{
	return getRes<GLTexture>(m_Textures, name, isNew);
}

GLShaderPtr GLResourceManager::createShader(GL::Enum type, const std::string & name)
{
	GLShaderPtr shader = std::make_shared<GLShader>(name, type);
	m_AllResources.push_back(shader);
	return shader;
}

GLShaderPtr GLResourceManager::getShader(GL::Enum type, const std::string & name, bool * isNew)
{
	return getRes<GLShader>(m_Shaders, std::make_pair(type, name), isNew);
}

GLProgramPtr GLResourceManager::createProgram(const std::string & name)
{
	GLProgramPtr program = std::make_shared<GLProgram>(name);
	m_AllResources.push_back(program);
	return program;
}

GLProgramPtr GLResourceManager::getProgram(const std::string & name, bool * isNew)
{
	return getRes<GLProgram>(m_Programs, name, isNew);
}

template <class T, class M, class K> std::shared_ptr<T> GLResourceManager::getRes(M & map, const K & key, bool * isNew)
{
	std::shared_ptr<T> result;
	typename M::iterator it = map.find(key);
	if (it != map.end() && (result = it->second.lock()))
	{
		if (isNew)
			*isNew = false;
		return result;
	}
	else
	{
		if (isNew)
			*isNew = true;

		std::shared_ptr<T> resource = std::make_shared<T>(key);
		if (it != map.end())
			it->second = resource;
		else
			map.insert(std::make_pair(key, resource));

		return resource;
	}
}

template <class T> static bool expired(const std::weak_ptr<T> & ptr)
{
	return ptr.expired();
}

template <class T1, class T2> static bool expired(const std::pair<T1, T2> & pair)
{
	return pair.second.expired();
}

template <class T> void GLResourceManager::collectGarbageIn(T & collection)
{
	for (auto it = collection.begin(); it != collection.end(); )
	{
		if (!expired(*it))
			++it;
		else
			it = collection.erase(it);
	}
}
