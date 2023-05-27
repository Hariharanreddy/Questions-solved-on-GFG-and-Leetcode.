//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
// 	int check(string str, int s, int e){
	    
// 	    if(s > e){
// 	        return 1;
// 	    }
	    
// 	    if(str[s] != str[e]){
// 	        return 0;
// 	    }
	    
// 	    int res;
	    
// 	    res = check(str, ++s, --e);
	    
// 	    return res;
// 	}
	
	int isPalindrome(string S)
	{
	    int s = 0;
	    int size = S.length();
	    int e = S.length() - 1;
	   // int ans = check(S, s, e-1);
	   int ans = 1;
	   
	   for(int i = 0 ; i < size ; i++){
	       
	       if(S[s] != S[e]){
	           ans = 0;
	           break;
	       }
	       
	       s++;
	       e--;
	       
	   }
	    
	    return ans;
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends