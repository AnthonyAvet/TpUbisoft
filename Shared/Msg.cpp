//**********************************************************************************************************************
#include "Msg.h"

namespace Shared
{
	Msg::Msg()
	{
			m_buffer_size = 0;
	}

	char* Msg::GetBuffer() const
	{
		return (char*) &m_static_buffer;
	}
} 
