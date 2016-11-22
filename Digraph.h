
//Courtney Shearer
//Digraph.h
#ifndef DIGRAPH_H
#define DIGRAPH_H
#include<string>
#include<iostream>
using namespace std;

class Digraph{

	private:
		double  A[26][26];
		string B[26][26];
		void populateArray();
		void basicArray();
		string textArray(string textfile);
	public:
		Digraph();
		Digraph(string  textfile);
		double getScore(char a,char b);
		double getScore(string & str);
 
		
};
#endif
