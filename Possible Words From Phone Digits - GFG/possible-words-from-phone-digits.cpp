// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    void solve(int a[], int N, vector<string> &ans, string map[] ,string str, int index)
    {
        //base case
        if(index > N-1)
        {
            ans.push_back(str);
            return;
        }
        
        //storing the characters of that number
        int num = a[index];
        string value = map[num];
        
        for(int i = 0 ; i < value.length() ; i++)
        {
            str.push_back(value[i]);
            solve(a, N, ans, map, str, index+1);
            str.pop_back();                           //backtracking
            
        }
        
    }

    
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> ans;
        
        // if(N == 1)
        // {
        //     return ans
        // }
        
        
        string map[10] = {"", "", "abc","def", "ghi", "jkl", "mno","pqrs", "tuv", "wxyz"};
        
        
        
        string str = "";
        
        int index = 0;
        
        solve(a, N, ans, map, str, index);
        
        return ans;

    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends