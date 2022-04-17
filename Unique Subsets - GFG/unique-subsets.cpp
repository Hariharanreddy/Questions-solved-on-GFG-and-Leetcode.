// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    
    void findSubsets(vector<int> &arr, int n, int i, set<vector<int>> &tempAns, vector<int> &ds)
        {
            if(i >= n)
            {
                tempAns.insert(ds);
                return;
            }
            
            //include
            ds.push_back(arr[i]);
            findSubsets(arr, n, i+1, tempAns, ds);
            
            //exclude
            ds.pop_back();
            findSubsets(arr, n, i+1, tempAns, ds);
            
        }
    
    
    
    vector<vector<int>> AllSubsets(vector<int> &arr, int n)
    {
        sort(arr.begin(), arr.end());
        
        int index = 0;
        set<vector<int>> temp_ans;
        vector<vector<int>> ans;
        vector<int> ds;
        
        findSubsets(arr, n, index, temp_ans, ds);
        
        for(auto i : temp_ans)
        {
            ans.push_back(i);
        }
        // sort(ans.begin(), ans.end());
        
        
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
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
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
}   


  // } Driver Code Ends