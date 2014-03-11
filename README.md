
GLWrappers
==========

This is the convenient C++11 library for cross-platform OpenGL ES 2.0 programming.

Please note that OpenGL ES context creation and management is outside of the scope
of this library. This library only provides convenient wrappers for OpenGL ES API on
both the desktop and mobile platforms.

This README contains a quick tour over the features of the library. For complete
list of types, constants, functions and classes, please build the reference manual
using the [Doxygen](http://www.stack.nl/~dimitri/doxygen/) tool.

Wrappers
--------

All OpenGL types, constants, and functions are wrapped into the *GL* namespace.
For example, to call the *glClear* function you may write the following piece
of code:

     GL::clear(GL::COLOR_BUFFER_BIT | GL::DEPTH_BUFFER_BIT);

In debug builds, all calls to OpenGL functions are checked with *glError*
calls. Any detected problems are reported to *std::clog*.

Currently, there are three wrappers available:

1. The **normal** wrapper is for use in all projects except for those built
   using the Qt library. On systems with OpenGL ES 2.0 support this wrapper
   invokes OpenGL ES functions directly. On desktop systems (Windows, Unix,
   OSX) OpenGL ES calls are emulated through the full version of OpenGL (with
   the help of the [OpenGL Extension Wrangler](http://glew.sourceforge.net/)
   library).

2. The **qt** wrapper is intended for use in projects built with the
   [Qt library](http://qt-project.org/) (version 4.8 or later). OpenGL calls
   are made through the
   [QGLFunctions](http://qt-project.org/doc/qt-4.8/qglfunctions.html) class.

3. At last, there is the **dummy** wrapper with all functions implemented as
   empty stubs. This wrapper is useful for compilation on platforms without
   OpenGL support and as a skeleton for new wrappers.


Resource management
-------------------

This library includes convenient C++ wrappers for OpenGL resources (textures,
shaders, etc.).

The *GL::Resource* class is a base class for all OpenGL resources. All managed
resources have names which could be obtained using the *name()* method
(usually resource name is a name of file from which resource has been loaded).

The *GL::ResourceManager* class is a manager of resources. It creates instances
of resources and tracks their usage.

### Resource loading

There are convenient methods available in the *GL::ResourceManager* class:

*getShader(type, name)*  
*getProgram(name)*  
*getTexture(name)*  

These methods load shaders, programs and textures respectively from files
with the specified *name* and store them in the resource manager. If resource
is already in memory, then these methods simply return a reference to the
same resource.

#### File format of shaders

Shaders are simply a source file in the GLSL language.

Please note that you have to support both GLSL and ESSL (OpenGL ES dialect of
GLSL) in your shaders. For example, in OpenGL ES you have to specify floating-point
precision in the fragment shader. This is not supported in "desktop" OpenGL.

You could use the *GL_ES* preprocessor definition to distinguish ESSL from GLSL:

     #ifdef GL_ES
     precision mediump float;
     #endif

#### File format of programs

Programs are represented using a simple text format.

Each line of a program file is either an empty line, a directive or a shader source
code. Empty lines are ignored. Lines starting with the '%' symbol are considered
directives. Only two directives are allowed: *%vertex* and *%fragment*.

The *%vertex* directive starts source code of a vertex shader. The *%fragment*
directive starts source of a fragment shader. Optionally you could specify a
file name for any of this directives. In this case shader will be loaded from
the specified file.

Sample program file:

     %vertex

     attribute vec2 a_position;
     void main()
     {
         gl_Position = a_position;
     }

     %fragment

     #ifdef GL_ES
     precision mediump float;
     #endif

     void main()
     {
         gl_FragColor = vec4(1.0f);
     }

Sample program file that loads shaders from another files:

     %vertex shader.vsh
     %fragment shader.fsh

Please note that shader file names are relative to the resources directory, not
to the directory where the program file is located.

### Dynamic resource creation

If you wouldn't like to load resource from file and would like to create it
dynamically, then the following methods are available:

*createShader(type, name)*  
*createProgram(name)*  
*createTexture(name)*  

Note that these methods do not register resource in the manager. This means
that *getShader*, *getProgram* and *getTexture* methods will not be able to
retrieve these resources by their names. The only place where the name you pass
to these methods is used, is the return value of the *name()* method of the
corresponding instance of *GL::Resource*.

### Resource tracking

For *GL::ResourceManager* to work properly you have to periodically call the
*collectGarbage()* method. If you decline to do so, negligible memory leaks
are possible.

Please note that resource manager does not implement any caching: resources are
considered alive only while there is at least one reference to them. If you want
to cache the resources, you have to subclass the *GL::ResourceManager* class and
implement caching functionality yourself.


Compiling this library
======================

This library is not intended to be built directly. Instead it is supposed
to be included into projects using the *buildtool*. Please consult the
[buildtool](https://github.com/zapolnov/buildtool) documentation for more
information.


License
=======

Copyright © 2014 Nikolay Zapolnov (zapolnov@gmail.com).

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

-------

**The OpenGL Extension Wrangler Library**<br />
Copyright © 2002-2008, Milan Ikits (milan ikits[]ieee org)<br />
Copyright © 2002-2008, Marcelo E. Magallon (mmagallo[]debian org)<br />
Copyright © 2002, Lev Povalahev<br />
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
* The name of the author may be used to endorse or promote products
  derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
THE POSSIBILITY OF SUCH DAMAGE.

-------

**Mesa 3-D graphics library**<br />
Version:  7.0

Copyright © 1999-2007  *Brian Paul*   All Rights Reserved.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
BRIAN PAUL BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

-------

Copyright © 2007 The Khronos Group Inc.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and/or associated documentation files (the
"Materials"), to deal in the Materials without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Materials, and to
permit persons to whom the Materials are furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Materials.

THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.

-------

**Doxygen comments for some constants, functions and methods are based on the
[OpenGL ES 2.0 Reference Pages](http://www.khronos.org/opengles/sdk/docs/man/)**.

Copyright © 1991-2006 Silicon Graphics, Inc.  
This document is licensed under the
[SGI Free Software B License](http://oss.sgi.com/projects/FreeB/).

Copyright © 2003-2005 3Dlabs Inc. Ltd.  
Copyright © 2005 Addison-Wesley.  
Copyright © 2006, 2008 Khronos Group.  
This material may be distributed subject to the terms and conditions set
forth in the [Open Publication License](http://opencontent.org/openpub/),
v1.0, 8 June 1999.
