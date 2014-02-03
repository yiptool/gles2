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
#include "gl_texture.h"
#include "gl_resource_manager.h"
#include <sstream>
#include <stdexcept>

GLTexture::GLTexture(GLResourceManager * mgr, const std::string & resName)
	: GLResource(resName),
	  m_Handle(0),
	  m_Manager(mgr)
{
	GL::genTextures(1, &m_Handle);
	if (!m_Manager->m_Textures.insert(std::make_pair(resName, this)).second)
	{
		std::stringstream ss;
		ss << "duplicate resource '" << resName << "'.";
		throw std::runtime_error(ss.str());
	}
}

GLTexture::~GLTexture()
{
	destroy();
	if (m_Manager)
		m_Manager->m_Textures.erase(name());
}

void GLTexture::destroy()
{
	if (m_Handle != 0)
	{
		GL::deleteTextures(1, &m_Handle);
		m_Handle = 0;
	}
}
