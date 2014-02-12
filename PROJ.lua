
SUBPROJECT("gl_wrappers")

if not HAS_SUBPROJECT("cxx-util") then
	error("This library depends on the 'cxx-util' library.")
end

DEFINES {
	"GL_H=\"" .. CURRENT_SOURCE_DIR .. "/gl.h\"",
	"GL_ERROR_H=\"" .. CURRENT_SOURCE_DIR .. "/gl_error.h\"",
	"GL_RESOURCE_H=\"" .. CURRENT_SOURCE_DIR .. "/gl_resource.h\"",
	"GL_RESOURCE_MANAGER_H=\"" .. CURRENT_SOURCE_DIR .. "/gl_resource_manager.h\"",
	"GL_PROGRAM_H=\"" .. CURRENT_SOURCE_DIR .. "/gl_program.h\"",
	"GL_SHADER_H=\"" .. CURRENT_SOURCE_DIR .. "/gl_shader.h\"",
	"GL_TEXTURE_H=\"" .. CURRENT_SOURCE_DIR .. "/gl_texture.h\"",
	"GL_VERTEX_ATTRIB_POINTER_H=\"" .. CURRENT_SOURCE_DIR .. "/gl_vertex_attrib_pointer.h\"",
}

SOURCE_FILES {
	"gl.cpp",
	"gl.h",
	"gl_constants.h",
	"gl_error.cpp",
	"gl_error.h",
	"gl_program.cpp",
	"gl_program.h",
	"gl_ptr.h",
	"gl_ptr_weak.cpp",
	"gl_ptr_weak.h",
	"gl_resource.cpp",
	"gl_resource.h",
	"gl_resource_manager.cpp",
	"gl_resource_manager.h",
	"gl_shader.cpp",
	"gl_shader.h",
	"gl_texture.cpp",
	"gl_texture.h",
	"gl_vertex_attrib_pointer.h",
}
