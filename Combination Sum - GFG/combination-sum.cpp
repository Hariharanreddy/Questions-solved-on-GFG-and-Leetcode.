// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
    void solve(vector<int> &arr, int sum, vector<int> &output,
                vector<vector<int>> &ans, int i, int size){
                    
        //base case
        if(sum < 0)
        {
            return;
        }
        
        if(i == size)
        {
            if(sum == 0)
            {
                ans.push_back(output);
            }
            return;
        }
        
        //include 
        //dont change index
        
            output.push_back(arr[i]);
            solve(arr, sum-arr[i], output, ans, i, size);
            output.pop_back();
        
        
        //exclude
        solve(arr, sum, output, ans, i+1, size);
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int> &A, int sum) {
        
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        
        sort(A.begin(), A.end());
        A.erase(unique( A.begin(), A.end()), A.end());
        
        solve(A, sum, output, ans, index, A.size());
        
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