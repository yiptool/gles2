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
#include "gl_resource_manager.h"
#include "gl_shader.h"
#include "gl_error.h"
#include <cstring>
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
	try {
		initShaderFromSource(shader, data);
	} catch (...) {
		deleteShader(shader);
		throw;
	}
	return shader;
}

GL::UInt GL::createShaderFromSource(Enum type, const std::string & data)
{
	return createShaderFromSource(type, data.c_str());
}

void GL::initShaderFromSource(UInt shader, const char * data)
{
	const Char * source[1] = { data };
	shaderSource(shader, 1, source, NULL);
	compileShader(shader);

	Int logLength = 0;
	getShaderiv(shader, INFO_LOG_LENGTH, &logLength);
	if (logLength > 0)
	{
		std::vector<char> log(static_cast<size_t>(logLength + 1), 0);
		getShaderInfoLog(shader, logLength, NULL, &log[0]);
		GL::PRINT_WARNING(&log[0]);
	}
}

void GL::initShaderFromSource(UInt shader, const std::vector<const char *> & data)
{
	shaderSource(shader, static_cast<Sizei>(data.size()), (const Char **)&data[0], NULL);
	compileShader(shader);

	Int logLength = 0;
	getShaderiv(shader, INFO_LOG_LENGTH, &logLength);
	if (logLength > 0)
	{
		std::vector<char> log(static_cast<size_t>(logLength + 1), 0);
		getShaderInfoLog(shader, logLength, NULL, &log[0]);
		GL::PRINT_WARNING(&log[0]);
	}
}

void GL::initShaderFromSource(UInt shader, const std::string & data)
{
	return initShaderFromSource(shader, data.c_str());
}

static bool iswhite(char ch)
{
	return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n';
}

void GL::initProgramFromSource(UInt program, const char * data, GLResourceManager * resmgr,
	PFNLOADSHADERPROC loadFile)
{
	std::vector<std::string> lines;

	for (const char * p = data; ; )
	{
		const char * end = strchr(p, '\n');
		if (end)
		{
			size_t length = end - p;
			while (length > 0 && iswhite(p[length - 1]))
				--length;
			lines.push_back(std::string(p, length));
			p = end + 1;
		}
		else
		{
			size_t length = strlen(p);
			while (length > 0 && iswhite(p[length - 1]))
				--length;
			lines.push_back(std::string(p, length));
			break;
		}
	}

	std::vector<const char *> vertex;
	std::vector<const char *> fragment;

	vertex.reserve(lines.size());
	fragment.reserve(lines.size());

	bool hasVertex = false, hasFragment = 0;
	Enum type = NONE;
	for (std::vector<std::string>::const_iterator it = lines.begin(); it != lines.end(); ++it)
	{
		if (it->c_str()[0] != '%')
		{
			vertex.push_back(type == NONE || type == VERTEX_SHADER ? it->c_str() : "");
			fragment.push_back(type == NONE || type == FRAGMENT_SHADER ? it->c_str() : "");
		}
		else
		{
			const std::string & str = *it;
			const char * file = NULL;

			vertex.push_back("");
			fragment.push_back("");

			if (str.length() >= 7 && !memcmp(str.c_str(), "%vertex", 7))
			{
				type = VERTEX_SHADER;
				file = str.c_str() + 7;
			}
			else if (str.length() >= 9 && !memcmp(str.c_str(), "%fragment", 9))
			{
				type = FRAGMENT_SHADER;
				file = str.c_str() + 9;
			}
			else
			{
				std::stringstream ss;
				ss << "invalid directive '" << str << "' in the vertex program.";
				throw std::runtime_error(ss.str());
			}

			if (file)
			{
				while (iswhite(*file))
					++file;
				if (!*file)
					file = NULL;
			}

			if (!file)
			{
				if (type == VERTEX_SHADER)
					hasVertex = true;
				else if (type == FRAGMENT_SHADER)
					hasFragment = true;
			}
			else if (!resmgr || !loadFile)
			{
				std::stringstream ss;
				ss << "unable to load file '" << file << "': resource manager is not available.";
				throw std::runtime_error(ss.str());
			}
			else
			{
				std::string filename(file);
				bool isNew = false;
				GLShaderPtr shader = resmgr->getShader(type, filename, &isNew);
				if (isNew)
					initShaderFromSource(shader->handle(), loadFile(filename));
				attachShader(program, shader->handle());
			}
		}
	}

	if (hasVertex)
	{
		UInt shader = createShader(VERTEX_SHADER);
		try {
			initShaderFromSource(shader,vertex);
			attachShader(program, shader);
		} catch (...) {
			deleteShader(shader);
			throw;
		}
		deleteShader(shader);
	}

	if (hasFragment)
	{
		UInt shader = createShader(FRAGMENT_SHADER);
		try {
			initShaderFromSource(shader, fragment);
			attachShader(program, shader);
		} catch (...) {
			deleteShader(shader);
			throw;
		}
		deleteShader(shader);
	}
}

void GL::initProgramFromSource(UInt program, const std::string & data, GLResourceManager * resmgr,
	PFNLOADSHADERPROC loadFile)
{
	return initProgramFromSource(program, data.c_str(), resmgr, loadFile);
}

void GL::linkAndValidateProgram(UInt program)
{
	linkProgram(program);

	Int logLength = 0;
	getProgramiv(program, INFO_LOG_LENGTH, &logLength);
	if (logLength > 0)
	{
		std::vector<char> log(static_cast<size_t>(logLength + 1), 0);
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
		std::vector<char> log(static_cast<size_t>(logLength + 1), 0);
		getProgramInfoLog(program, logLength, NULL, &log[0]);

		std::stringstream ss;
		ss << "glValidateProgram(" << program << "): " << &log[0];
		GL::PRINT_WARNING(ss.str());
	}
}
