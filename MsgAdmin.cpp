/*
 * MsgAdmin.cpp
 *
 *  Created on: May 26, 2015
 *      Author: gena
 */

#include "MsgAdmin.h"
#include<cstdlib>
#include<iostream>
namespace std {

MsgAdmin* MsgAdmin::m_pInstance = NULL;//initialize static pointer (singleton implementation)
int MsgAdmin::NoMsg = 0;			//initialize static variable for counting the amount of messages

MsgAdmin::MsgAdmin():PtrNode(NULL){}//constructor

MsgAdmin::~MsgAdmin()//destructor
{
	cout << "\nAllocated memory has been released. " << endl;
	delete m_pInstance;//deletes singleton object
	m_pInstance = NULL;
}//end destructor
// function instances a singleton object
MsgAdmin* MsgAdmin::Instance()
{
	if(!m_pInstance)
	{
		m_pInstance = new MsgAdmin;
	}
	return m_pInstance;
}//end instance function
//function checks if stack is empty
bool MsgAdmin::IsEmpty() const
{
	if(PtrNode == NULL)
		return true;
	else
		return false;
}//end IsEmpty
//function checks if stack is full. Since a LL stack never will be full (depend heap memory) return  always will be false
bool MsgAdmin::IsFull() const {return false;}
//function initializes stack, (sets to zero state)
void MsgAdmin::InitStack()
{
	Node* tmp = PtrNode;

	if(IsEmpty()){cout << "\nMessage box is empty" << endl;return;}
	else
		{
			while(PtrNode!= NULL)
			{
				PtrNode = PtrNode->link;
				delete tmp->Massage;
				delete tmp;
				tmp = PtrNode;
			}
			cout << "\nMessage box has been deleted..." << endl;
		}
}
//functions inserts a new element to the stack
void MsgAdmin::Push(Msg* msgg)
{
	Node* newNode;
	newNode = new Node;//allocates memory to the new node
	if(!newNode)exit(0);
	newNode->Massage = msgg;
	newNode->link = NULL;

	newNode->link = PtrNode;
	PtrNode = newNode;
	cout << "\nMessage box was updated with a new message... ";
	cout << "Overall messages in the box ... " <<IncrmentNoMsg() << endl;
}//end Push function
//function Pop deletes massage
void MsgAdmin::Pop()
{
	if(IsEmpty()){cout << "\nMessage box is empty" << endl;}
	else
	{
		Node* tmp = PtrNode;
		PtrNode = PtrNode->link;
		delete tmp;

		cout << "\nThe item was deleted from stack ";
	}
}//end Pop function
//function showMessage displays message's content
void MsgAdmin::showMessage(void)
{
	cout << "\n*****Classified messages following security level*****" << endl;
	Node* tmp;
	tmp = PtrNode;
	while(tmp!=NULL)
	{
		tmp->Massage->show();
		tmp = tmp->link;
	}

}//end showessage function
//function finds safest of all messages
void MsgAdmin::findSafest()
{
	Node* tmp;
	Node* biggest = NULL;
	double test=0.0;

	tmp = PtrNode;
	while(tmp!=NULL)
	{
		if(tmp->Massage->GetSafeFactor() > test)
		{
			test = tmp->Massage->GetSafeFactor() ;
			biggest = tmp;
		}
		tmp = tmp->link;
	}
	cout << "\n*******Safest of all messages*********";
	biggest->Massage->show();
}//end findSafe function

int MsgAdmin::IncrmentNoMsg()
{
	NoMsg++;
	return NoMsg;
}

void MsgAdmin::Destroy(void)
{
	delete m_pInstance;
	m_pInstance = NULL;
}

} /* namespace std */



