// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   
   bool isPalindrome(string s, int start, int end)
   {
       while(start < end)
       {
           if(s[start] != s[end])
           {
               return false;
           }
           
           start++;
           end--;
       }
       
       return true;
       
   }
   
   
   
   
   void doPartition(int ind, string s, vector<vector<string>> &ans,
                    vector<string> &output)
    {
        //base case
        if(ind >= s.size())
        {
            ans.push_back(output);
            return;
        }
        
        for(int i=ind ; i<s.size() ; i++)
        {
            if(isPalindrome(s, ind, i))
            {
                //push the left partition
                output.push_back(s.substr(ind, i-ind+1));
                
                //recursive call from i+1
                doPartition(i+1, s, ans, output);
                
                //backtrack
                output.pop_back();
            }
        }
    }
  
  
  
  
  
    vector<vector<string>> allPalindromicPerms(string s) {
        
        vector<vector<string>> ans;
        vector<string> output;
        
        doPartition(0, s, ans, output);
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends