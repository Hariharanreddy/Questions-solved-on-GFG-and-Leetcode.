//{ Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


// } Driver Code Ends

#include<vector>
#include<math.h>

class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
    	int s = str.size();
    	int sum = 0;
    	
    	for(int i=s-1 ; i>=0 ; i--){
    	   
    	    int temp = 0;
    	    int j = 0;
    	    
    	    while((str[i]-'0' >= 0 && str[i]-'0' <= 9) && i>=0){
    
    	       
    	       temp = temp + (str[i]-'0') * pow(10, j);

    	        j++;
    	        i--;
    	        
    	    }
    	    
    	   // cout<<temp<<endl;
    	    sum = temp+sum;
    	}
    	
    	return sum;
    	
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}

// } Driver Code Ends