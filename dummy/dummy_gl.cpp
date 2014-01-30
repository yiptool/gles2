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
#include "../gl.h"

void GL::init()
{
}

void GL::activeTexture(Enum texture)
{
	(void)texture;
}

void GL::attachShader(UInt program, UInt shader)
{
	(void)program;
	(void)shader;
}

void GL::bindAttribLocation(UInt program, UInt index, const Char * name)
{
	(void)program;
	(void)index;
	(void)name;
}

void GL::bindBuffer(Enum target, UInt buffer)
{
	(void)target;
	(void)buffer;
}

void GL::bindFramebuffer(Enum target, UInt framebuffer)
{
	(void)target;
	(void)framebuffer;
}

void GL::bindRenderbuffer(Enum target, UInt renderbuffer)
{
	(void)target;
	(void)renderbuffer;
}

void GL::bindTexture(Enum target, UInt texture)
{
	(void)target;
	(void)texture;
}

void GL::blendColor(Clampf red, Clampf green, Clampf blue, Clampf alpha)
{
	(void)red;
	(void)green;
	(void)blue;
	(void)alpha;
}

void GL::blendEquation(Enum mode)
{
	(void)mode;
}

void GL::blendEquationSeparate(Enum modeRGB, Enum modeAlpha)
{
	(void)modeRGB;
	(void)modeAlpha;
}

void GL::blendFunc(Enum sfactor, Enum dfactor)
{
	(void)sfactor;
	(void)dfactor;
}

void GL::blendFuncSeparate(Enum srcRGB, Enum dstRGB, Enum srcAlpha, Enum dstAlpha)
{
	(void)srcRGB;
	(void)dstRGB;
	(void)srcAlpha;
	(void)dstAlpha;
}

void GL::bufferData(Enum target, Sizeiptr size, const void * data, Enum usage)
{
	(void)target;
	(void)size;
	(void)data;
	(void)usage;
}

void GL::bufferSubData(Enum target, Intptr offset, Sizeiptr size, const void * data)
{
	(void)target;
	(void)offset;
	(void)size;
	(void)data;
}

GL::Enum GL::checkFramebufferStatus(Enum target)
{
	(void)target;
	return GL::FRAMEBUFFER_UNSUPPORTED;
}

void GL::clear(Bitfield mask)
{
	(void)mask;
}

void GL::clearColor(Clampf red, Clampf green, Clampf blue, Clampf alpha)
{
	(void)red;
	(void)green;
	(void)blue;
	(void)alpha;
}

void GL::clearDepthf(Clampf depth)
{
	(void)depth;
}

void GL::clearStencil(Int s)
{
	(void)s;
}

void GL::colorMask(Boolean red, Boolean green, Boolean blue, Boolean alpha)
{
	(void)red;
	(void)green;
	(void)blue;
	(void)alpha;
}

void GL::compileShader(UInt shader)
{
	(void)shader;
}

void GL::compressedTexImage2D(Enum target, Int level, Enum internalformat, Sizei width, Sizei height,
	Int border, Sizei imageSize, const void * data)
{
	(void)target;
	(void)level;
	(void)internalformat;
	(void)width;
	(void)height;
	(void)border;
	(void)imageSize;
	(void)data;
}

void GL::compressedTexSubImage2D(Enum target, Int level, Int xoffset, Int yoffset, Sizei width,
	Sizei height, Enum format, Sizei imageSize, const void * data)
{
	(void)target;
	(void)level;
	(void)xoffset;
	(void)yoffset;
	(void)width;
	(void)height;
	(void)format;
	(void)imageSize;
	(void)data;
}

void GL::copyTexImage2D(Enum target, Int level, Enum intfmt, Int x, Int y, Sizei w, Sizei h, Int border)
{
	(void)target;
	(void)level;
	(void)intfmt;
	(void)x;
	(void)y;
	(void)w;
	(void)h;
	(void)border;
}

void GL::copyTexSubImage2D(Enum target, Int level, Int xoff, Int yoff, Int x, Int y, Sizei w, Sizei h)
{
	(void)target;
	(void)level;
	(void)xoff;
	(void)yoff;
	(void)x;
	(void)y;
	(void)w;
	(void)h;
}

GL::UInt GL::createProgram()
{
	return 0;
}

GL::UInt GL::createShader(Enum type)
{
	(void)type;
	return 0;
}

void GL::cullFace(Enum mode)
{
	(void)mode;
}

void GL::deleteBuffers(Sizei n, const UInt * buffers)
{
	(void)n;
	(void)buffers;
}

void GL::deleteFramebuffers(Sizei n, const UInt * framebuffers)
{
	(void)n;
	(void)framebuffers;
}

void GL::deleteProgram(UInt program)
{
	(void)program;
}

void GL::deleteRenderbuffers(Sizei n, const UInt * renderbuffers)
{
	(void)n;
	(void)renderbuffers;
}

void GL::deleteShader(UInt shader)
{
	(void)shader;
}

void GL::deleteTextures(Sizei n, const UInt * textures)
{
	(void)n;
	(void)textures;
}

void GL::depthFunc(Enum func)
{
	(void)func;
}

void GL::depthMask(Boolean flag)
{
	(void)flag;
}

void GL::depthRangef(Clampf zNear, Clampf zFar)
{
	(void)zNear;
	(void)zFar;
}

void GL::detachShader(UInt program, UInt shader)
{
	(void)program;
	(void)shader;
}

void GL::disable(Enum cap)
{
	(void)cap;
}

void GL::disableVertexAttribArray(UInt index)
{
	(void)index;
}

void GL::drawArrays(Enum mode, Int first, Sizei count)
{
	(void)mode;
	(void)first;
	(void)count;
}

void GL::drawElements(Enum mode, Sizei count, Enum type, const void * indices)
{
	(void)mode;
	(void)count;
	(void)type;
	(void)indices;
}

void GL::enable(Enum cap)
{
	(void)cap;
}

void GL::enableVertexAttribArray(UInt index)
{
	(void)index;
}

void GL::finish()
{
}

void GL::flush()
{
}

void GL::framebufferRenderbuffer(Enum target, Enum attachment, Enum renderbuffertarget, UInt renderbuffer)
{
	(void)target;
	(void)attachment;
	(void)renderbuffertarget;
	(void)renderbuffer;
}

void GL::framebufferTexture2D(Enum target, Enum attachment, Enum textarget, UInt texture, Int level)
{
	(void)target;
	(void)attachment;
	(void)textarget;
	(void)texture;
	(void)level;
}

void GL::frontFace(Enum mode)
{
	(void)mode;
}

void GL::genBuffers(Sizei n, UInt * buffers)
{
	(void)n;
	(void)buffers;
}

void GL::generateMipmap(Enum target)
{
	(void)target;
}

void GL::genFramebuffers(Sizei n, UInt * framebuffers)
{
	(void)n;
	(void)framebuffers;
}

void GL::genRenderbuffers(Sizei n, UInt * renderbuffers)
{
	(void)n;
	(void)renderbuffers;
}

void GL::genTextures(Sizei n, UInt * textures)
{
	(void)n;
	(void)textures;
}

void GL::getActiveAttrib(UInt prog, UInt idx, Sizei bufsz, Sizei * len, Int * sz, Enum * type, Char * name)
{
	(void)prog;
	(void)idx;
	(void)bufsz;
	(void)len;
	(void)sz;
	(void)type;
	(void)name;
}

void GL::getActiveUniform(UInt prog, UInt idx, Sizei bufsz, Sizei * len, Int * sz, Enum * type, Char * name)
{
	(void)prog;
	(void)idx;
	(void)bufsz;
	(void)len;
	(void)sz;
	(void)type;
	(void)name;
}

void GL::getAttachedShaders(UInt program, Sizei maxcount, Sizei * count, UInt * shaders)
{
	(void)program;
	(void)maxcount;
	(void)count;
	(void)shaders;
}

int GL::getAttribLocation(UInt program, const Char * name)
{
	(void)program;
	(void)name;
	return -1;
}

