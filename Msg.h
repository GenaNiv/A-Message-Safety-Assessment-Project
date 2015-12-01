/*
 * Msg.h
 *
 *  Created on: May 25, 2015
 *      Author: gena
 */

#ifndef MSG_H_
#define MSG_H_
#include<string>
namespace std {
// Msg class defines the base structure of text message
class Msg {
public:
	Msg(const string& , double);//constructor
	virtual ~Msg();				//destructor
	void SetBodyText(string& Message);
	string& GetBodyText(void);
	void SetSafeFactor(double sfFactor);
	double GetSafeFactor(void);
	//virtual functions have not implemented in Msg.cpp
	virtual void updateSafeFactor(){}
	virtual void show() const{}

protected: //Derived classes can use these variables
	string bodyText;
	double SafeFactor;
};//end class

} /* namespace std */

#endif /* MSG_H_ */















