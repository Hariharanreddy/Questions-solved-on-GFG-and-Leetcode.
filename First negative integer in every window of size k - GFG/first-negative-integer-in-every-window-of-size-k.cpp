// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int n, long long int k) {
    
    queue<long long int> q;
    vector<long long int> vec;
    
    //process the first window
    for(int i = 0 ; i< k ; i++)
    {
        if(a[i] < 0)
        {
            q.push(i);
        }
    }
    
    //Push q.front into vector
    if(q.size() != 0)
    {
        vec.push_back(a[q.front()]);
    }
    else
    {
        vec.push_back(0);
    }
    
    //for remaining windows
    for(int i=k ; i<n ; i++)
    {
        //Pop the outside window index from queue
        if(!q.empty() && i - q.front() >= k)
        {
            q.pop();
        }
        
        //Adding window element
        if(a[i]<0)
        {
            q.push(i);
        }
        
        //Push q.front into vector
        if(q.size() != 0)
        {
            vec.push_back(a[q.front()]);
        }
        else
        {
            vec.push_back(0);
        }
    }
    
    return vec;
    
                                             
 }