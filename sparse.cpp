//Joel Loucks
//1033681
#include <iostream>
#include <fstream>
#include <string>
#include "clp.h"
#include "MatrixArray.h"
#include "List.h"
using namespace std; 


int main(int argc,char** argv)
{
	CommandLineParser clp(argv[1],';');  
	
	char *v1 = clp.extract("A");
	char *v2 = clp.extract("B");
	char *v3 = clp.extract("result");
	char *v4 = clp.extract("storage");
	

	if(v1 == NULL ) {
		cout<<"There is no file1 name!\n";
	}
	if(v2 ==NULL){
		cout<<"There is no file2 name!\n";
	}
	if(v3 == NULL){
		cout<<"There is no file3 name!\n";
	}

	if(*v4=='a' || v4==NULL)
	{
		MatrixArray A,B,C;
		
		A.readFile(v1);
		B.readFile(v2);
		
		C= A.operator*(B);
	
		C.printMatrix(v3);
	
	}
	else
	{
		List A, B, C;
	
		A.readFile(v1);
		B.readFile(v2);
		
		A.multiply(B,v3);
		
		//C.printFile(C,v4);
	
	}
	
	
	
	cout<<"\n*Thank you for using the sparse matrix multiplier!*\n";

	return 0;
}



