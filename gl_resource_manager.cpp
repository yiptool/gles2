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
	for (ResourceList::const_iterator it = m_AllResources.begin(); it != m_AllResources.end(); ++it)
	{
		if (!it->isNull())
			it->get()->destroy();
	}
}

void GLResourceManager::collectGarbage()
{
	for (ResourceList::iterator it = m_AllResources.begin(); it != m_AllResources.end(); )
	{
		if (!it->isNull())
			++it;
		else
			it = m_AllResources.erase(it);
	}

	collectGarbageInMap(m_Textures);
	collectGarbageInMap(m_Shaders);
	collectGarbageInMap(m_Programs);
}

GLTexturePtr GLResourceManager::createTexture(const std::string & name)
{
	GLTexturePtr texture = new GLTexture(name);
	m_AllResources.push_back(texture);
	return texture;
}

GLTexturePtr GLResourceManager::getTexture(const std::string & name, bool * isNew)
{
	return getResource<GLTexture>(m_Textures, name, isNew);
}

GLShaderPtr GLResourceManager::createShader(GL::Enum type, const std::string & name)
{
	GLShaderPtr shader = new GLShader(name, type);
	m_AllResources.push_back(shader);
	return shader;
}

GLShaderPtr GLResourceManager::getShader(GL::Enum type, const std::string & name, bool * isNew)
{
	return getResource<GLShader>(m_Shaders, std::make_pair(type, name), isNew);
}

GLProgramPtr GLResourceManager::createProgram(const std::string & name)
{
	GLProgramPtr program = new GLProgram(name);
	m_AllResources.push_back(program);
	return program;
}

GLProgramPtr GLResourceManager::getProgram(const std::string & name, bool * isNew)
{
	return getResource<GLProgram>(m_Programs, name, isNew);
}

template <class T, class M, class K> GLPtr<T> GLResourceManager::getResource(M & map, const K & key, bool * isNew)
{
	typename M::iterator it = map.find(key);
	if (it != map.end() && !it->second.isNull())
	{
		if (isNew)
			*isNew = false;
		return it->second.get();
	}
	else
	{
		if (isNew)
			*isNew = true;

		GLPtr<T> resource = new T(key);
		if (it != map.end())
			it->second = resource;
		else
			map.insert(std::make_pair(key, resource));

		return resource;
	}
}

template <class M> void GLResourceManager::collectGarbageInMap(M & map)
{
	for (typename M::iterator it = map.begin(); it != map.end(); )
	{
		if (!it->second.isNull())
			++it;
		else
			it = map.erase(it);
	}
}
