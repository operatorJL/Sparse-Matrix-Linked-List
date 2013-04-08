/***********************************
matrix class 
************************************/
#include <iostream>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <string>
#include "MatrixArray.h"
using namespace std;

ifstream in;
ofstream fout;

/***********************************
	default constructor to initialize 
	matrix values
************************************/
MatrixArray::MatrixArray()
{
	//cout<<"in constructor\n";
	//for(int i=0; i<101; i++)
	//{
		//for(int j=0; i<101; j++)
			//matrix[i][j]=0.0;
//	}
	
	for(int i=0; i<101; i++)
	{
		for(int j=0; j<101; j++)
			matrix[i][j]=0.0;
	}
	
	maxI=1;
	maxJ=1;
	iValue=1;
	jValue=1;
	
}

/***********************************
	constructor that is called
	after overloaded operator 
************************************/
MatrixArray::MatrixArray(double newMatrix[][101], int newI, int newJ)
{
	maxI=newI;
	maxJ=newJ;
	for(int r=1; r<=newI; r++)
	{
		for(int c=1; c<=newJ; c++)
			matrix[r][c]=newMatrix[r][c];
	}
	
}

/***********************************
	takes the input file that was
	parsed from clp.cpp, opens it
	and does error checking on inputs 
	and assigns them in the matrix
************************************/
void MatrixArray::readFile(char *file)
{
	string input=" ";
	int linenum=0;
	int i=1;
	int j=1;
	double value=0.0;
	
	in.open(file);
	
	if(in.fail())
	{
		cout<<"could not open the file\n";
		cout<<"please retry with a new file\n";
	}
		
		
	while(!in.eof())
	{
			++linenum;
			
			
			
			getline(in,input);
			
		
			if(input[0]=='#')
				continue;
			else	
			{
				istringstream lineparse(input);
				
			
				if(!(lineparse>> i >> j >> value))
				{
					continue;
				}	
				lineparse>> i >> j >> value;
					
					
				if(i<0)
				{
					cout<<"line "<<linenum<< " has negative i entry \n";
					continue;
				}
				
				
				if(j<0)
				{
					cout<<"line "<<linenum<< " has negative j entry \n";
					continue;
				}
				
				
				
				
				if(maxI<=i)
					maxI=i;
					
				
				if(maxJ<=j)
					maxJ=j;
					
				
					
				matrix[i][j]=value;	
			}
	
	}
	
	in.close();
	
	
}

void MatrixArray::setValue(int i, int j, double value)
{
	matrix[i][j]=value;
}

double MatrixArray::getValue(int i, int j)
{

	return matrix[i][j];
	
}
void MatrixArray::setMaxI(int newMaxI)
{
	maxI=newMaxI;
}
int MatrixArray::getMaxI()
{
	return maxI;
}

void MatrixArray::setMaxJ(int newMaxJ)
{
	maxJ=newMaxJ;
}

int MatrixArray::getMaxJ()
{
	return maxJ;
}

void MatrixArray::setIvalue(int newIvalue)
{
	iValue=newIvalue;
}

int MatrixArray::getIvalue()
{
	return iValue;
}

void MatrixArray::setJvalue(int newJvalue)
{
	jValue=newJvalue;
}

int MatrixArray::getJvalue()
{
	return jValue;
}

/*************************************
	printing the result matrix in
	sparse list form.  finds a value
	in matrix < or > 0 and prints
	the i and j values then the value

*************************************/
void MatrixArray::printMatrix(char *file)
{	
	fout.open(file);
	
	fout<<"#Result\n";
	fout<<"#Matrix C\n";
	
	for(int i=1; i<=maxI; i++)
	{	
		for(int j=1; j<=maxJ; j++)
			{
				if((matrix[i][j]<0) || (matrix[i][j]>0))
					{
						fout<<i<<" "<<j<<" "<<matrix[i][j]<<endl;
					
					}
					
				
			}
	}		
	fout<<endl;	
	
	fout.close();
	
	
}
/*************************************
overloaded operator to do matrix
multiplication.  returns an anonymous
object 
**************************************/

const MatrixArray MatrixArray::operator *(const MatrixArray& matxB)
{
	double cMatrix[101][101]= {0.0};
	
	if(maxJ != matxB.maxI)
		{
			cout<<"Invalid matrix dimensions\n";
			cout<<"cannot multiply matrices\n";
		}
	else
	{
		for (int i = 1 ; i <= maxI; i++)
		{	
			for (int j = 1;  j <= matxB.maxJ; j++)
			{	
				for (int k = 1; k <= matxB.maxI; k++)
				{	
					cMatrix[i][j] += matrix[i][k] * matxB.matrix[k][j];
				}
			}
		}
	
	
		return MatrixArray(cMatrix, maxI, matxB.maxJ);
	
	}
	
	
}
/*******************************
	printing to the screen 
	for error checking

********************************/
void MatrixArray::printScreen()
{

for(int i=1; i<=maxI; i++)
	{	
		for(int j=1; j<=maxJ; j++)
			{
				if(matrix[i][j]<0 || matrix[i][j]>0)
					{
						cout<<i<<" "<<j<<" "<<matrix[i][j]<<endl;
					
					}
					
				
			}
	}	



}