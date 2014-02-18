//**********************************************************************************************************************
#include "RegisterService.h"

namespace Shared
{

	RegisterService::RegisterService(NetworkManager& manager_in) : GenericRPC(manager_in)
	{
		m_IN = &m_Query;
		m_OUT = &m_Answer;
	}

	
	////////////////////////////////////////////////////////////
	// QueryRegisterService
	////////////////////////////////////////////////////////////
	bool QueryRegisterService::Serialize(Serializer& serializer)
	{
		serializer << m_methodID;
		serializer << m_serviceID;
	}
	bool QueryRegisterService::Unserialize(Serializer& serializer)
	{
		serializer >> m_methodID;
		serializer >> m_serviceID;
	}
	////////////////////////////////////////////////////////////
	// AnswerRegisterService
	////////////////////////////////////////////////////////////
	bool AnswerRegisterService::Serialize(Serializer& serializer)
	{
		serializer << m_methodID;
		serializer << m_port;
		serializer << m_IP;
	}
	bool AnswerRegisterService::Unserialize(Serializer& serializer)
	{
		serializer >> m_methodID;
		serializer >> m_port;
		serializer >> m_IP;
	}
} //namespace Shared
