//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    void findSubsequence(int i, string &ans, string &s, set<string> &st, int n){
        
     if(i >= n){
         if(ans.size() > 1){
             if(ans[0] == 'a' || ans[0] == 'e' || ans[0] == 'i' || ans[0] == 'o' || ans[0] == 'u'){
             
             int l = ans.size() - 1;
             
             if(ans[l] != 'a' && ans[l] != 'e' && ans[l] != 'i' && ans[l] != 'o' && ans[l] != 'u'){
                 st.insert(ans);
             }
         }
        }
         
         return;
     }   
     
        //add
         ans.push_back(s[i]);
         findSubsequence(i+1, ans, s, st, n);
         
         //remove
         ans.pop_back();
         findSubsequence(i+1, ans, s, st, n);
        
    }
  
    set<string> allPossibleSubsequences(string S) {
        
        set<string> st;
        string ans;
        int n = S.size();
        
        findSubsequence(0, ans, S, st, n);
        
        return st;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends