//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
        
        int s = 0; 
        int e = k-1;
        bool flag = false;
        int len = arr.size();
        
        for( ; e < len && k < len ; s=s+k, e=e+k){
            
            int temp_s = s;
            int temp_e = e;
            
            while(temp_s < temp_e){
                swap(arr[temp_s++], arr[temp_e--]);
            }
            
            if(e+k >= len){
                flag = true;
                s = s+k;
                break;
            }
        }
        
        if(k >= len){
            s = 0;
            e = len-1;
            while(s < e){
                swap(arr[s++], arr[e--]);
            }
        }
        
        if(flag){
            int e = len-1;
            while(s < e){
                swap(arr[s++], arr[e--]);
            }
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends