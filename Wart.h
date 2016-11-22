//Courtney Shearer
//Wart.h
#ifndef WART_H
#define WART_H
#include <string>
#include "Digraph.h"
using namespace std;

class Wart{

public:
	Wart(string a);
	void encode(int width);
	void decode(Digraph & D);
	string &getMessage();
	friend ostream &operator<<(ostream &out, const Wart &myWart);
private:
        string message;

};
#endif
