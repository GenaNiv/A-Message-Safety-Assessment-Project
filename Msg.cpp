/*
 * Msg.cpp
 *
 *  Created on: May 25, 2015
 *      Author: gena
 */

#include "Msg.h"
#include<cstring>
#include<iostream>
namespace std {

//initialize constructor
Msg::Msg(const string& message , double safatyfactor):bodyText(message), SafeFactor(safatyfactor) {}
//destructor
Msg::~Msg() { /*cout << " \nBase class destrucotr called..." << endl;*/}
//setters
void Msg::SetBodyText(string& Message){ bodyText = Message;}
void Msg::SetSafeFactor(double sfFactor){ SafeFactor = sfFactor;}
//getters
string& Msg::GetBodyText(void){ return bodyText;}
double Msg::GetSafeFactor(void){return SafeFactor;}

} /* namespace std */









