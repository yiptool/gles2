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
#include "gl_program.h"
#include "gl_resource_manager.h"
#include <sstream>
#include <stdexcept>
#include <iostream>

GL::Program::Program(const std::string & resName)
	: Resource(resName)
{
	m_Handle = GL::createProgram();
}

GL::Program::~Program()
{
	destroy();
}

void GL::Program::link()
{
	linkProgram(m_Handle);

	Int logLength = 0;
	getProgramiv(m_Handle, INFO_LOG_LENGTH, &logLength);
	if (logLength > 0)
	{
		std::vector<char> log(static_cast<size_t>(logLength + 1), 0);
		getProgramInfoLog(m_Handle, logLength, NULL, log.data());
		std::clog << "Linking program \"" << name() << "\":\n" << log.data();
	}
}

void GL::Program::validate()
{
	validateProgram(m_Handle);

	Int logLength = 0;
	getProgramiv(m_Handle, INFO_LOG_LENGTH, &logLength);
	if (logLength > 0)
	{
		std::vector<char> log(static_cast<size_t>(logLength + 1), 0);
		getProgramInfoLog(m_Handle, logLength, NULL, log.data());
		std::clog << "Validating program \"" << name() << "\":\n" << log.data();
	}
}

void GL::Program::destroy()
{
	if (m_Handle != 0)
	{
		GL::deleteProgram(m_Handle);
		m_Handle = 0;
	}
}
