// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> stk;
        
        for(int i = 0; i < x.length(); i++)
        {
            char ch = x[i];
            //If its an open bracket
            if(ch == '{' || ch == '[' || ch == '(')
            {
                stk.push(ch);
            }
            //closing bracket
            else
            {
                if(!stk.empty())
                {
                    char top = stk.top();
                    if( (ch == ')' && top == '(') || ( ch == '}' && top == '{') || (ch == ']' && top == '[') ) 
                     {
                         stk.pop();
                     }
                     else
                     {
                         return false;
                     }
                }
                else
                {
                    return false;
                }
            }
        }
        
        if(stk.empty())
        {
            return true;
        }
        else
        return false;
        
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends