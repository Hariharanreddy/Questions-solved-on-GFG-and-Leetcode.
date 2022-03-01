// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int r)
    {
         int m = l + (r - l)/2;
         
         int len1 = m - l + 1;
         int len2 = r - m;
         
         int *first = new int[len1];
         int *second = new int[len2];
         
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
         
    }
    
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r)
        {
            return;
        }
        
        int mid = l+(r-l)/2;
        
        //left side sort
        mergeSort(arr, l, mid);
        
        //right side sort
        mergeSort(arr, mid+1, r);
        
        merge(arr, l, r);
        
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends