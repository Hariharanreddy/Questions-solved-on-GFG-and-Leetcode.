//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        
        if(N == 1){
            return 0;
        }
        
        long long sum = 0;
        for(long long i=1 ; i*i <= N ; i++){
            if(N%i == 0){
                
                if(i*i == N || i == 1){
                    //coz we want to add them only once
                    sum = sum + i;
                }
                else{
                    sum = sum + i + N/i;
                }
                
                if(sum > N){
                    return 0;
                }
                
            }
        }
        
        if(sum == N){
            return 1;
        }
        else{
            return 0;
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends