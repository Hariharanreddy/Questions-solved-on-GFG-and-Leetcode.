// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
         vector<int> ans;
       
       
       int count = 0;
       int total = r*c;
       
       int startingrow = 0;
       int startingcol = 0;
       int endingrow = r - 1;
       int endingcol = c - 1;
       
       while(count < total)
       {
           
           for(int index=startingcol;count<total && index <= endingcol ; index++)
           {
               ans.push_back(matrix[startingrow][index]);
           count++;
               
           }
           startingrow++;
           
           
           for(int index=startingrow;count<total && index <= endingrow ; index++)
           {
               ans.push_back(matrix[index][endingcol]);
           count++;
               
           }
           endingcol--;
           
           for(int index=endingcol;count<total && index >= startingcol ; index--)
           {
               ans.push_back(matrix[endingrow][index]);
           count++;
               
           }
           endingrow--;
           
           for(int index=endingrow;count<total && index >= startingrow ; index--)
           {
               ans.push_back(matrix[index][startingcol]);
           count++;
               
           }
           startingcol++;
           
       }
       return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends