// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long> prevSmallerElement(long long arr[], int n)
    {
        stack<long long> s;            //for indexes
        s.push(-1);             
        
        vector<long long> ans(n);
        
        for(int i=0;i<n;i++)
        {
            long long curr = arr[i];
            
            while(s.top() != -1 && arr[s.top()] >= curr)      //arr[s.top()] is the element on stack
            {
                s.pop();
            }
            
            ans[i] = s.top();      //store the prevsmallerelement index
            s.push(i);             //pushing the index
                
        }
        
        return ans;
        
        
    }
    
    vector<long long> nextSmallerElement(long long arr[], int n)
    {
        stack<long long> s;
        s.push(-1);                 //for indexes
        
        vector<long long> ans(n);
        
        for(int i=n-1; i>=0 ;i--)
        {
            long long curr = arr[i];
            
            while(s.top() != -1 && arr[s.top()] >= curr)      //arr[s.top()] is the element on stack
            {
                s.pop();
            }
            
            ans[i] = s.top();      //store the nextsmallerelement index
            s.push(i);             //pushing the index
            
        }
        
        return ans;

    }
    
    
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> next;
        next = nextSmallerElement(arr, n);
        
        vector<long long> prev;
        prev = prevSmallerElement(arr, n);
        
        long long area = INT_MIN;
        for(int i=0;i<n;i++)
        {
            long long l = arr[i];
            
            if(next[i] == -1)
            {
                next[i] = n;
            }
            
            long long b = next[i] - prev[i] - 1;
            
            area = max(area, l*b);
        }
        
        return area;
        
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends