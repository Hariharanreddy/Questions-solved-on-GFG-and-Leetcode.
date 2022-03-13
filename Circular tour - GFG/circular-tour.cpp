// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int start = 0;
       int deficit = 0;
       int bal = 0;       //balance
       
       for(int i=0 ; i<n ; i++)
       {
           bal += p[i].petrol - p[i].distance;
           
           //if bal gets negative -> reset bal = 0, move start, add deficit
           if(bal < 0)
           {
               deficit += bal;
               bal = 0;
               start = i+1;
           }
       }
       
       if(deficit + bal >= 0)
       {
           return start;
       }
       else
       return -1;
       
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends