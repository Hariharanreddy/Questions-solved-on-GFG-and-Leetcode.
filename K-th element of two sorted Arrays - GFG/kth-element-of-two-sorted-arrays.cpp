// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        //max heap
        priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<int>> minpq;
        bool arr1_traversed_first = false;
        
        //use min heap when
        if(n < k && m < k)
        {
            int new_k = ((n+m) -k) + 1;
            
            
            
            
            //processing the first k elements
            if(n < new_k)
            {
                for(int i=0 ; i<new_k ; i++)
                {
                    minpq.push(arr2[i]);
                }
                
            }
            else
            {
                for(int i=0 ; i<new_k ; i++)
                {
                    minpq.push(arr1[i]);
                }
                arr1_traversed_first = true;
            }
            
            //processing for the rest elements
            if(!arr1_traversed_first)
            {
                for(int i=new_k ; i<m ; i++)
                {
                    if(arr2[i] > minpq.top())
                    {
                        minpq.pop();
                        minpq.push(arr2[i]);
                    }
                }
                for(int i = 0 ; i<n ; i++)
                {
                    if(arr1[i] > minpq.top())
                    {
                        minpq.pop();
                        minpq.push(arr1[i]);
                    }
                    
                }
            }
            else
            {
                for(int i=new_k ; i<n ; i++)
                {
                    if(arr1[i] > minpq.top())
                    {
                        minpq.pop();
                        minpq.push(arr1[i]);
                    }
                }
                for(int i = 0 ; i<m ; i++)
                {
                    if(arr2[i] > minpq.top())
                    {
                        minpq.pop();
                        minpq.push(arr2[i]);
                    }
                }
            }
                
            return minpq.top();
            
        }
        
        
        //process the first k elements
        if(n < k)
        {
            for(int i=0 ; i<k ; i++)
            {
                pq.push(arr2[i]);
            }
            
        }
        else
        {
            for(int i=0 ; i<k ; i++)
            {
                pq.push(arr1[i]);
            }
            arr1_traversed_first = true;
        }
        
        //processing for the rest elements
        if(!arr1_traversed_first)
        {
            for(int i=k ; i<m ; i++)
            {
                if(arr2[i] < pq.top())
                {
                    pq.pop();
                    pq.push(arr2[i]);
                }
            }
            for(int i = 0 ; i<n ; i++)
            {
                if(arr1[i] < pq.top())
                {
                    pq.pop();
                    pq.push(arr1[i]);
                }
                
            }
        }
        else
        {
            for(int i=k ; i<n ; i++)
            {
                if(arr1[i] < pq.top())
                {
                    pq.pop();
                    pq.push(arr1[i]);
                }
            }
            for(int i = 0 ; i<m ; i++)
            {
                if(arr2[i] < pq.top())
                {
                    pq.pop();
                    pq.push(arr2[i]);
                }
            }
        }
        
        return pq.top();
        
        
        
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends