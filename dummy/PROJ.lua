
SUBPROJECT("gl_wrappers_dummy")

if not HAS_SUBPROJECT("gl_wrappers") then
	error("This library depends on the 'gl_wrappers' library.")
end

SOURCE_FILES {
	"dummy_gl.cpp",
}
