// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& arr) {
         
        vector<vector<int>> ans;
        vector<int> output;
        
        //Edge Case
        if(arr.size() == 0)
        {
            return ans;
        }
        
        //Sorting the arr
        sort(arr.begin(), arr.end());
        
        int low = arr[0][0], high = arr[0][1];
        
        //Processing the other intervals
        int rows = arr.size();
        for(int i=1 ; i<rows ; i++)
        {
                //It means the overlapping doesn't exist
                if(arr[i][0] < low || arr[i][0] > high)
                {
                    
                    //Insert previous interval into ans
                    
                    output.push_back(low);
                    output.push_back(high);
                    
                    ans.push_back(output);
                    
                    output.pop_back();
                    output.pop_back();
                    // cout<<output[0]<<" "<<output[1]<<" ";
                    // cout<<endl;
                    
                    //Update low and high
                    low = arr[i][0];
                    high = arr[i][1];
                    
                }
                    //It means overlapping exists
                else
                {
                    //update high
                    if(high < arr[i][1])
                    {
                        high = arr[i][1];
                    }
                }
        }
        
        //Insert the last interval
        output.push_back(low);
        output.push_back(high);
                    
        ans.push_back(output);
               
        return ans; 
         
         
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends