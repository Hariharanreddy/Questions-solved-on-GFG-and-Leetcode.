#include <iostream>
#include <vector>
using namespace std;

vector<int> min_sum_subarray(int arr[], int n, vector<int> &cal)
{
    int min_ending = 10400;
    int res = 10400;
    
    for(int i = 0 ; i<n ; i++)
    {
        for(int j=i ; j<n ; j++)
        {
            min_ending = min(min_ending+arr[j], arr[j]);
            res = min(min_ending, res);
        }
        
        cal.push_back(res);
        min_ending = 10400;
        res = 10400;
    }
    
    return cal;
}


int main() {
	//code
	int t;
	cin >> t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int arr[n];
	    for(int i = 0 ; i<n ; i++)
	    {
	        cin>>arr[i];
	    }
	    
	    vector<int> vec;
	    vec = min_sum_subarray(arr, n, vec);
	    
	    for(int i = 0 ; i< n; i++)
	    {
	        cout<<vec[i]<<" ";
	    }
	    cout<<endl;
	    
	}
	return 0;
}