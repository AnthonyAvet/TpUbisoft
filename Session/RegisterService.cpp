#include "RegisterService.h"

namespace Session
{
	RegisterService::RegisterService(Shared::NetworkManager& manager_in) : GenericRPC(manager_in)
	{
	}


	RegisterService::~RegisterService()
	{
	}

	// NetworkManager life call
	bool RegisterService::OnInit()
	{
	}
	bool RegisterService::OnUpdate()
	{
	}
	bool RegisterService::OnTerm()
	{
	}
		
		
	bool RegisterService::Serialize(Shared::Serializer& serializer)
	{
	}
	bool RegisterService::Unserialize(Shared::Serializer& serializer)
	{
	}

	// specified RPC to implement
	bool RegisterService::OnIncomingAnswer(const Shared::NetPeer& peerFrom_in, const Shared::Msg& answer_in)
	{
	}

}