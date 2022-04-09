// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int subsum(int arr[], int n)
    {
        int res = arr[0];
        int maxending = arr[0];
        
        for(int i = 1;i<n;i++)
        {
            maxending = max(maxending+arr[i], arr[i]);
            res = max(res, maxending);
        }
        
        return res;
    }
    
    int circularSubarraySum(int arr[], int num){
        
        //Max Subarray Sum
        int max_normal_sum = subsum(arr, num);
        
        //If sum is negative then in rotation also it will be negative
        if(max_normal_sum < 1)
        {
            return max_normal_sum;
        }
        
        int arr_sum = 0;
        
        for(int i=0;i<num;i++)
        {
            //calculating total sum of array
            arr_sum = arr[i]+arr_sum;
            
            //modifying the array elements to opposite sign
            arr[i]=arr[i]*-1;
        }
        
        int max_cir_sum = arr_sum + subsum(arr, num);
        
        return max(max_cir_sum, max_normal_sum);
        
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends