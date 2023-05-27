//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

string reverseWord(string str){
    
  stack<int> st;
  
  for(int i=0 ;i<str.length() ; i++){
    st.push(str[i]);    
  }
  
  string rev;
  
  while(!st.empty()){
      rev.push_back(st.top());
      st.pop();
  }
  
  return rev;
  
}



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends