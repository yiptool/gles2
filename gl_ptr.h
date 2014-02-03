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
#ifndef __4b1711703b1241caa559152b6bda34fe__
#define __4b1711703b1241caa559152b6bda34fe__

#include <cstddef>
#include <cassert>

template <class R> class GLPtr
{
public:
	inline GLPtr() : p(NULL) {}
	inline GLPtr(R * o) : p(o) { acquire(p); }
	template <class T> inline GLPtr(T * o) : p(o) { acquire(p); }
	inline GLPtr(const GLPtr & src) : p(src.p) { acquire(p); }
	template <class T> inline GLPtr(const GLPtr<T> & src) : p(src.p) { acquire(p); }
	inline ~GLPtr() { release(); }

	inline GLPtr & operator=(R * o) { acquire(o); release(); p = o; return *this; }
	template <class T> inline GLPtr & operator=(T * o) { acquire(o); release(); p = o; return *this; }
	inline GLPtr & operator=(const GLPtr & src) { acquire(src.p); release(); p = src.p; return *this; }
	template <class T> inline GLPtr & operator=(const GLPtr<T> & s)
		{ acquire(s.p); release(); p = s.p; return *this; }

	void release() { if (p) { p->release(); p = NULL; } }

	inline bool isNull() const { return !p; }
	inline bool operator!() const { return !p; }

	inline R * get() const { return p; }

	inline R & operator*() const { ASSERT(p); return *p; }
	inline R * operator->() const { ASSERT(p); return p; }

	inline bool operator==(const GLPtr<R> & src) const { return p == src.p; }
	template <class T> inline bool operator==(const GLPtr<T> & src) const { return p == src.p; }
	inline bool operator==(const R * src) const { return p == src; }
	template <class T> inline bool operator==(const T * src) const { return p == src; }

	inline bool operator!=(const GLPtr<R> & src) const { return p != src.p; }
	template <class T> inline bool operator!=(const GLPtr<T> & src) const { return p != src.p; }
	inline bool operator!=(const R * src) const { return p != src; }
	template <class T> inline bool operator!=(const T * src) const { return p != src; }

private:
	R * p;

	void acquire(R * o) const { if (o) o->retain(); }

	template <class T> friend class GLPtr;
};

#endif
