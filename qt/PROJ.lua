
SUBPROJECT("gl_wrappers_qt")

if not HAS_SUBPROJECT("gl_wrappers") then
	error("This library depends on the 'gl_wrappers' library.")
end

USES_OPENGL()

USES_QT {
	"QtOpenGL"
}

SOURCE_FILES {
	"qt_gl.cpp",
}
