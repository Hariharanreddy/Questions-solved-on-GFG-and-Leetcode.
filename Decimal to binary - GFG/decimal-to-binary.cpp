//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

void toBinary(int N)
{
    // your code here
    int temp = N;
    int digit = 0;
    int bin = 0;
    int i = 0;
    
    while(temp != 0){
        digit = temp % 2;
        
        bin = (digit * pow(10, i)) + bin;
        
        temp = temp / 2;
        i++;
    }
    
    cout<<bin;
    
        
}

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
	cin>>t;
	
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    toBinary(n);
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends