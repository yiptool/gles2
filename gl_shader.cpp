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
#include "gl_shader.h"
#include "gl_resource_manager.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>

GLShader::GLShader(const std::string & resName, GL::Enum type)
	: GLResource(resName),
	  m_Handle(0),
	  m_Type(type)
{
	m_Handle = GL::createShader(m_Type);
}

GLShader::GLShader(const std::pair<GL::Enum, std::string> & pair)
	: GLResource(pair.second),
	  m_Handle(0),
	  m_Type(pair.first)
{
	m_Handle = GL::createShader(m_Type);
}

GLShader::~GLShader()
{
	destroy();
}

void GLShader::destroy()
{
	if (m_Handle != 0)
	{
		GL::deleteShader(m_Handle);
		m_Handle = 0;
	}
}
