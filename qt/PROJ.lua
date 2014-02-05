
USES_OPENGL()

USES_QT {
	"QtOpenGL"
}

DEFINES {
	"QT_GL_H=\"" .. CURRENT_SOURCE_DIR .. "/qt_gl.h\"",
}

SOURCE_FILES {
	"qt_gl.cpp",
	"qt_gl.h",
}