void GL::getBooleanv(Enum pname, Boolean * params)
{
	(void)pname;
	(void)params;
}

void GL::getBufferParameteriv(Enum target, Enum pname, Int * params)
{
	(void)target;
	(void)pname;
	(void)params;
}

GL::Enum GL::getError()
{
	return GL::INVALID_OPERATION;
}

void GL::getFloatv(Enum pname, Float * params)
{
	(void)pname;
	(void)params;
}

void GL::getFramebufferAttachmentParameteriv(Enum target, Enum attachment, Enum pname, Int * params)
{
	(void)target;
	(void)attachment;
	(void)pname;
	(void)params;
}

void GL::getIntegerv(Enum pname, Int * params)
{
	(void)pname;
	(void)params;
}

void GL::getProgramiv(UInt program, Enum pname, Int * params)
{
	(void)program;
	(void)pname;
	(void)params;
}

void GL::getProgramInfoLog(UInt program, Sizei bufsize, Sizei * length, Char * infolog)
{
	(void)program;
	(void)bufsize;
	(void)length;
	(void)infolog;
}

void GL::getRenderbufferParameteriv(Enum target, Enum pname, Int * params)
{
	(void)target;
	(void)pname;
	(void)params;
}

void GL::getShaderiv(UInt shader, Enum pname, Int * params)
{
	(void)shader;
	(void)pname;
	(void)params;
}

void GL::getShaderInfoLog(UInt shader, Sizei bufsize, Sizei * length, Char * infolog)
{
	(void)shader;
	(void)bufsize;
	(void)length;
	(void)infolog;
}

void GL::getShaderPrecisionFormat(Enum shadertype, Enum precisiontype, Int * range, Int * precision)
{
	(void)shadertype;
	(void)precisiontype;
	(void)range;
	(void)precision;
}

void GL::getShaderSource(UInt shader, Sizei bufsize, Sizei * length, Char * source)
{
	(void)shader;
	(void)bufsize;
	(void)length;
	(void)source;
}

const GL::Char * GL::getString(Enum name)
{
	(void)name;
	return "";
}

void GL::getTexParameterfv(Enum target, Enum pname, Float * params)
{
	(void)target;
	(void)pname;
	(void)params;
}

void GL::getTexParameteriv(Enum target, Enum pname, Int * params)
{
	(void)target;
	(void)pname;
	(void)params;
}

void GL::getUniformfv(UInt program, Int location, Float * params)
{
	(void)program;
	(void)location;
	(void)params;
}

void GL::getUniformiv(UInt program, Int location, Int * params)
{
	(void)program;
	(void)location;
	(void)params;
}

int GL::getUniformLocation(UInt program, const Char * name)
{
	(void)program;
	(void)name;
	return -1;
}

void GL::getVertexAttribfv(UInt index, Enum pname, Float * params)
{
	(void)index;
	(void)pname;
	(void)params;
}

void GL::getVertexAttribiv(UInt index, Enum pname, Int * params)
{
	(void)index;
	(void)pname;
	(void)params;
}

void GL::getVertexAttribPointerv(UInt index, Enum pname, void ** pointer)
{
	(void)index;
	(void)pname;
	(void)pointer;
}

void GL::hint(Enum target, Enum mode)
{
	(void)target;
	(void)mode;
}

GL::Boolean GL::isBuffer(UInt buffer)
{
	(void)buffer;
	return GL::FALSE;
}

GL::Boolean GL::isEnabled(Enum cap)
{
	(void)cap;
	return GL::FALSE;
}

GL::Boolean GL::isFramebuffer(UInt framebuffer)
{
	(void)framebuffer;
	return GL::FALSE;
}

GL::Boolean GL::isProgram(UInt program)
{
	(void)program;
	return GL::FALSE;
}

GL::Boolean GL::isRenderbuffer(UInt renderbuffer)
{
	(void)renderbuffer;
	return GL::FALSE;
}

GL::Boolean GL::isShader(UInt shader)
{
	(void)shader;
	return GL::FALSE;
}

