// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        
        
        if(arr.size() == 1)
        {
            return arr;
        }
        
        //Step1 - search for arr[i] < arr[i+1] from back
        int index1;
        for(int i=n-2 ; i>=0 ; i--)
        {
            if(arr[i] < arr[i+1])
            {
                index1 = i;
                break;
            }
        }
        
        //Step2 - search for greater element than it from back
        if(index1 < 0)
        {
            //last permutation was there so reverse the array
            reverse(arr.begin(), arr.end());
            return arr;
        }
        else
        {
            
            for(int i = n-1 ; i>=0 ; i--)
            {
                if(arr[i] > arr[index1])
                {
                    int index2 = i;
                    swap(arr[index2], arr[index1]);
                    
                    //reverse from further index
                    reverse(arr.begin()+index1+1 , arr.end());
                    return arr;
                }
            }
        }
    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends