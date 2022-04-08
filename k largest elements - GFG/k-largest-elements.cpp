// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    
	    priority_queue<int, vector<int>, greater<int>> pq;
	    vector<int> vec;
	    
	    //step1 - Store first k elements
	    for(int i = 0 ; i<k ; i++)
	    {
	        pq.push(arr[i]);
	    }
	    
	    //step2 - pop if pq.top is smaller than other elements
	    for(int i = k ; i<n ; i++)
	    {
	        if(pq.top() < arr[i])
	        {
	            pq.pop();
	            pq.push(arr[i]);
	        }
	    }
	    
	    //step3 -store all elements of pq in vector
	    while(!pq.empty())
	    {
	        vec.push_back(pq.top());
	        pq.pop();
	    }
	    
	    //step 4 - sort vec in descending order
	    sort(vec.begin(), vec.end(), greater<int>());
	        
	    
	    return vec;
	    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends