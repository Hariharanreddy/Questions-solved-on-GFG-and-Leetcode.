class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        int arr[n];
        
        for(int i = 0;i<n ; i++)
        {
            arr[(i+k)%n] = nums[i];
        }
        
        for(int i = 0;i<n ; i++)
        {
            nums[i] = arr[i];
        }
        
    }
};