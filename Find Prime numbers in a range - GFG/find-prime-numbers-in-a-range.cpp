//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool isPrime(int n)
    {
    
        // Check if n=1 or n=0
        if (n <= 1)
        {
            return false;    
        }
        // Check if n=2 or n=3
        if (n == 2 || n == 3){
            return true;
        }
            
        // Check whether n is divisible by 2 or 3
        if (n % 2 == 0 || n % 3 == 0){
            return false;
        }
            
        // Check from 5 to square root of n
        // Iterate i by (i+6) - Every number can be represented by  6n+1 or 6n-1
        for (int i = 5; i <= sqrt(n); i = i + 6){
            if (n % i == 0 || n % (i + 2) == 0)
            {
                return false;
            }
        }
            
     
        return true;
    }   
  
    vector<int> primeRange(int M, int N) {
        
        vector<int> a;
        
        for(int i = M ; i <= N ; i++){
            if(isPrime(i)){
                a.push_back(i);
            }
        }
        
        return a;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends