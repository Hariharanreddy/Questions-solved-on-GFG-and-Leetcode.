class Solution {
public:
    int climbStairs(int n) {
        int prev2=1;
        int prev=1;
        
        int ways = 0;
        
        for(int i=1 ; i<n ; i++)
        {
            ways=(prev2+prev);
            prev2=prev;
            prev=ways;
        }
        
        return prev;
    }
};