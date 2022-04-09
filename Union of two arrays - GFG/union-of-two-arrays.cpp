// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int arr[], int n, int b[], int m)  {
        
        unordered_map<int, bool> visited;
        int count = 0;
        
        for(int i=0; i<n ;i++)
        {
            if(visited[arr[i]] != true)
            {
                visited[arr[i]] = true;
                count++;
            }
        }
        
        for(int i=0; i<m ;i++)
        {
            if(visited[b[i]] != true)
            {
                visited[b[i]] = true;
                count++;
            }
        }
        
        return count;
        
        
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends