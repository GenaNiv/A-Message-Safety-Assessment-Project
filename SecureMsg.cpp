/*
 * SecureMsg.cpp
 *
 *  Created on: May 25, 2015
 *      Author: gena
 */

#include "SecureMsg.h"
#include<cstring>
#include<iostream>

namespace std {
//initialize list constructor
SecureMsg::SecureMsg(const string& msg, double sffactor, securityType ST, keyStrength KS, int meslength):
Msg(msg,sffactor)
{
	SetSecType(ST) ;
	SetStrgthlevel(KS);
	SetMsgLength(meslength);
	updateSafeFactor();
}
//destructor
SecureMsg::~SecureMsg() { /*cout << " \nSecureMsg derived class destructor called..." << endl; */}

//method that calculates a final safe factor
void SecureMsg::updateSafeFactor()
{
	Msg::SafeFactor = (0.4)*GetSecType() + (0.3)*GetStrgthlevel() + (0.3)*(1/GetMsgLength());
}//end

//seters
void SecureMsg::SetSecType(securityType SecT){ SecType = SecT;}
void SecureMsg::SetStrgthlevel(keyStrength KeyStr){ Strgthlevel = KeyStr;}

//gtters
securityType SecureMsg::GetSecType(void) { return SecType; }
keyStrength SecureMsg::GetStrgthlevel(void) { return Strgthlevel; }
//show function
void SecureMsg::show() const
{
	cout << "\nSecureMsg: ";
	cout << "\nsafeFactor: " <<SecureMsg::SafeFactor;
	cout << "\nMsg Length: " << SecureMsg::msglength;
	cout << "\nSecurity type: ";
	if(SecureMsg::SecType == PWD)
	{
		cout << "PWD ";
	}
	else if (SecureMsg::SecType == AES)
	{
		cout << "AES ";
	}
	else if (SecureMsg::SecType == PKI)
	{
		cout << "PKI ";
	}
	else if (SecureMsg::SecType == SSL)
		cout << "SSL ";

	cout << "  keyStrength: ";

	if(SecureMsg::Strgthlevel == LOW)
	{
		cout << "LOW " << endl;
	}
	else if (SecureMsg::Strgthlevel == NORM)
	{
		cout << "NORM " << endl;
	}
	else if (SecureMsg::Strgthlevel == MID)
	{
		cout << "MID " << endl;
	}
	else if (SecureMsg::Strgthlevel == HIGH)
		cout << "HIGH " << endl;
}//end show func


} /* namespace std */




