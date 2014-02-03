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

GLShader::GLShader(GLResourceManager * mgr, const std::string & resName, GL::Enum type)
	: GLResource(resName),
	  m_Handle(0),
	  m_Type(type),
	  m_Manager(mgr)
{
	m_Handle = GL::createShader(type);
	if (!m_Manager->m_Shaders.insert(std::make_pair(std::make_pair(type, resName), this)).second)
	{
		std::stringstream ss;
		ss << "duplicate shader '" << resName << "' (type 0x" << std::hex << type << ").";
		throw std::runtime_error(ss.str());
	}
}

GLShader::~GLShader()
{
	destroy();
	if (m_Manager)
		m_Manager->m_Shaders.erase(std::make_pair(m_Type, name()));
}

void GLShader::destroy()
{
	if (m_Handle != 0)
	{
		GL::deleteShader(m_Handle);
		m_Handle = 0;
	}
}
