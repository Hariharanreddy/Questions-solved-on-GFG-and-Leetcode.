// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    //odd condn
    if(s.length()%2 == 1)
    {
        return -1;
    }
    
    
    stack<char> st;
    
    for(int i=0 ; i<s.length() ; i++)
    {
        char ch = s[i];
        
        if(ch == '{')
        {
            st.push(ch);
        }
        else
        {
            //ch is closed bracket
            //pop if stack top is {, else push it
            if(!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }
    
    
    //stack contains invalid expression
        int a = 0, b = 0;
        while(!st.empty())
        {
            if(st.top() == '{')
            {
                st.pop();
                a++;
            }
            else
            {
                st.pop();
                b++;
            }
        }
        
        int ans = (a+1)/2 + (b+1)/2;
        
        return ans;
}