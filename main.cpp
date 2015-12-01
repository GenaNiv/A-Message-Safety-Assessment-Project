/*
 * main.cpp
 *
 *  Created on: May 25, 2015
 *      Author: gena
 */
#include<iostream>
using namespace std;
#include "MsgAdmin.h"
#include "Msg.h"
#include "PlainMsg.h"
#include "SecureMsg.h"
#define Max_MSG_NUM 10
//Main Function
int main()
{
	Msg* m[Max_MSG_NUM];//array of pointers to Msg class representing the accepted messages

	//Message store box initialization
	m[0] = new SecureMsg("secure", 0.95, PWD, HIGH, 6);
	m[1] = new PlainMsg("plain", 0.727273, 11, B);
	m[2] = new SecureMsg("secure", 1.41, PKI, MID, 28);
	m[3] = new PlainMsg("plain", 2.11364, 22, D);
	m[4] = new SecureMsg("secure", 0.95, PWD, HIGH, 6);
	m[5] = new SecureMsg("secure", 0.727273, AES, NORM, 11);
	m[6] = new SecureMsg("secure", 1.41, PKI, MID, 28);
	m[7] = new PlainMsg("plain", 2.11364, 22, D);
	m[8] = new SecureMsg("secure", 0.95, PWD, HIGH, 6);
	m[9] = new PlainMsg("plain", 0.727273, 11, B);

	//Performs instance and operation on the message box
	for(int i = 0; i < Max_MSG_NUM; i++)
	{
		MsgAdmin::Instance()->Push(m[i]);
	}

	//Displaying content of the message box
	MsgAdmin::Instance()->showMessage();
	//Dinding most safest message
	MsgAdmin::Instance()->findSafest();
	//Delete message box
	MsgAdmin::Instance()->InitStack();


	return 0;
}// end Main func.



