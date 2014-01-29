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
#include "gl.h"
#include "gl_error.h"
#include <stdexcept>
#include <vector>

GL::Int GL::getInteger(Enum param)
{
	Int value = 0;
	getIntegerv(param, &value);
	return value;
}

GL::UInt GL::createShaderFromSource(Enum type, const char * data)
{
	UInt shader = createShader(type);
	try
	{
		const Char * source[1] = { data };
		shaderSource(shader, 1, source, NULL);
		compileShader(shader);

		Int logLength = 0;
		getShaderiv(shader, INFO_LOG_LENGTH, &logLength);
		if (logLength > 0)
		{
			std::vector<char> log(logLength + 1, 0);
			getShaderInfoLog(shader, logLength, NULL, &log[0]);
			GL::PRINT_WARNING(&log[0]);
		}
	}
	catch (...)
	{
		deleteShader(shader);
		throw;
	}

	return shader;
}

GL::UInt GL::createShaderFromSource(Enum type, const std::string & data)
{
	return createShaderFromSource(type, data.c_str());
}

void GL::linkAndValidateProgram(UInt program)
{
	linkProgram(program);

	Int logLength = 0;
	getProgramiv(program, INFO_LOG_LENGTH, &logLength);
	if (logLength > 0)
	{
		std::vector<char> log(logLength + 1, 0);
		getProgramInfoLog(program, logLength, NULL, &log[0]);

		std::stringstream ss;
		ss << "glLinkProgram(" << program << "): " << &log[0];
		GL::PRINT_WARNING(ss.str());
	}

	validateProgram(program);

	logLength = 0;
	getProgramiv(program, INFO_LOG_LENGTH, &logLength);
	if (logLength > 0)
	{
		std::vector<char> log(logLength + 1, 0);
		getProgramInfoLog(program, logLength, NULL, &log[0]);

		std::stringstream ss;
		ss << "glValidateProgram(" << program << "): " << &log[0];
		GL::PRINT_WARNING(ss.str());
	}
}
