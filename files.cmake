
SET(gl_wrappers_files
	gl.cpp
	gl.h
	gl_constants.h
	gl_error.cpp
	gl_error.h
)

SET(dummy_gl_wrappers_files
	dummy/dummy_gl.cpp
)

SET(normal_gl_wrappers_files
	glew/include/GL/glew.h
	glew/include/GL/glxew.h
	glew/include/GL/wglew.h
	glew/src/glew.c.h
	normal/normal_gl.cpp
)

SET(qt_gl_wrappers_files
	qt/qt_gl.cpp
	qt/qt_gl.h
)
