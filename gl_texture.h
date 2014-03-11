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
#ifndef __2266940fc02274d1b0dbb64a279b3fa2__
#define __2266940fc02274d1b0dbb64a279b3fa2__

#include "gl_resource.h"
#include "gl.h"

namespace GL
{
	/** OpenGL ES texture. */
	class Texture : public Resource
	{
	public:
		/**
		 * Binds texture into the OpenGL context.
		 * This is equivalent to GL::bindTexture.
		 * @param target Target to bind texture to (default is GL::TEXTURE_2D).
		 */
		inline void bind(Enum target = GL::TEXTURE_2D) { GL::bindTexture(target, m_Handle); }

		/**
		 * Initializes texture from resource data.
		 * @note This method binds the texture into the OpenGL context.
		 * @param data Pointer to the resource data.
		 * @param size Size of the resource data.
		 */
		void initFromResourceData(const void * data, size_t size);

		/**
		 * Initializes texture from resource data.
		 * @note This method binds the texture into the OpenGL context.
		 * @param d Resource data.
		 */
		inline void initFromResourceData(const std::string & d) { initFromResourceData(d.data(), d.size()); }

		/**
		 * Returns width of the texture in pixels.
		 * @return Width of the texture in pixels.
		 */
		int width() const { return m_Width; }

		/**
		 * Returns height of the texture in pixels.
		 * @return Height of the texture in pixels.
		 */
		int height() const { return m_Height; }

		/**
		 * Sets size of the texture in pixels.
		 * @param w Width of the texture in pixels.
		 * @param h Height of the texture in pixels.
		 */
		inline void setSize(int w, int h) { m_Width = w; m_Height = h; }

		/**
		 * Sets width of the texture in pixels.
		 * @param w Width of the texture in pixels.
		 */
		inline void setWidth(int w) { m_Width = w; }

		/**
		 * Sets height of the texture in pixels.
		 * @param w Height of the texture in pixels.
		 */
		inline void setHeight(int h) { m_Height = h; }

	protected:
		/**
		 * Constructor.
		 * @param mgr Pointer to the resource manager.
		 * @param resName Name of the texture resource.
		 */
		Texture(ResourceManager * mgr, const std::string & resName);

		/** Destructor. */
		~Texture();

		/**
		 * Releases the associated OpenGL texture.
		 * This is equivalent to GL::deleteTextures.
		 */
		void destroy();

	private:
		UInt m_Handle;
		int m_Width;
		int m_Height;

		Texture(const Texture &) = delete;
		Texture & operator=(const Texture &) = delete;

		friend class ResourceManager;
	};

	/** Strong pointer to the OpenGL ES texture. */
	typedef std::shared_ptr<Texture> TexturePtr;
	/** Weak pointer to the OpenGL ES texture. */
	typedef std::weak_ptr<Texture> TextureWeakPtr;
}

#endif
