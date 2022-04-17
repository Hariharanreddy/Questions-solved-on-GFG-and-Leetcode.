class Solution {
public:
    void findcombination(int idx,int target,vector<int>&candidates,                   vector<vector<int>>& ans, int n, vector<int>& ds)
    {
        
        if(idx == n || target == 0)
        {
            if(target==0)
            {
                ans.push_back(ds);
                return;
            }
        }
        //looping goes from current index to end of the vector 
        for(int i=idx ; i<n ; i++)
        {
            //if current index value is greater than target then break from the loop
            if(candidates[i]>target)
            {
                break;
            }
            //if the index is smaller than i 
		    //value at current index is equal to value at next index then we will not consider the next element
            if(i>idx && candidates[i]==candidates[i-1])
            {
                continue;
            }
            //thus we can pick the element
            ds.push_back(candidates[i]);
            //recursilvely call for picking and smilarly reduce the target
            findcombination(i+1,target-candidates[i],candidates,ans,n,ds);
            //now remove the element before going to next index
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        //sorting is done as we need subsequences in order
        sort(candidates.begin(),candidates.end());
        
	    vector<vector<int>>ans;
	    vector<int>ds;
        
        int size = candidates.size();
        
	    findcombination(0,target,candidates,ans,size,ds);
        
        return ans;
    }
};