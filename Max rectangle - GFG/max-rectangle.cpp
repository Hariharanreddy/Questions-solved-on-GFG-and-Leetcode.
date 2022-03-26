// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    
       
    vector<int> NextSmallerElement(vector<int> vec, int size)
    {
        vector<int> ans(size);
        
        stack<int> s;
        s.push(-1);
        
        for(int i = size-1 ; i >= 0 ; i--)
        {
            
            while(s.top() != -1 && vec[s.top()] >= vec[i])
            {
                s.pop();
            }
            
            ans[i] = s.top();
        
            s.push(i);
        }
        
        return ans;
        
    }
    
    vector<int> PrevSmallerElement(vector<int> vec, int size)
    {
        vector<int> ans(size);
        
        stack<int> s;
        s.push(-1);
        
        for(int i = 0 ; i < size ; i++)
        {
            
            while(s.top() != -1 && vec[s.top()] >= vec[i])
            {
                s.pop();
            }
            
            ans[i] = s.top();
            
            s.push(i);
        }
        
        return ans;
        
    }
    
    
    int Largesthistogram(vector<int> vec, int c)
    {
        //find the indexes of next smaller element
        vector<int> next(c, 0);
        vector<int> prev(c, 0);
        
        //returns the vector having indexes of next smaller elements
        next = NextSmallerElement(vec, c);
        
        //for prev smaller element
        prev = PrevSmallerElement(vec, c);
        
        
        int area = INT_MIN;
        //traversing the column and calculating max area
        for(int i = 0 ; i < c ; i++)
        {
            int l = vec[i];
            
            if(next[i] == -1)
            {
                next[i] = c;
            }
            
            int b = next[i] - prev[i] - 1;
            
            area = max(area, l*b);
        }
        
        return area;
        
    }
    

  
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        vector<int> vec(m, 0);
        int area = INT_MIN;
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(M[i][j] == 0)
                {
                    vec[j] = 0;
                }
                else
                {
                    vec[j] += M[i][j];
                }
            }
            
            int new_area = Largesthistogram(vec, m);
            
            area = max(new_area, area);
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