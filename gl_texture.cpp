#include "gl_texture.h"
#include "gl_resource_manager.h"
#include <sstream>
#include <stdexcept>

GLTexture::GLTexture(GLResourceManager * mgr, const std::string & resName)
	: GLResource(resName),
	  m_Handle(0),
	  m_Manager(mgr)
{
	GL::genTextures(1, &m_Handle);
	if (!m_Manager->m_Textures.insert(std::make_pair(resName, this)).second)
	{
		std::stringstream ss;
		ss << "duplicate resource '" << resName << "'.";
		throw std::runtime_error(ss.str());
	}
}

GLTexture::~GLTexture()
{
	destroy();
	if (m_Manager)
		m_Manager->m_Textures.erase(name());
}

void GLTexture::destroy()
{
	if (m_Handle != 0)
	{
		GL::deleteTextures(1, &m_Handle);
		m_Handle = 0;
	}
}
