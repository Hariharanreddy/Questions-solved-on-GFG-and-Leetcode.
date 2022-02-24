class Solution {
public:
    
    int solve(vector<int>& nums, int lsum, int rsum ,int s, int e)
    {
        //base case when there is no pivot index
        if(s>e)
        {
            return -1;
        }
        
        //if pivot index
        rsum = rsum-nums[s];
        if(lsum == rsum)
        {
            return s;
        }
        
        return solve(nums, lsum+nums[s], rsum, s+1, e);
        
        
    }
    
    
    int pivotIndex(vector<int>& nums) {
        
        int size = nums.size();
        int lsum = 0;
        int rsum=0;
        for(int i=0 ; i<size; i++)
        {
            rsum += nums[i];
        }
        
        return solve(nums, lsum, rsum, 0 , size-1);
    }
};