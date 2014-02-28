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

#include <string>
#include <cassert>
#include UNORDERED_H
#include REF_COUNTED_OBJECT_H
#include WEAK_PTR_H
#include STRONG_PTR_H

class GLResourceManager;

class GLResource : public RefCountedObject
{
public:
	inline const std::string & name() const { return m_Name; }

protected:
	GLResource(const std::string & resName);
	~GLResource();

	virtual void destroy() = 0;

private:
	std::string m_Name;

	GLResource(const GLResource &);
	GLResource & operator=(const GLResource &);

	friend class GLResourceManager;
};

typedef StrongPtr<GLResource> GLResourcePtr;
typedef WeakPtr<GLResource> GLResourceWeakPtr;

#endif
