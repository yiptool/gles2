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

#include "gl_shader.h"
#include "gl_program.h"
#include "gl_texture.h"
#include "gl_util.h"

class GLResourceManager
{
public:
	GLResourceManager();
	~GLResourceManager();

	GLTexturePtr getTexture(const std::string & name, bool * isNew = NULL);

	inline GLProgramPtr createProgram() { return new GLProgram(this); }
	GLShaderPtr getShader(GL::Enum type, const std::string & name, bool * isNew = NULL);

private:
	typedef std::pair<GL::Enum, std::string> ShaderMapKey;

  #ifndef GL_UNORDERED_MAP_HASH
	typedef GL_UNORDERED_MAP<ShaderMapKey, GLShader *> ShaderMap;
  #else
	struct ShaderMapKeyHasher
	{
		static const size_t bucket_size = 4;
		static const size_t min_buckets = 8;
		inline bool operator()(const ShaderMapKey & k1, const ShaderMapKey & k2) const { return k1 < k2; }
		inline size_t operator()(const ShaderMapKey & v) const
			{ return GL_UNORDERED_MAP_HASH<std::string>()(v.second); }
	};
	typedef GL_UNORDERED_MAP<ShaderMapKey, GLShader *, ShaderMapKeyHasher> ShaderMap;
  #endif

	typedef GL_UNORDERED_MAP<std::string, GLTexture *> TextureMap;
	typedef GL_UNORDERED_SET<GLProgram *> ProgramSet;

	ShaderMap m_Shaders;
	TextureMap m_Textures;
	ProgramSet m_Programs;

	GLResourceManager(const GLResourceManager &);
	GLResourceManager & operator=(const GLResourceManager &);

	friend class GLShader;
	friend class GLProgram;
	friend class GLTexture;
};

#endif
