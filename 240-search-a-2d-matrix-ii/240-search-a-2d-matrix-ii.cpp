class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
     
        int rowindex = 0;
        int colindex = col-1;
        
        int element;
        
        while(rowindex < row && colindex>=0)
        {
            
            element = matrix[rowindex][colindex];
            
            if(element == target)
            {
                return 1;
            }
            
            if(element > target)
            {
                colindex--;
            }
            else
            {
                rowindex++;
            }
            
            
        }
        
        return 0;
        
    }
};