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
#ifndef __f471791f3e0fda4867317dc478eafd4f__
#define __f471791f3e0fda4867317dc478eafd4f__

#include "gl_ptr.h"
#include "gl_ptr_weak.h"
#include <string>
#include UNORDERED_H

class GLPtrWeakBase;
class GLResourceManager;

class GLResource
{
public:
	inline const std::string & name() const { return m_Name; }

	inline int refCount() const { return m_RefCount; }

	inline void retain() { ++m_RefCount; }
	inline void release() { assert(m_RefCount > 0); if (--m_RefCount == 0) deleteThis(); }

protected:
	GLResource(const std::string & resName);
	virtual ~GLResource();

	virtual void destroy() = 0;
	virtual void deleteThis();

private:
	typedef UNORDERED_SET<GLPtrWeakBase *> WeakPtrsSet;

	WeakPtrsSet m_WeakPtrs;
	int m_RefCount;
	std::string m_Name;

	GLResource(const GLResource &);
	GLResource & operator=(const GLResource &);

	friend class GLPtrWeakBase;
	friend class GLResourceManager;
};

typedef GLPtr<GLResource> GLResourcePtr;
typedef GLWeakPtr<GLResource> GLResourceWeakPtr;

#endif
