//Courtney Shearer
#include <iostream>
using namespace std;
#include "Wart.h"
#include "Digraph.h"

int main(){
Wart A("Orange rules");
Digraph C("kafka.txt");

A.encode(4);

cout<<"Enter file name for digraph:  "<< "kafka.txt"<<endl;
cout<< "(proportion of "<<C.getScore('h','e')<<")"<<endl;       
cout<<"Enter sentence terminated by <Enter> "<< A << endl;
cout<<"This gets a score of:  "<<C.getScore( A.getMessage())<<endl;

A.decode(C);
cout<<"The decoded sentence is:"<<endl;
cout<<A.getMessage()<<endl;

return 0;
}
