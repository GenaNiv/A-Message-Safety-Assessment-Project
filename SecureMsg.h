/*
 * SecureMsg.h
 *
 *  Created on: May 25, 2015
 *      Author: gena
 */

#ifndef SECUREMSG_H_
#define SECUREMSG_H_
enum securityType {PWD=1, AES=2, PKI=3, SSL=4};
enum keyStrength {LOW=1, NORM=2, MID=3, HIGH=4};
#include "Msg.h"
namespace std {
// SecureMsg class defines a structure of a secure messages
class SecureMsg: public Msg {
public:
	SecureMsg(const string& msg, double sffactor, securityType ST, keyStrength KS, int meslength);
	virtual ~SecureMsg();
	//setters
	void SetMsgLength(int L){ msglength = L;}
	void SetSecType(securityType SecT);
	void SetStrgthlevel(keyStrength KeyStr);
	//getters
	int GetMsgLength(void){ return msglength; }
	securityType GetSecType(void);
	keyStrength GetStrgthlevel(void);

	void show() const;
	void updateSafeFactor();
private:
	securityType SecType;
	keyStrength Strgthlevel;
	int msglength;
};

} /* namespace std */

#endif /* SECUREMSG_H_ */








