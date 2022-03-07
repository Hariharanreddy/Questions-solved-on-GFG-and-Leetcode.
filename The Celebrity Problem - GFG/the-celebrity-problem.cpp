// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    bool knows(vector<vector<int> >& M, int a, int b)
    {
        if(M[a][b] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        //step 1 -> push all person in stack 
        stack<int> s;
        for(int i=0; i<n ; i++)
        {
            s.push(i);
        }
        
        //step 2 -> find potential celebrity
        while(s.size() != 1)
        {
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M, a, b))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        
        //step 3 -> check potential celeb
        int celeb = s.top();
        int rowcount = 0;
        int colcount = 0;
        
        for(int i = 0 ; i< n ;i++)
        {
            if(M[celeb][i] == 1)
            {
                rowcount++;
            }
            
            if(M[i][celeb] == 1)
            {
                colcount++;
            }
        }
        
        if(rowcount != 0)
        {
            return -1;
        }
        
        if(colcount != n-1)
        {
            return -1;
        }
        
        return s.top();
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends