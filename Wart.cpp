//Courtney Shearer
//Wart.cpp
#include<iostream>
#include<string>
using namespace std;
#include "Wart.h"
#include "Digraph.h"

Wart:: Wart(string a):  message(a)
{
}

void Wart:: encode(int width){
	string blank = " ";
	string period = ".";
	int index;
	string encode;//encoded message
	if(message.length() % width != 0){
		message.append(period);
		index = message.length() - 1;
	}
	while(message.length() % width != 0){
		message.insert(index,blank);
	}
//Have appropriate message
	int r = (message.length() / width);//rows
	int c = width;//columns
	char M[r][c];//to store original message letters
	int i = 0;//index of message
	for(int a = 0; a < r;a++){//fill the array
		for(int b = 0; b<c;b++){
			char letter = message.at(i);
			//cout<<letter;
			M[a][b] = letter;
			i++;
		}
	}
	for(int a = 0; a<c;a++){
		for(int b =0; b<r;b++){
			encode += M[b][a];

		}
	}
	message = encode;
}

void Wart::decode(Digraph & D){
	int length = message.length();//store original length
	int m  = message.length();
	double  maxscore = 0.0;
	double  score;
	string maxmess;//the message with the highest score
	string decode;
	for(int i = m; i > 0;i--){
		decode ="";
		if(length % i  == 0){
			int r = length / i;
			int c = i;
			int index = 0;
			string W[r][c];//new matrix
			for(int a = 0; a<r;a++){//put message in new matrix
        			for(int b =0; b<c;b++){
					W[a][b] = message.substr(index,1);
					string letter = W[a][b];
					index++; 
        			}
			}
			for(int a = 0; a<c;a++){//get decoded message, read matrix in specific way
                        	for(int b =0; b<r;b++){
					string letter = W[b][a];
                                	decode+=letter;
                        	}
                	}
			score = D.getScore(decode);
			if(score > maxscore){
				maxscore = score;
				maxmess = decode;
			}
		}
		
	}
	message = maxmess;
}


string& Wart::getMessage(){
	return message;
}
 
ostream &operator<<(ostream &out, const Wart &myWart){
out<<myWart.message;
return out;
}
