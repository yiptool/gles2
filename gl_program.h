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
#ifndef __de0fbe635f005208ed3510d2587da3d0__
#define __de0fbe635f005208ed3510d2587da3d0__

#include "gl_shader.h"
#include "gl_resource.h"
#include "gl.h"

namespace GL
{
	class ResourceManager;

	/** OpenGL ES program. */
	class Program : public Resource
	{
	public:
		/**
		 * Returns raw OpenGL ES handle of the program.
		 * @return Raw handle of the program.
		 */
		inline UInt handle() const { return m_Handle; }

		/**
		 * Attaches shader to the program.
		 * This is equivalent to GL::attachShader.
		 * @param shader %Shader to attach.
		 */
		inline void attachShader(const ShaderPtr & shader) { GL::attachShader(m_Handle, shader->m_Handle); }

		/**
		 * Detaches shader from the program.
		 * This is equivalent to GL::detachShader.
		 * @param shader %Shader to detach.
		 */
		inline void detachShader(const ShaderPtr & shader) { GL::detachShader(m_Handle, shader->m_Handle); }

		/**
		 * Links the program.
		 * This is equivalent to GL::linkProgramEx.
		 */
		inline void link() { GL::linkProgramEx(m_Handle); }

		/**
		 * Checks whether this program may be run with the current OpenGL state.
		 * This is equivalent to GL::validateProgramEx.
		 */
		inline void validate() { GL::validateProgramEx(m_Handle); }

		/**
		 * Binds program into the OpenGL context.
		 * This is equivalent to GL::useProgram.
		 */
		inline void use() { GL::useProgram(m_Handle); }

//	protected:
		/**
		 * Constructor.
		 * @param resName Name of the program resource.
		 */
		Program(const std::string & resName);

		/** Destructor. */
		~Program();

		/**
		 * Releases the associated OpenGL program.
		 * This is equivalent to GL::deleteProgram.
		 */
		void destroy();

	private:
		UInt m_Handle;

		Program(const Program &) = delete;
		Program & operator=(const Program &) = delete;

		friend class ResourceManager;
	};

	/** Strong pointer to the OpenGL program. */
	typedef std::shared_ptr<Program> ProgramPtr;
	/** Weak pointer to the OpenGL program. */
	typedef std::weak_ptr<Program> ProgramWeakPtr;
}

#endif
