class Solution {
public:

        int firstpos(vector<int>& nums, int target, int start, int end)
    {
        //base case if not found
        if(start>end)
            return -1;
        
        
        int mid = start + (end-start)/2;
        
        //if found
        if(nums[mid] > target)
            return firstpos(nums, target, start, mid-1);
        
        else if(nums[mid] < target)
            return firstpos(nums, target, mid+1, end);

        else{
            if(mid == 0 || nums[mid]!=nums[mid-1])
                return mid;
            else
                return firstpos(nums, target, start, mid-1);
        }
        
        
	}
    
    int lastpos(vector<int>& nums, int target, int start, int end)
    {
        //base case if not found
        if(start > end){
            return -1;
        }
        
        int mid = start + (end-start)/2;
        
        //if found
        if(nums[mid] > target)
            return lastpos(nums, target, start, mid-1);
        
        else if(nums[mid] < target)
            return lastpos(nums, target, mid+1, end);

        else{
            if(mid == nums.size()-1 || nums[mid]!=nums[mid+1])
                return mid;
            else
                return lastpos(nums, target, mid+1, end);
        }
        

    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
       
        vector<int> vec;
        
        int size = nums.size();
        
        vec.push_back(firstpos(nums, target, 0, size-1));
        vec.push_back(lastpos(nums, target, 0, size-1));
        
        return vec;
        
    }
};