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
#ifndef __febb0d4d5a85eeec11c8faf83e369998__
#define __febb0d4d5a85eeec11c8faf83e369998__

#include "gl_resource.h"
#include "gl.h"
#include <utility>

class GLProgram;
class GLResourceManager;

class GLShader : public GLResource
{
public:
	inline GL::Enum type() const { return m_Type; }
	inline GL::UInt handle() const { return m_Handle; }

protected:
	GLShader(const std::string & resName, GL::Enum shaderType);
	GLShader(const std::pair<GL::Enum, std::string> & pair);
	~GLShader();

	void destroy();

private:
	GL::UInt m_Handle;
	GL::Enum m_Type;

	GLShader(const GLShader &);
	GLShader & operator=(const GLShader &);

	friend class GLProgram;
	friend class GLResourceManager;
};

typedef StrongPtr<GLShader> GLShaderPtr;
typedef WeakPtr<GLShader> GLShaderWeakPtr;

#endif
