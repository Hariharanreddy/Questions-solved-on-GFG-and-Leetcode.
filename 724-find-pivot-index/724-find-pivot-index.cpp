class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int sum = 0;
        int size = nums.size();
        
        for(int i=0; i<size ; i++){
            sum+=nums[i];
        }
        
        int lsum = 0;
        int rsum = sum;
        
        for(int i = 0 ; i<size ; i++){
            rsum = rsum-nums[i];
            
            if(lsum == rsum)
                return i;
            else
                lsum=lsum+nums[i];
            
        }
        
        return -1;
    }
};