#ifndef __9c261e9c451bfabcb33bb46b7a14672a__
#define __9c261e9c451bfabcb33bb46b7a14672a__

#include "gl.h"

class GLVertexAttribPointer
{
public:
	inline GLVertexAttribPointer(GL::UInt index, GL::Int size, GL::Enum type, GL::Boolean normalized,
			GL::Sizei stride, const void * p)
		: m_Index(index)
	{
		GL::vertexAttribPointer(m_Index, size, type, normalized, stride, p);
		GL::enableVertexAttribArray(m_Index);
	}

	inline ~GLVertexAttribPointer()
	{
		GL::disableVertexAttribArray(m_Index);
	}

private:
	GL::UInt m_Index;

	GLVertexAttribPointer(const GLVertexAttribPointer &);
	GLVertexAttribPointer & operator=(const GLVertexAttribPointer &);
};

#endif
