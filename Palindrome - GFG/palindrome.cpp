//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    string x = to_string(n);
		    int s = 0;
		    int e = x.length()-1;
		    
		    while(s <= e){
		        if(x[s] != x[e]){
		            return "No";
		        }
		        s++;
		        e--;
		    }
		    
		    return "Yes";
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends