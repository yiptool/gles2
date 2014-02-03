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
#ifndef __bcc596275155e36dedb087d60387167c__
#define __bcc596275155e36dedb087d60387167c__

#include <cstddef>

#if __cplusplus >= 201103L || defined(__clang__)
 #include <unordered_map>
 #define GL_UNORDERED_MAP_HASH std::hash
 #define GL_UNORDERED_MAP std::unordered_map
#elif defined(__GLIBCXX__)
 #include <tr1/unordered_map>
 #define GL_UNORDERED_MAP_HASH std::tr1::hash
 #define GL_UNORDERED_MAP std::tr1::unordered_map
#elif defined(_MSC_VER) && _MSC_VER >= 1500 /* Visual Studio 2008 */
 #include <unordered_map>
 #define GL_UNORDERED_MAP_HASH std::tr1::hash
 #define GL_UNORDERED_MAP std::tr1::unordered_map
#elif defined(_MSC_VER) && _MSC_VER >= 1310 /* Visual Studio .NET 2003 */
 #include <hash_map>
 #define GL_UNORDERED_MAP_HASH stdext::hash_compare
 #define GL_UNORDERED_MAP stdext::hash_map
#else
 #include <map>
 #warning Using std::map instead of std::unordered_map
 #undef GL_UNORDERED_MAP_HASH
 #define GL_UNORDERED_MAP std::map
#endif

#endif
