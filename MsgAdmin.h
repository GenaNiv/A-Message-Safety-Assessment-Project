/*
 * MsgAdmin.h
 *
 *  Created on: May 26, 2015
 *      Author: gena
 */

#ifndef MSGADMIN_H_
#define MSGADMIN_H_
#include "Msg.h"
#include<string>
namespace std {


//Linked list data struct Node type
struct Node
{
	Msg* Massage;
	Node* link;
};//end struct

//Singleton class that manages a message box
class MsgAdmin {
public:
	static MsgAdmin* Instance();

	bool IsEmpty() const;
	bool IsFull() const;
	void InitStack();
	void Push(Msg* msgg);
	void Pop();
    void showMessage(void);
    void findSafest();
    Msg* findSafest(string Msgtype);
    int IncrmentNoMsg();
    virtual ~MsgAdmin();
    void Destroy(void);
private:
	MsgAdmin();
	MsgAdmin(MsgAdmin const&){}
	MsgAdmin& operator=(MsgAdmin const&){}
	static MsgAdmin* m_pInstance;
	Node* PtrNode;
	static int NoMsg;
protected:


};//end class

} /* namespace std */

#endif /* MSGADMIN_H_ */



