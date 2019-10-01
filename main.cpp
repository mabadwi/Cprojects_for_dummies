#include<string.h>  
#include<iostream> 
using namespace std;
int distinctMoves(string s, int n, int x, int y) {
    int goal = 0;
    int ref = 0;
    int N = s.length();
    for(int i=0; i<N;i++)
    	{
    	for(int j = i;j<N-1;j++)
            {
                if(s[j]=='r')
                    ref++;
                else
                    ref--;
                //cout<<s[j]<< "\t"<<ref  <<endl; 
                if (ref == (y-x)){
                    goal++;
                }
            }
            //rotate
            char temp = s[i];
		 	for(int k = 1; k<N;k++){
		 		s[k-1]= s[k];
			 }
			 s[N-1] = temp;
			 cout<< "became  "<<s<< endl;
		}
        
    return goal;
}
int main()
{
    string str1 = "rrlrlr";
    int n1 = 6;
    int x1 = 1;
    int y1 = 2;
    int stp1 = distinctMoves(str1,n1,x1,y1);
    std::cout<<stp1 << " expected  = " << "7" << std::endl;
    
    string str2 = "rrlrlr";
    int n2 = 6;
    int x2 = 1;
    int y2 = 3;
    int stp2 = distinctMoves(str2,n2,x2,y2);
    std::cout<<stp2 << " expected  = " << "5" << std::endl;
    
    string str3 = "rrrlrr";
    int n3 = 7;
    int x3 = 0;
    int y3 = 0;
    int stp3 = distinctMoves(str3,n3,x3,y3);
    std::cout<<stp3 << " expected  = " << "2" << std::endl;
    return 0;
}

