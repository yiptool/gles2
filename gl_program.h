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
#ifndef __de0fbe635f005208ed3510d2587da3d0__
#define __de0fbe635f005208ed3510d2587da3d0__

#include "gl_shader.h"
#include "gl_resource.h"
#include "gl.h"

class GLResourceManager;

class GLProgram : public GLResource
{
public:
	void attachShader(const GLShaderPtr & shader);
	void detachShader(const GLShaderPtr & shader);

	inline void linkAndValidate() { GL::linkAndValidateProgram(m_Handle); }

	inline void use() { GL::useProgram(m_Handle); }

protected:
	GLProgram(GLResourceManager * mgr);
	~GLProgram();

	void destroy();

private:
	GL::UInt m_Handle;
	GLResourceManager * m_Manager;

	GLProgram(const GLProgram &);
	GLProgram & operator=(const GLProgram &);

	friend class GLResourceManager;
};

typedef GLPtr<GLProgram> GLProgramPtr;

#endif