GL::Boolean GL::isTexture(UInt texture)
{
	(void)texture;
	return GL::FALSE;
}

void GL::lineWidth(Float width)
{
	(void)width;
}

void GL::linkProgram(UInt program)
{
	(void)program;
}

void GL::pixelStorei(Enum pname, Int param)
{
	(void)pname;
	(void)param;
}

void GL::polygonOffset(Float factor, Float units)
{
	(void)factor;
	(void)units;
}

void GL::readPixels(Int x, Int y, Sizei width, Sizei height, Enum format, Enum type, void * pixels)
{
	(void)x;
	(void)y;
	(void)width;
	(void)height;
	(void)format;
	(void)type;
	(void)pixels;
}

void GL::releaseShaderCompiler()
{
}

void GL::renderbufferStorage(Enum target, Enum internalformat, Sizei width, Sizei height)
{
	(void)target;
	(void)internalformat;
	(void)width;
	(void)height;
}

void GL::sampleCoverage(Clampf value, Boolean invert)
{
	(void)value;
	(void)invert;
}

void GL::scissor(Int x, Int y, Sizei width, Sizei height)
{
	(void)x;
	(void)y;
	(void)width;
	(void)height;
}

void GL::shaderBinary(Sizei n, const UInt * shaders, Enum binaryformat, const void * binary, Sizei length)
{
	(void)n;
	(void)shaders;
	(void)binaryformat;
	(void)binary;
	(void)length;
}

void GL::shaderSource(UInt shader, Sizei count, const Char ** string, const Int * length)
{
	(void)shader;
	(void)count;
	(void)string;
	(void)length;
}

void GL::stencilFunc(Enum func, Int ref, UInt mask)
{
	(void)func;
	(void)ref;
	(void)mask;
}

void GL::stencilFuncSeparate(Enum face, Enum func, Int ref, UInt mask)
{
	(void)face;
	(void)func;
	(void)ref;
	(void)mask;
}

void GL::stencilMask(UInt mask)
{
	(void)mask;
}

void GL::stencilMaskSeparate(Enum face, UInt mask)
{
	(void)face;
	(void)mask;
}

void GL::stencilOp(Enum fail, Enum zfail, Enum zpass)
{
	(void)fail;
	(void)zfail;
	(void)zpass;
}

void GL::stencilOpSeparate(Enum face, Enum fail, Enum zfail, Enum zpass)
{
	(void)face;
	(void)fail;
	(void)zfail;
	(void)zpass;
}

void GL::texImage2D(Enum target, Int level, Int internalformat, Sizei width, Sizei height, Int border,
	Enum format, Enum type, const void * pixels)
{
	(void)target;
	(void)level;
	(void)internalformat;
	(void)width;
	(void)height;
	(void)border;
	(void)format;
	(void)type;
	(void)pixels;
}

void GL::texParameterf(Enum target, Enum pname, Float param)
{
	(void)target;
	(void)pname;
	(void)param;
}

void GL::texParameterfv(Enum target, Enum pname, const Float * params)
{
	(void)target;
	(void)pname;
	(void)params;
}

void GL::texParameteri(Enum target, Enum pname, Int param)
{
	(void)target;
	(void)pname;
	(void)param;
}

void GL::texParameteriv(Enum target, Enum pname, const Int * params)
{
	(void)target;
	(void)pname;
	(void)params;
}

void GL::texSubImage2D(Enum target, Int level, Int xoffset, Int yoffset, Sizei width, Sizei height,
		Enum format, Enum type, const void * pixels)
{
	(void)target;
	(void)level;
	(void)xoffset;
	(void)yoffset;
	(void)width;
	(void)height;
	(void)format;
	(void)type;
	(void)pixels;
}

void GL::uniform1f(Int location, Float x)
{
	(void)location;
	(void)x;
}

void GL::uniform1fv(Int location, Sizei count, const Float * v)
{
	(void)location;
	(void)count;
	(void)v;
}

void GL::uniform1i(Int location, Int x)
{
	(void)location;
	(void)x;
}

