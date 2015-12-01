/*
 * PlainMsg.h
 *
 *  Created on: May 25, 2015
 *      Author: gena
 */

#ifndef PLAINMSG_H_
#define PLAINMSG_H_
#include "Msg.h"
enum SecurLevel {A=1, B=2, C=3, D=4, E=5};
namespace std {
// PlainMsg class defines a structure of a simple un-encrypted plain message
class PlainMsg: public Msg {
public:
	PlainMsg(const string& msg, double sffactor, int msglenght, SecurLevel OwnClass);
	virtual ~PlainMsg();
	void SetMsgLen(int MSGlen);
	int GetMsgLen(void);
	void SetSecurerLevel(SecurLevel threatL);
	SecurLevel GetSecurerLevel(void);
	void updateSafeFactor();
	void show() const;

private:
	SecurLevel ownerClass;
	int msglen;
};//end class

} /* namespace std */

#endif /* PLAINMSG_H_ */







