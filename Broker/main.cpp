//**********************************************************************************************************************
#include <stdio.h>
#include <stdlib.h>

#include "Broker.h"
#include "NetPeer.h"
#include "NetSocket.h"
#include "Msg.h"
#include "Serializer.h"
#include "NetworkManager.h"

int main(void)
{

	WSADATA data;
	WSAStartup(MAKEWORD(2,2), &data);
	
	/////////////////////////////////////////////////
	// test part 1
	/////////////////////////////////////////////////
	Shared::Serializer* ser01 = new Shared::Serializer(56);
	char testChar;
	int	 testint;
	short testshort;
	char testChar1;

	*ser01 << 'a';
	*ser01 << (int) 12;
	*ser01 << (short) 21;
	*ser01 << 'k';

	ser01->resetIndex();

	*ser01 >> testChar;
	*ser01 >> (int)testint;
	*ser01 >> (short)testshort;
	*ser01 >> testChar1;

	printf ("Characters: %c %d %c %d\n", testChar, testint, testChar1, testshort);

	system("PAUSE");

	/////////////////////////////////////////////////
	// test part 2
	/////////////////////////////////////////////////
	Shared::NetSocket* sock = new Shared::NetSocket();
	bool retour = sock->Bind(4242);

	printf("retour bind vaut: %d\n",retour);

	Shared::NetPeer* net = new Shared::NetPeer("127.0.0.1", 4242);
	Shared::NetPeer* netIn = new Shared::NetPeer();
	Shared::Msg* msg = new Shared::Msg();
	Shared::Msg* msgReception = new Shared::Msg();

	Shared::Serializer* ser = new Shared::Serializer(msg->GetBuffer(),msg->GetBufferCapacity());
	* ser << 'A';
	* ser << 'n';
	* ser << (int) 6;
	* ser << 't';
	* ser << 'h';
	* ser << 'o';

	msg->SetBufferSize(ser->getBufferSize());

	retour = sock->Send(*net, *msg);
	printf("retour send vaut: %d\n",retour);

	Shared::Serializer* serRetour = new Shared::Serializer(msgReception->GetBuffer(),msgReception->GetBufferCapacity());

	retour = sock->Read(*netIn, *msgReception);
	printf("retour read vaut: %d\n",retour);
	char retourChar[5];
	
	int val=0;

	*serRetour >> retourChar[0];
	*serRetour >> retourChar[1];
	*serRetour >> (int) val;
	*serRetour >> retourChar[2];
	*serRetour >> retourChar[3];
	*serRetour >> retourChar[4];

	printf("message : %s +  %d\n", retourChar, val);

	system("PAUSE");
	/////////////////////////////////////////////////
	// test part 3
	/////////////////////////////////////////////////
	Shared::NetworkManager ntm = Shared::NetworkManager(*net, 4242);

	ntm.SendToBroker(*msg);
	
	retour = sock->Read(*netIn, *msgReception);
	printf("retour read vaut: %d\n",retour);

	serRetour->resetIndex();

	*serRetour >> retourChar[0];
	*serRetour >> retourChar[1];
	*serRetour >> (int) val;
	*serRetour >> retourChar[2];
	*serRetour >> retourChar[3];
	*serRetour >> retourChar[4];

	printf("message : %s +  %d\n", retourChar, val);

	system("PAUSE");
	return 0;
}