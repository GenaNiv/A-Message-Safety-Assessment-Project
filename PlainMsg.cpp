/*
 * PlainMsg.cpp
 *
 *  Created on: May 25, 2015
 *      Author: gena
 */

#include "PlainMsg.h"
#include<iostream>
namespace std {
//initializer constructor
PlainMsg::PlainMsg(const string& msg, double sffactor, int msglenght, SecurLevel OwnClass):Msg(msg,sffactor)
{
	SetMsgLen(msglenght);
	SetSecurerLevel(OwnClass);
	updateSafeFactor();
}

PlainMsg::~PlainMsg() { /*cout << " \nPlainMsg derived class destructor called..." << endl;*/ }

//method that calculates a final safe factor
void PlainMsg::updateSafeFactor()
{
	SafeFactor = (0.7)*ownerClass + (0.3)*(1/msglen);
}//end

//setters
void PlainMsg::SetMsgLen(int MSGlen){msglen = MSGlen;}

void PlainMsg::SetSecurerLevel(SecurLevel threatL){ownerClass = threatL;}

//getters
int PlainMsg::GetMsgLen(void){return msglen;}

SecurLevel PlainMsg::GetSecurerLevel(void){return ownerClass;}
//function show message content
void PlainMsg::show() const
{
	cout << "\nPlainMsg: ";
	cout << "\nsafeFactor: " <<PlainMsg::SafeFactor;
	cout << "\nMsg Len: " << PlainMsg::msglen;
	cout << "\nOwner Class: ";
	if(PlainMsg::ownerClass == A)
	{
		cout << "CLS_A " << endl;
	}
	else if (PlainMsg::ownerClass == B)
	{
		cout << "CLS_B " << endl;
	}
	else if (PlainMsg::ownerClass == C)
	{
			cout << "CLS_C " << endl;
	}
	else if (PlainMsg::ownerClass == D)
			cout << "CLS_D " << endl;

}//end show func



} /* namespace std */






