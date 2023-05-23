//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
        int getCount (string S, int N)
        {
            char temp;
            unordered_map<char, int> ump;
            int size = S.size();
            
            for(int i = 0 ; i<size; i++){
                
                if(ump.find(S[i]) == ump.end()){
                    ump[S[i]]++;
                    temp = S[i];
                }
                else if(temp != S[i]){
                    ump[S[i]]++;
                    temp=S[i];
                }
            }
            
            int c = 0;
            
            for(auto it = ump.begin() ; it!=ump.end(); it++){
                if(it->second == N){
                    c++;
                    
                }
                // cout<<it->first<<" "<<it->second<<endl;
            }
            
            return c;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n; cin >> n;
        
        Solution ob;
        cout <<ob.getCount (s, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends