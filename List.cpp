#include "List.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
 
ifstream fin;
ofstream out;
 
		
List::List()
{
		head=NULL;
		currentRow=NULL;
		currentNode = NULL;
		maxI=1;
		maxJ=1;
		i=1;
		j=1;
		rowcount=1;
		tempVal=0;
		input=" ";

}

List::List(node *prodHead, int newMaxI, int newMaxJ)
{
	cHead=prodHead;
	maxI=newMaxI;
	maxJ=newMaxJ;

}
void List::readFile(char* file)
{
	fin.open(file);
	
	
	while(!fin.eof())
	{
		int line=0;
		line++;
		
	
		getline(fin, input);
		
		if(input=="")
			continue;
		
		if(input[0]=='#')
			continue;
			
		istringstream parse(input);
		
		
		
		if(!(parse>> i >> j >> tempVal))
		{
			cout<<"Line "<<line<<" input error\n";
			continue;
		}
		
		parse>> i >> j >> tempVal;
		
		if(i<=0)
		{
			cout<<"Line "<<line<<" negative i entry\n";
			continue;
		
		}
		
		if(j<=0)
		{
			cout<<"Line "<<line<<" negative j entry\n";
			continue;
		
		}
	
			
		if(j>maxJ)
			maxJ=j;
			
		
		if(currentRow==NULL || i>maxI)
		{
			maxI=i;
			rowcount++;
			
			newRow = new Row(i,j,tempVal);
			
			newRow->addNode();
			
			if(head==NULL)
			{
				
				head=newRow;
				
				
				currentRow=newRow;
				
				currentNode=newRow->newEntry;
				
			}
			else
			{	
				currentRow->nextRow=newRow;
				
				currentRow=newRow;
				
				
				currentNode=newRow->newEntry;
			}
			
		}
		else
		{
		
			
			newNode = new node(i,j,tempVal);
			
			currentNode->nodeLink=newNode;
			
			currentNode=newNode;
		}
		
		
	
	
	
	
	}
	
	fin.close();
}

void List::printScreen()
{
	currentRow=head;
	currentNode=currentRow->headNode;
	
	while(currentRow!=NULL)
	{	
		currentNode=currentRow->headNode;
	
		while(currentNode!=NULL)
		{
			
			cout<<currentNode->iValue<<" "<<currentNode->jValue<<" "<<currentNode->value<<endl;
		
			currentNode=currentNode->nodeLink;
		}
		
		currentRow=currentRow->nextRow;
	}
 

}


double List::searchA(int i,int k)
{
	currentRow=head;
	currentNode=currentRow->headNode;
	
	
	while(currentRow!=NULL)
	{	
		currentNode=currentRow->headNode;

		while(currentNode!=NULL)
		{
			if((currentNode->iValue==i) && (currentNode->jValue==k))
			{	
				return currentNode->value;
			}
			currentNode=currentNode->nodeLink;
		}
	
		currentRow=currentRow->nextRow;
	
	}

	return 0.0;
}

double List::searchB(int k, int j)
{
	currentRow=head;
	currentNode=currentRow->headNode;
	
	
	while(currentRow!=NULL)
	{	
		currentNode=currentRow->headNode;

		while(currentNode!=NULL)
		{
			if((currentNode->iValue==k) && (currentNode->jValue==j))
			{	
				return currentNode->value;
			}
			currentNode=currentNode->nodeLink;
		}
	
		currentRow=currentRow->nextRow;
	
	}
	
	return 0.0;

}

/*void List::printFile(List &listC, char *file)
{
	out.open(file);
	
	currentNode=listC.cHead;
	
	while(currentNode!=NULL)
	{
		out<<currentNode->iValue<<" "<<currentNode->jValue<<" "<<currentNode->value<<endl;
		
		currentNode=currentNode->nodeLink;
	
	}
	
	
	out.close();
	
	
}	
*/
void List::multiply(List& listB, char *file)
{
	out.open(file);
	double aVal=0.0;
	double bVal=0.0;
	double tempval=0.0;
	
	out<<"#Result\n";
	out<<"#Matrix C\n";
	
	
	if(maxJ != listB.maxI)
		{
			cout<<"Invalid matrix dimensions\n";
			cout<<"cannot multiply matrices\n";
		}
	else
	{
		for (int i = 1 ; i <= maxI; i++)
		{	
			for (int j = 1;  j <= listB.maxJ; j++)
			{	
				
				for (int k = 1; k <= maxJ; k++)
				{	
					aVal=searchA(i,k);
					bVal=listB.searchB(k,j);
					
					tempval+=aVal*bVal;
					
				}
				
				if(tempval!=0)
				{
					out<<i<<" "<<j<<" "<<tempval<<endl;
					tempval=0;
				
				}
			}
		}
	
	}
	
	out.close();
}