//**********************************************************************************************************************
#pragma once

#include "NetPeer.h"
#include "Msg.h"
#include "Serializable.h"
#include "GenericRPC.h"

namespace Shared
{

	//**********************************************************************************************************************
	class RegisterService : public GenericRPC
	{
	public:


		RegisterService(NetworkManager& manager_in);
		virtual ~RegisterService();

		// NetworkManager life call
		virtual bool OnInit();
		virtual bool OnUpdate();
		virtual bool OnTerm();
		
		// specified RPC to implement
		virtual bool OnIncomingAnswer(const NetPeer& peerFrom_in, const Msg& answer_in) = 0;


	protected:
		QueryRegisterService m_Query;
		AnswerRegisterService m_Answer;

	};
	
	class QueryRegisterService : public Serializable
	{
		bool Serialize(Serializer& serializer);
		bool Unserialize(Serializer& serializer);

		protected :
			unsigned long m_methodID;
			unsigned long m_serviceID;
	};

	class AnswerRegisterService  : public Serializable
	{
		bool Serialize(Serializer& serializer);
		bool Unserialize(Serializer& serializer);

		protected :
			unsigned long m_methodID;
			unsigned short m_port;
			unsigned long m_IP;
	};

} //namespace Shared