void GL::uniform1iv(Int location, Sizei count, const Int * v)
{
	(void)location;
	(void)count;
	(void)v;
}

void GL::uniform2f(Int location, Float x, Float y)
{
	(void)location;
	(void)x;
	(void)y;
}

void GL::uniform2fv(Int location, Sizei count, const Float * v)
{
	(void)location;
	(void)count;
	(void)v;
}

void GL::uniform2i(Int location, Int x, Int y)
{
	(void)location;
	(void)x;
	(void)y;
}

void GL::uniform2iv(Int location, Sizei count, const Int * v)
{
	(void)location;
	(void)count;
	(void)v;
}

void GL::uniform3f(Int location, Float x, Float y, Float z)
{
	(void)location;
	(void)x;
	(void)y;
	(void)z;
}

void GL::uniform3fv(Int location, Sizei count, const Float * v)
{
	(void)location;
	(void)count;
	(void)v;
}

void GL::uniform3i(Int location, Int x, Int y, Int z)
{
	(void)location;
	(void)x;
	(void)y;
	(void)z;
}

void GL::uniform3iv(Int location, Sizei count, const Int * v)
{
	(void)location;
	(void)count;
	(void)v;
}

void GL::uniform4f(Int location, Float x, Float y, Float z, Float w)
{
	(void)location;
	(void)x;
	(void)y;
	(void)z;
	(void)w;
}

void GL::uniform4fv(Int location, Sizei count, const Float * v)
{
	(void)location;
	(void)count;
	(void)v;
}

void GL::uniform4i(Int location, Int x, Int y, Int z, Int w)
{
	(void)location;
	(void)x;
	(void)y;
	(void)z;
	(void)w;
}

void GL::uniform4iv(Int location, Sizei count, const Int * v)
{
	(void)location;
	(void)count;
	(void)v;
}

void GL::uniformMatrix2fv(Int location, Sizei count, Boolean transpose, const Float * value)
{
	(void)location;
	(void)count;
	(void)transpose;
	(void)value;
}

void GL::uniformMatrix3fv(Int location, Sizei count, Boolean transpose, const Float * value)
{
	(void)location;
	(void)count;
	(void)transpose;
	(void)value;
}

void GL::uniformMatrix4fv(Int location, Sizei count, Boolean transpose, const Float * value)
{
	(void)location;
	(void)count;
	(void)transpose;
	(void)value;
}

void GL::useProgram(UInt program)
{
	(void)program;
}

void GL::validateProgram(UInt program)
{
	(void)program;
}

void GL::vertexAttrib1f(UInt indx, Float x)
{
	(void)indx;
	(void)x;
}

void GL::vertexAttrib1fv(UInt indx, const Float * values)
{
	(void)indx;
	(void)values;
}

void GL::vertexAttrib2f(UInt indx, Float x, Float y)
{
	(void)indx;
	(void)x;
	(void)y;
}

void GL::vertexAttrib2fv(UInt indx, const Float * values)
{
	(void)indx;
	(void)values;
}

void GL::vertexAttrib3f(UInt indx, Float x, Float y, Float z)
{
	(void)indx;
	(void)x;
	(void)y;
	(void)z;
}

void GL::vertexAttrib3fv(UInt indx, const Float * values)
{
	(void)indx;
	(void)values;
}

void GL::vertexAttrib4f(UInt indx, Float x, Float y, Float z, Float w)
{
	(void)indx;
	(void)x;
	(void)y;
	(void)z;
	(void)w;
}

void GL::vertexAttrib4fv(UInt indx, const Float * values)
{
	(void)indx;
	(void)values;
}

void GL::vertexAttribPointer(UInt indx, Int size, Enum type, Boolean norm, Sizei stride, const void * ptr)
{
	(void)indx;
	(void)size;
	(void)type;
	(void)norm;
	(void)stride;
	(void)ptr;
}

void GL::viewport(Int x, Int y, Sizei width, Sizei height)
{
	(void)x;
	(void)y;
	(void)width;
	(void)height;
}
