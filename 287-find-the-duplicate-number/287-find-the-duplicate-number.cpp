class Solution {
public:
    int findDuplicate(vector<int>& vec) {
        
        int slow = vec[0];
        int fast = vec[0];
        
        //make them meet at a place within the cycle
        do{
            slow = vec[slow];
            fast = vec[vec[fast]];
        }while(slow != fast);
        
        //place the fast pointer to vec[0]
        fast = vec[0];
        while(slow != fast)
        {
            slow = vec[slow];
            fast = vec[fast];
        }
        
        return slow;
        
    }
};