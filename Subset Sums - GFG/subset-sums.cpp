// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void findSums(vector<int> &arr, int N, vector<int> &ans, int sum, int i)
    {
        //base case
        if(i >= N)
        {
            ans.push_back(sum);
            return;
        }
        
        //include
        sum += arr[i];
        findSums(arr, N, ans, sum, i+1);
        
        //exclude
        sum-=arr[i];
        findSums(arr, N, ans, sum, i+1);
        
    }


    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        int sum = 0;
        int index = 0;
        
        findSums(arr, N, ans, sum, index);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends