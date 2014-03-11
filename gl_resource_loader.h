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
#ifndef __4d228f167919cb9cb5be84833a71acff__
#define __4d228f167919cb9cb5be84833a71acff__

#include <string>
#include <istream>
#include <memory>

namespace GL
{
	class ResourceLoader;

	/** Strong pointer to the resource loader. */
	typedef std::shared_ptr<ResourceLoader> ResourceLoaderPtr;

	/** Strong pointer to the instance of *std::istream*. */
	typedef std::shared_ptr<std::istream> ResourceStreamPtr;

	/**
	 * Loader for resource files.
	 * This class loads resources from the current directory of the application using the
	 * *std::ifstream* class. If this is not desirable, custom instance of the resource loader
	 * could be set using the setInstance() method.
	 */
	class ResourceLoader
	{
	public:
		/** Constructor. */
		inline ResourceLoader() noexcept {}

		/** Destructor. */
		virtual ~ResourceLoader();

		/**
		 * Loads the specified resource file into memory.
		 * @param name Name of the resource file.
		 * @return Resource data.
		 * @throws std::runtime_error if resource file could not be loaded.
		 */
		virtual std::string loadResource(const std::string & name);

		/**
		 * Opens the specified resource file for reading.
		 * @param name Name of the resource file.
		 * @return Input stream for the resource.
		 * @throws std::runtime_error if resource file could not be opened.
		 */
		virtual ResourceStreamPtr openResource(const std::string & name);

		/**
		 * Returns reference to the standard resource loader.
		 * @return Reference to the standard resource loader.
		 */
		static ResourceLoader & standard();

	private:
		ResourceLoader(const ResourceLoader &) = delete;
		ResourceLoader & operator=(const ResourceLoader &) = delete;
	};
}

#endif
