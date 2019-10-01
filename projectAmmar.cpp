/**********
*********/

#include <iostream>
#include <string>
#include <string.h>
#include<cstdlib>
#include<sstream>
#include <stdlib.h>

#define delimiter ' '
using namespace std;

double **AllocateMatrix (string mat);
void DeallocateMatrix (double **a, string mat);
void addMatrix( double **a, double **b,int c,int r);
void subsMatrix(double **a,double **b,int c,int r);
void mutipMatrix( double **a, double **b,int c,int r);
main ()
{
  string mat1, mat2;
  char opr;
  int c=0,r=1,l=0;
  
  std::cout << "Enter First Matrix" << std::endl;
  std::getline(std::cin, mat1);

// Calculating rows and columns
l = mat1.length();
  for (int i = 1; i < l - 1; i++)
    {
      if (mat1[i] == ';')
	{
	  r++;
	  
    }
      else if (mat1[i] == delimiter)
	c++;
    }
    
  c = c / r;
  c++;

  double **a = AllocateMatrix (mat1);
 
  std::cout << "Enter operator" << std::endl;
  
  cin >> opr;
  cin.sync();
  switch (opr)
    {
    case '+':
      {std::cout << "Enter Matrix to add" << std::endl;
      
      std::getline(std::cin, mat2);
      double **b = AllocateMatrix (mat2);
      addMatrix(a,b,c,r);
      break;}
    case '-':
      {std::cout << "Enter Matrix to substruct" << std::endl;
      std::getline(std::cin, mat2);
      double **b = AllocateMatrix (mat2);
      subsMatrix(a,b,c,r);
      break;}
    case 'x':
      {std::cout << "Enter Matrix to Cross Product" << std::endl;
      std::getline(std::cin, mat2);
      double **b = AllocateMatrix (mat2);
      if(c!=r){
      	cout<<"the matrix should be squered"<< std::endl;
      	break;
	  }
      mutipMatrix(a,b,c,r);
      break;}
    default:
      std::cout << "Undefined operator" << std::endl;
      break;


    }
    DeallocateMatrix (a, mat1);

}



double ** AllocateMatrix (string mat)
{
   
  int r = 1, c = 0, l = 0, pos = 0;	// r=num rows, c=num cols
  l = mat.length();
   
  // Calculating rows and columns
  for (int i = 1; i < l - 1; i++)
    {
      if (mat[i] == ';')
	{
	  r++;
	  mat[i] = delimiter;
	}
      else if (mat[i] == delimiter)
	c++;
    }
    
  mat[l - 1] = ' ';
  c = c / r;
  c++;
 
  mat.erase (0, 1);

  // allocating 2D array   
  double **a = new double *[r];
  for (int i = 0; i < r; i++)
    a[i] = new double[c];

  // populating the mtrix
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      {
	pos = mat.find (delimiter);

	 a[i][j] =atof( mat.substr (0, pos).c_str());
	mat.erase (0, pos + 1);
      };

  
  return a;
}

void DeallocateMatrix (double **a, string mat)	// r=num rows
{
  int r = 1, l = 0;
  l = mat.length ();
  // Calculating rows 
  for (int i = 1; i < l - 1; i++)
    {
      if (mat[i] == ';')
	r++;

    }

  for (int i = 0; i < r; i++)
    delete[]a[i];
  delete[]a;
}

void addMatrix( double **a, double **b,int c,int r)
{
    std::cout << "The Result is: \n [" ;
    for (int i = 0; i < r; i++)
    {
        //std::cout << "" << std::endl;
    for (int j = 0; j < c; j++)
      {
          cout <<a[i][j]+b[i][j] << " ";
		   
      }
       
        if (i!=r-1)
         cout<<";";
        
    }
    std::cout << "]" << std::endl;
}


void subsMatrix( double **a, double **b,int c,int r)
{
    std::cout << "The Result is: \n [" ;
    for (int i = 0; i < r; i++)
    {
        //std::cout << "" << std::endl;
    for (int j = 0; j < c; j++)
      {
          cout <<a[i][j]-b[i][j] << " ";
		   
      }
       
        if (i!=r-1)
         cout<<";";
        
    }
    std::cout << "]" << std::endl;
}

void mutipMatrix( double **a, double **b,int c,int r)
{
    int product[100][100];
	std::cout << "The Result is: \n [" ;
    for(int i=0; i<r; ++i)
         for(int j=0; j<c; ++j) {
            product[i][j] = 0;
         }
	for(int i=0; i<r; ++i)
	 for(int j=0; j<c; ++j)
	    for(int k=0; k<r; ++k) {
	       product[i][j]+=a[i][k]*b[k][j];
	    }
    for (int i = 0; i < r; i++)
    {
        
    for (int j = 0; j < c; j++)
      {
          cout <<product[i][j] << " ";
		   
      }
       
        if (i!=r-1)
         cout<<";";
        
    }
    std::cout << "]" << std::endl;
}
