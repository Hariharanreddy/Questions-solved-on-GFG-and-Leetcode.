//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        string ans;
        stack<char> st;
        int size = s.size();
        
        for(int i=0 ;i<size ; i++){
            while(s[i] != '.' && i < size){
                st.push(s[i]);
                i++;
            }
            
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            
            while(s[i] == '.' && i < size){
                ans.push_back('.');
                i++;
            }
            
            i--;
        }
        
        // ans.pop_back();
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends