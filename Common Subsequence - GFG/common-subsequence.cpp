//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	bool commonSubseq (string a, string b)
	{
	    unordered_map<char, int> mp;
	    int size_a = a.length();
	    int size_b = b.length();
	    
	    for(int i=0 ; i < size_a ; i++){
	        mp[a[i]]++;
	    }
	    
	    for(int i=0 ; i < size_b ; i++){
	        if(mp.find(b[i]) != mp.end()){
	            return true;
	        }
	    }
	    
	    return false;
	    
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--) 
	{
		string a, b; cin >> a >> b;
		Solution ob;
		cout << ob.commonSubseq (a, b) << '\n';
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends