//**********************************************************************************************************************
#include "SessionService.h"

namespace Session
{
	SessionService::SessionService(Shared::NetworkManager* manager) : GenericRPCListener(manager) {
		
	}

	bool SessionService::OnIncomingQuery(Shared::NetPeer& from, Shared::Msg& message)
	{
		Shared::Serializer serializer = Shared::Serializer(message.GetBuffer(), message.GetBufferSize());
		
		
	}
} // namespace Session
