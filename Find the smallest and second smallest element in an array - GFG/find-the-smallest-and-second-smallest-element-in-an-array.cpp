//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> minAnd2ndMin(int a[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        vector<int> ans = minAnd2ndMin(a, n);
        if (ans[0] == -1)
            cout << -1 << endl;
        else 
            cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
// } Driver Code Ends


vector<int> minAnd2ndMin(int a[], int n) {
    vector<int> v;
    int smallest = a[0];
    int second_smallest = INT_MAX;
    
    for(int i= 1 ; i<n ; i++){
        
        if(a[i] < smallest){
            second_smallest = smallest;
            smallest = a[i];
            continue;
        }
        
        if(a[i] > smallest && second_smallest == INT_MAX){
            second_smallest = a[i];
            continue;
        }
        
        if(a[i] < second_smallest && a[i] > smallest){
            second_smallest = a[i];
            continue;
        }
    }
    
    if(second_smallest == INT_MAX){
        v.push_back(-1);
        v.push_back(-1);
    }
    else{
        v.push_back(smallest);
        v.push_back(second_smallest);
    }
    
    return v;
}