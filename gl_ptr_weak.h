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
#ifndef __a1bafc3baadba135ed9609ce2dc9bf92__
#define __a1bafc3baadba135ed9609ce2dc9bf92__

#include "gl_ptr.h"

class GLResource;

class GLPtrWeakBase
{
public:
	inline GLPtrWeakBase() : m_Resource(NULL) {}
	inline GLPtrWeakBase(GLResource * resource) : m_Resource(resource) { acquire(); }
	virtual inline ~GLPtrWeakBase() { release(); }

protected:
	GLResource * m_Resource;

	void acquire();
	void release();

	GLPtrWeakBase(const GLPtrWeakBase &);
	GLPtrWeakBase & operator=(const GLPtrWeakBase &);

	friend class GLResource;
};

template <class R> class GLWeakPtr : public GLPtrWeakBase
{
public:
	inline GLWeakPtr() {}
	inline GLWeakPtr(R * resource) : GLPtrWeakBase(resource) {}
	template <class T> inline GLWeakPtr(T * resource) : GLPtrWeakBase(resource) {}
	inline GLWeakPtr(const GLWeakPtr & src) : GLPtrWeakBase(src.m_Resource) {}
	template <class T> inline GLWeakPtr(const GLWeakPtr<T> & src) : GLPtrWeakBase(src.m_Resource) {}
	template <class T> inline GLWeakPtr(const GLPtr<T> & src) : GLPtrWeakBase(src.get()) {}

	inline GLWeakPtr & operator=(R * r) { release(); m_Resource = r; acquire(); return *this; }
	template <class T> inline GLWeakPtr & operator=(T * r) { release(); m_Resource = r; acquire(); return *this; }
	inline GLWeakPtr & operator=(const GLWeakPtr & s)
		{ release(); m_Resource = s.m_Resource; acquire(); return *this; }
	template <class T> inline GLWeakPtr & operator=(const GLWeakPtr<T> & s)
		{ release(); m_Resource = s.m_Resource; acquire(); return *this; }
	template <class T> inline GLWeakPtr & operator=(const GLPtr<T> & s)
		{ release(); m_Resource = s.get(); acquire(); return *this; }

	inline bool isNull() const { return !m_Resource; }
	inline bool operator!() const { return !m_Resource; }

	inline GLPtr<R> get() const { return (m_Resource ? static_cast<R *>(m_Resource) : NULL); }

	inline bool operator==(const GLWeakPtr<R> & s) const { return m_Resource == s.m_Resource; }
	template <class T> inline bool operator==(const GLWeakPtr<T> & s) const { return m_Resource == s.m_Resource; }
	inline bool operator==(const R * r) const { return m_Resource == r; }
	template <class T> inline bool operator==(const T * r) const { return m_Resource == r; }

	inline bool operator!=(const GLWeakPtr<R> & s) const { return m_Resource != s.m_Resource; }
	template <class T> inline bool operator!=(const GLWeakPtr<T> & s) const { return m_Resource != s.m_Resource; }
	inline bool operator!=(const R * r) const { return m_Resource != r; }
	template <class T> inline bool operator!=(const T * r) const { return m_Resource != r; }

private:
	template <class T> friend class GLWeakPtr;
};

#endif
