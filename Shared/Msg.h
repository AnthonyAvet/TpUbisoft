//**********************************************************************************************************************
#pragma once

namespace Shared
{
	//**********************************************************************************************************************
	class Msg
	{
	public:

		Msg();

		char* GetBuffer() const;
		size_t GetBufferSize()		const { return m_buffer_size	;}
		size_t GetBufferCapacity()	const { return m_buffer_capacity;}


	protected:

		char	m_static_buffer[/*NetSocket::MTU*/1300];
		size_t	m_buffer_size;
		size_t	m_buffer_capacity;

	};

} //namespace Shared
