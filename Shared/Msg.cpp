//**********************************************************************************************************************
#include "Msg.h"

namespace Shared
{
	Msg::Msg()
	{
		
	}

	char* Msg::GetBuffer() const
	{
		return (char*) &m_static_buffer;
	}
} 
