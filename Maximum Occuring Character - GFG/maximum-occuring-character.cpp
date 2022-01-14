// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int len = str.size();
        
        int arr[256] = {0};
        int max = 0;
        char ans;
        
        for(int i = 0 ; i<len ; i++)
        {
            arr[str[i]]++;
        }
        
        for(int i = 255 ; i>=0 ; i--)
        {
            if (max <= arr[i]) {
            max = arr[i];
            ans = i;
        }
        }
        
        return ans;
        
        
    }

};

// { Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}  // } Driver Code Ends