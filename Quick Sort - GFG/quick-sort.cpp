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
    //Function to sort an array using quick sort algorithm.
    int partition (int arr[], int s, int e)
    {
       //taking pivot as the first element
       int pivot = arr[s];
       
       
       //counting the number of elements smaller than it
       int count = 0;
       for(int i=s+1 ; i<=e ; i++){
           if(arr[i] <= pivot){
               count++;
           }
       }
       
       //swapping it with element having position s+count
       int pivotindex = s+count;
       swap(arr[s], arr[pivotindex]);
       
       //partioning by placing pointers at first and last position
       int i = s, j = e;
       
       
       while(i < pivotindex && j > pivotindex){
           
           while(arr[i] <= pivot){
               i++;
           }
           
           while(arr[j] > pivot){
               j--;
           }
           
           
           if(i < pivotindex && j > pivotindex){
               swap(arr[i++], arr[j--]);
           }
           
       }
       
       return pivotindex;
       
    }
    
    void quickSort(int arr[], int s, int e)
    {
        // base case -> 1 or 0 element in array are sorted.
        if(s >= e){
            return;
        }
        
        //Partitioning
        int p = partition(arr, s, e);
        
        //sort the left half
        quickSort(arr, s, p-1);
        
        //sort the right half
        quickSort(arr, p+1, e);
    }
    
    
    
};


// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends