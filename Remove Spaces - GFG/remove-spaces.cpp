// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string modify (string s)
    {
        //code here.
        int len = s.size();
        int ptr = 0;
        int count_space = 0;
        for(int i = 0; i<len ; i++)
        {
            if(s[i] == ' ')
            {
                count_space++;
                continue;
            }
            else
            {
                s[ptr] = s[i];
                ptr++;
            }
        }
        
        for(int i = 0 ; i<count_space ; i++)
        {
            s.pop_back();
        }
        
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore ();
    while (t--)
    {
        string s;
        getline (cin, s);
        Solution ob;
        cout <<ob.modify (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends