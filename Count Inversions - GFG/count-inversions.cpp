// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[], long long l, long long r)
    {
         long long count_inv = 0;
         
         long long m = l + (r - l)/2;
         
         int len1 = m - l + 1;
         int len2 = r - m;
         
         long long *first = new long long[len1];
         long long *second = new long long[len2];
         
         int main_array_index = l;
         for(int i = 0 ; i< len1 ; i++)
         {
             first[i] = arr[main_array_index++];
         }
         
         main_array_index = m+1;
         for(int i = 0 ; i< len2 ; i++)
         {
             second[i] = arr[main_array_index++];
         }
         
         main_array_index = l;
         int i = 0;
         int j = 0;
         
         while(i < len1 && j < len2)
         {
             if(first[i] <= second[j])
             {
                 arr[main_array_index++] = first[i++]; 
             }
             else
             {
                 arr[main_array_index++] = second[j++];
                 count_inv++;
                 count_inv = count_inv + len1 - 1 - i;
                 
             }
         }
         
         while(i<len1)
         {
            arr[main_array_index++] = first[i++]; 
         }
         
         while(j<len2)
         {
             arr[main_array_index++] = second[j++]; 
         }
         
         delete[] first;
         delete[] second;
         
         return count_inv;
         
    }
    
    long long  mergeSort(long long arr[], long long l, long long r)
    {
        
        if(l>=r)
        {
            return 0;
        }
        
        long long count = 0;
        
        long long mid = l+(r-l)/2;
        
        //left side sort
        count += mergeSort(arr, l, mid);
        
        //right side sort
        count += mergeSort(arr, mid+1, r);
        
        count += merge(arr, l, r);
        
        return count;
        
    }
    
long long int inversionCount(long long arr[], long long N)
    {
        
        long long int ans = mergeSort(arr, 0, N-1);
        return ans;
        
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends