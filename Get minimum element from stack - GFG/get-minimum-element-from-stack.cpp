// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int mini;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           if(s.empty())
           {
               return -1;
           }
           else
           {
               return mini;
           }
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //underflow
           if(s.empty())
           {
               return -1;
           }
           else
           {
               int curr = s.top();
               s.pop();
               
               if(curr < mini)
               {
                   int stack_element = mini;
                   int prevMin = 2*mini - curr;
                   mini = prevMin;
                   
                   return stack_element;
                   
               }
               else
               {
                   return curr;
               }
               
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //For 1st elements
           if(s.empty())
           {
               s.push(x);
               mini = x;
           }
           else
           {
               if(x < mini)
               {
                   //moddify the x and push it
                   int modified = 2*x - mini;
                   s.push(modified);
                   
                   //update mini
                   mini = x;
               }
               else
               {
                   s.push(x);
               }
           }
       }
};

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends