//Courtney Shearer
//Digraph.cpp
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include "Digraph.h"

Digraph::Digraph(){
        populateArray();
	basicArray();
}
Digraph::Digraph(string  textfile){
	string best = textArray(textfile);	
	cout<<"Most common was: "<< best;
}
double Digraph::getScore(char a,char b){
	string digraph = "  ";
	double score;
	populateArray();//make an array of digraph oombos, ie alpha array
	digraph.at(0) = a;//first letter
	digraph.at(1) = b;//second letter
	for(int i = 0;i<26;i++){//get score of digraph
                for(int j = 0; j<26 ; j++){
                        if(B[i][j] == digraph){//does a letter in the alpha array equal the digraph
				score = A[i][j];//get the score from the double array
			}
                }
	}
	return score;
}

double Digraph::getScore( string & str){
	double score;
	string digraph;
	for(unsigned int a = 0; a<str.length()-1; a++){
		if(((str.at(a) >= 'A' && str.at(a) <= 'Z') || (str.at(a) >= 'a' && str.at(a) <= 'z')) && ((str.at(a+1) >= 'A' && str.at(a+1) <= 'Z') || (str.at(a+1) >= 'a' && str.at(a+1) <= 'z'))){
			digraph = str.substr(a,2);//get a digraph from string
			digraph.at(0) = tolower(digraph.at(0));//make lower case
			digraph.at(1) = tolower(digraph.at(1));
			for(int i = 0;i<26;i++){//get score of digraph
                		for(int j = 0; j<26 ; j++){
                        		if(B[i][j] == digraph){
						score += A[i][j];//add digraph scores to score
					}
                		}
        		}
		}
	}
	return score;
}	

	 

	
string  Digraph:: textArray(string textfile){
	for(int a = 0;a<26;a++){//fill double array with zeros
        	for(int b = 0; b<26 ; b++){
			A[a][b] = 0;
		}
	}
	double num = 0;//to track number of pairs
	ifstream myfile;
	myfile.open(textfile);
	string word = "";
	char blank = ' ';
	string pair = "";//digraph
	populateArray();//alpha array of digraphs
	while(!myfile.eof()){
	      getline(myfile,word,blank);
	      if(word.length() != 0){//check for multiple blanks
		for( unsigned int i = 0;i<word.length()-1;i++){//fill double array with occurances of digraphs/pairs
			if(((word.at(i) >= 'A' && word.at(i) <= 'Z') || (word.at(i) >= 'a' && word.at(i) <= 'z')) && ((word.at(i+1) >= 'A' && word.at(i+1) <= 'Z') || (word.at(i+1) >= 'a' && word.at(i+1) <= 'z'))){

				pair = word.substr(i,2);//digraph is a pair
				pair.at(0) = tolower(pair.at(0));//lower case letter
				pair.at(1) = tolower(pair.at(1));
				for(int a = 0;a<26;a++){//find pair in alpha Array
					for(int b = 0; b<26 ; b++){
						if(B[a][b] == pair){
							A[a][b]++;
							num++;
						} 
					}
				}
			
			}
		}
	      }	
	}
	for(int a = 0;a<26;a++){//puts occurances of digraphs in proportion
                for(int b = 0; b<26 ; b++){
			A[a][b] = A[a][b]/num;                        
                }
        }
	double max = 0;//to track max double score
	int row;
	int column;
	for(int i = 0;i<26;i++){//get digraph with highest proportion
		for(int j=0;j<26;j++){
			if( A[i][j] > max){
				max = A[i][j];
				row = i;
				column = j;
			}
		}
	}	
	myfile.close();
	return B[row][column];

}	

void Digraph::populateArray(){//makes the array of all possible digraphs/pairs
        string pair = "  ";
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        for(int  i = 0; i< 26;i++){
                
                for(int j = 0; j< 26;j++){
                        pair.at(0) = alpha.at(i);
                        pair.at(1) =alpha.at(j);
                        B[i][j] = pair;
                        pair = "  ";    
                 }
        }
}
void Digraph::basicArray(){//makes a double array for the basic constructor
        for(int  i = 0; i< 26;i++){
                
               for(int j = 0; j< 26;j++){
                   if ( B[i][j] == "th"||B[i][j] ==  "he" ||B[i][j] ==  "in" ||B[i][j] ==  "er" || B[i][j] ==  "an" || B[i][j] ==  "re" ||B[i][j] ==  "nd" ||B[i][j] ==  "at" ||B[i][j] ==  "on" ||B[i][j] ==  "nt"){  
                                A[i][j] = .1;
                        }
                        else{
                                A[i][j] = 0.0;
                        }

                 }

        }

}
