// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isValid(int grid[N][N], int row, int col, int ch)
    {
        //In single loop - 3 things will be checked
        //row, col and the 3x3 box is having ch or not
        
        //since it is a 9x9 matrix
        for(int i=0 ; i<9 ; i++)
        {
            //row check
            if(grid[i][col] == ch)
            {
                return false;
            }
            
            //col check
            if(grid[row][i] == ch)
            {
                return false;
            }
            
            if(grid[3 * (row/3) + i/3][3 * (col/3) + i%3] == ch)
            {
                return false;
            }
        }
        return true;
    }
    
    
    bool SolveSudoku(int grid[N][N])  
    { 
        //iterate the whole matrix
        for(int i = 0 ; i<N ; i++)
            for(int j = 0 ; j<N ; j++)
            {
                
                if(grid[i][j] == 0)
                {
                    //try to put 0 - 9
                    for(int value = 1 ; value <= 9 ; value++)
                    {
                        if(isValid(grid, i, j, value))
                        {
                            //store it
                            grid[i][j] = value;
                            
                            if(SolveSudoku(grid))
                            {
                                return true;
                            }
                            else
                            {
                                grid[i][j] = 0;   
                            }
                        }
                    }
                    
                    return false;
                }
            }
            
        //it means whole matrix has been traversed completely
        //with all the elements
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        SolveSudoku(grid);
        
            for(int i=0 ; i<N ; i++)
                for(int j=0 ; j<N ; j++)
                {
                    cout<<grid[i][j]<<" ";
                }
        
        
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends