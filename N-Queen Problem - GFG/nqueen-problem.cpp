// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    void solve(int col, vector<vector<int>> &ans,vector<int> &board,vector<int> & leftRow,
        vector<int> &upperDiagonal,vector<int> &lowerDiagonal,int n)
    {
        //base case
        if(col >= n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0 ; row<n ; row++)
        {
            if(leftRow[row] == 0 && upperDiagonal[row+col] == 0
                && lowerDiagonal[n-1 + col - row] == 0)
            {
                //mark that queen with the row
                board[col] = row+1;
                
                //map those 
                leftRow[row] = 1;
                upperDiagonal[row+col] = 1;
                lowerDiagonal[n-1 + col - row] = 1;
                
                solve(col+1, ans, board, leftRow, upperDiagonal, lowerDiagonal, n);
                
                //map those 
                leftRow[row] = 0;
                upperDiagonal[row+col] = 0;
                lowerDiagonal[n-1 + col - row] = 0;
                
                
            }
        }
        
        
        
        
    }
    
    

    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>> ans;
        vector<int> board(n, 0);
        
        vector<int> leftRow(n, 0), upperDiagonal(2*n -1 , 0), lowerDiagonal(2*n -1 , 0);
        
        int col = 0;
        solve(col, ans, board, leftRow, upperDiagonal, lowerDiagonal, n);
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends