class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> vec;
        
        int rowsize = matrix.size();
        int colsize = matrix[0].size();
        
        int total = rowsize*colsize;
        int count = 0;
        
        int col = colsize-1;
        int row = rowsize-1;
        
        for(int i=0 ;count<total && i<rowsize ; i++){
            
            for(int j=i ;count<total &&  j<colsize ; j++){
                vec.push_back(matrix[i][j]);
                count++;
            }
            colsize--;
            
            for(int k=i+1 ;count<total &&  k<rowsize ; k++){
                vec.push_back(matrix[k][col]);
                count++;
            }
            rowsize--;
            col--;
            
            for(int a = col;count<total && a>=i ; a--)
            {
                vec.push_back(matrix[row][a]);
                count++;
            }
            row--;
            
            for(int b = row ;count<total && b>=i+1 ; b--){
                vec.push_back(matrix[b][i]);  
                count++;
                
            } 
        }
        
        
        
        
        return vec;
    }
};