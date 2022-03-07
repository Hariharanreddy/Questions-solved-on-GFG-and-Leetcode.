// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<int> prevSmallerElement(int arr[], int n)
    {
        stack<int> s;            //for indexes
        s.push(-1);             
        
        vector<int> ans(n);
        
        for(int i=0;i<n;i++)
        {
            int curr = arr[i];
            
            while(s.top() != -1 && arr[s.top()] >= curr)      //arr[s.top()] is the element on stack
            {
                s.pop();
            }
            
            ans[i] = s.top();      //store the prevsmallerelement index
            s.push(i);             //pushing the index
                
        }
        
        return ans;
        
        
    }
    
    vector<int> nextSmallerElement(int arr[], int n)
    {
        stack<int> s;
        s.push(-1);                 //for indexes
        
        vector<int> ans(n);
        
        for(int i=n-1; i>=0 ;i--)
        {
            int curr = arr[i];
            
            while(s.top() != -1 && arr[s.top()] >= curr)      //arr[s.top()] is the element on stack
            {
                s.pop();
            }
            
            ans[i] = s.top();      //store the nextsmallerelement index
            s.push(i);             //pushing the index
            
        }
        
        return ans;

    }
  
  
    int getMaxArea(int arr[], int n)
    {
        vector<int> next;
        next = nextSmallerElement(arr, n);
        
        vector<int> prev;
        prev = prevSmallerElement(arr, n);
        
        int area = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l = arr[i];
            
            if(next[i] == -1)
            {
                next[i] = n;
            }
            
            int b = next[i] - prev[i] - 1;
            
            area = max(area, l*b);
        }
        
        return area;
    }
  
  
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        int area = INT_MIN;
        
        int arr[m] = {0};
        
        for(int i = 0; i< n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                //if base row element is 0, histogram can't be made so take that bar of histogram as 0.
                if(M[i][j] == 0)
                {
                    arr[j] = 0;
                }
                else
                {
                arr[j] = arr[j] + M[i][j];
                }
            }
            
            area = max(area, getMaxArea(arr, m));
        }
        
        return area;
 
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends