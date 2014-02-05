//**********************************************************************************************************************
#include <stdio.h>
#include <stdlib.h>

#include "Broker.h"
#include "NetPeer.h"
#include "NetSocket.h"
#include "Msg.h"
#include "Serializer.h"

int main(void)
{

	WSADATA data;
	WSAStartup(MAKEWORD(2,2), &data);
	/*
	char testChar;
	int	 testint;
	short testshort;
	char testChar1;

	ser->resetIndex();

	*ser >> testChar;
	*ser >> (int)testint;
	*ser >> (short)testshort;
	*ser >> testChar1;

	printf ("Characters: %c %d %c %d\n", testChar, testint, testChar1, testshort);

	system("PAUSE");*/
	Shared::NetSocket* sock = new Shared::NetSocket();
	bool retour = sock->Bind(4242);

	printf("retour bind vaut: %d\n",retour);

	Shared::NetPeer* net = new Shared::NetPeer("127.0.0.1", 4242);
	Shared::NetPeer* netIn = new Shared::NetPeer();
	Shared::Msg* msg = new Shared::Msg();

	Shared::Serializer* ser = new Shared::Serializer(56);

	char * buf = msg->GetBuffer();
	strcpy(buf, "Helllo");
	msg->SetBufferSize(5);

	retour = sock->Send(*net, *msg);
	printf("retour send vaut: %d\n",retour);
	
	strcpy(buf, "");
	msg->SetBufferSize(0);

	retour = sock->Read(*netIn, *msg);
	printf("retour read vaut: %d\n",retour);

	printf("message : %s\n", buf);

	system("PAUSE");

	return 0;
}