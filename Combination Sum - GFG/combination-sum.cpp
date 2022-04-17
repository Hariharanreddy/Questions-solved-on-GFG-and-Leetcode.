// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    void func(int ind, int B, vector<int>& A, vector<int>& ds,const int &n, vector<vector<int>>& ans) {
        
        if(ind == n) 
        {
            if(B == 0) 
            {
                ans.push_back(ds);
            }
            return;
        }
        
        if(A[ind]<=B) {
            
            
            ds.push_back(A[ind]);
            func(ind, B-A[ind], A, ds, n, ans);
            ds.pop_back();
            
        }
        
        func(ind+1, B, A, ds, n, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int> &A, int B) {
        
        sort(A.begin(), A.end());
        
        vector<vector<int>> ans;
        vector<int> ds;
        
        A.erase(unique(A.begin(), A.end()), A.end());
        func(0, B, A, ds, A.size(), ans);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends