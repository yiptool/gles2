
SUBPROJECT("gl_wrappers_normal")

if not HAS_SUBPROJECT("gl_wrappers") then
	error("This library depends on the 'gl_wrappers' library.")
end

USES_OPENGL()

SOURCE_FILES {
	"glew/include/GL/glew.h",
	"glew/include/GL/glxew.h",
	"glew/include/GL/wglew.h",
	"glew/src/glew.c.h",
	"normal_gl.cpp",
}
