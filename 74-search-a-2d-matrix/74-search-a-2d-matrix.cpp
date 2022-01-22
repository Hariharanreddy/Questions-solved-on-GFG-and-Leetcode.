class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rowsize = matrix.size();
        int colsize = matrix[0].size();
        int s = 0;
        int e = rowsize*colsize-1;
        
        int mid = s + (e-s)/2;
        
        int element;
        while(s<=e)
        {
            element = matrix[mid/colsize][mid%colsize];
            
            if(element == target){
                return 1;
            }
            else if(element > target)
            {
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
            
            mid = s + (e-s)/2;
        }
        return 0;
        
    }
};