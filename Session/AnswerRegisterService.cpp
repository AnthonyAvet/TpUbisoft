#include "AnswerRegisterService.h"

namespace Session
{
	AnswerRegisterService::AnswerRegisterService(Shared::NetworkManager& manager_in) : GenericRPC(manager_in)
	{
	}


	AnswerRegisterService::~AnswerRegisterService()
	{
	}

	// NetworkManager life call
	bool AnswerRegisterService::OnInit()
	{
	}
	bool AnswerRegisterService::OnUpdate()
	{
	}
	bool AnswerRegisterService::OnTerm()
	{
	}
		
		
	bool AnswerRegisterService::Serialize(Shared::Serializer& serializer)
	{
	}
	bool AnswerRegisterService::Unserialize(Shared::Serializer& serializer)
	{
	}

	// specified RPC to implement
	bool AnswerRegisterService::OnIncomingAnswer(const Shared::NetPeer& peerFrom_in, const Shared::Msg& answer_in)
	{
	}

}