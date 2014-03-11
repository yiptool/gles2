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
#include "gl_resource_loader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

GL::ResourceLoader::~ResourceLoader()
{
}

std::string GL::ResourceLoader::loadResource(const std::string & name)
{
	ResourceStreamPtr stream = openResource(name);

	std::string result((std::istreambuf_iterator<char>(*stream)), std::istreambuf_iterator<char>());
	if (stream->fail() || stream->bad())
	{
		std::stringstream ss;
		ss << "error reading resource file '" << name << "'.";
		throw std::runtime_error(ss.str());
	}

	return result;
}

GL::ResourceStreamPtr GL::ResourceLoader::openResource(const std::string & name)
{
	std::shared_ptr<std::ifstream> stream = std::make_shared<std::ifstream>();

	stream->open(name.c_str(), std::ios::in | std::ios::binary);
	if (!stream->is_open() || stream->fail() || stream->bad())
	{
		std::stringstream ss;
		ss << "unable to open resource file '" << name << "'.";
		throw std::runtime_error(ss.str());
	}

	return stream;
}

GL::ResourceLoader & GL::ResourceLoader::standard()
{
	static GL::ResourceLoader instance;
	return instance;
}
