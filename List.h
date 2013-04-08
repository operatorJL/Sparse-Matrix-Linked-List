#include "Row.h"
#include <string>
#include <iostream>
using namespace std;

class List
{	
	public:
		
		Row *head;
		Row *newRow;
		node *newNode;
		Row *currentRow;
		node *currentNode;
		node *cHead;
		int maxI;
		int maxJ;
		int i;
		int j;
		int rowcount;
		double tempVal;
		string input;
		
		List();
		List(node*,int,int);
		//~List();
		void readFile(char *);
		double searchA(int,int);
		double searchB(int,int);
		void printScreen();
		//void printFile(List&, char *);
		void multiply(List&, char*);
	


};