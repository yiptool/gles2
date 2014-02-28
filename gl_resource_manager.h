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
#ifndef __bd60f34af632e5ad2a9b5bb6a5b67443__
#define __bd60f34af632e5ad2a9b5bb6a5b67443__

#include "gl_texture.h"
#include "gl_shader.h"
#include "gl_program.h"
#include <vector>
#include UNORDERED_H

namespace GL
{
	typedef std::pair<GL::Enum, std::string> ShaderMapKey;
	UNORDERED_HASH_FUNC(ShaderMapKeyHasher, return UNORDERED_HASH<std::string>()(value.second))
}

class GLResourceManager
{
public:
	GLResourceManager();
	virtual ~GLResourceManager();

	virtual void collectGarbage();

	GLTexturePtr createTexture(const std::string & name = m_DefaultTextureName);
	GLTexturePtr getTexture(const std::string & name, bool * isNew);

	GLShaderPtr createShader(GL::Enum type, const std::string & name = m_DefaultShaderName);
	GLShaderPtr getShader(GL::Enum type, const std::string & name, bool * isNew);

	GLProgramPtr createProgram(const std::string & name = m_DefaultProgramName);
	GLProgramPtr getProgram(const std::string & name, bool * isNew);

private:
	typedef UNORDERED_MAP<std::string, GLTextureWeakPtr> TextureMap;
	typedef UNORDERED_MAP<std::string, GLProgramWeakPtr> ProgramMap;
	typedef UNORDERED_MAP<GL::ShaderMapKey, GLShaderWeakPtr, GL::ShaderMapKeyHasher> ShaderMap;
	typedef std::vector<GLResourceWeakPtr> ResourceList;

	static const std::string m_DefaultTextureName;
	static const std::string m_DefaultShaderName;
	static const std::string m_DefaultProgramName;

	ResourceList m_AllResources;
	TextureMap m_Textures;
	ShaderMap m_Shaders;
	ProgramMap m_Programs;

	template <class T, class M, class K> StrongPtr<T> getRes(M & map, const K & key, bool * isNew);
	template <class M> void collectGarbageInMap(M & map);

	GLResourceManager(const GLResourceManager &);
	GLResourceManager & operator=(const GLResourceManager &);

	friend class GLShader;
	friend class GLProgram;
	friend class GLTexture;
};

#endif
