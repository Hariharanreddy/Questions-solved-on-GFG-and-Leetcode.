class Solution {
public:

int search(vector<int> &arr,int size, int s, int e){
        
        if(s>e)
            return -1;
        
        
        int mid = s + (e-s)/2;
        
        if(mid == 0 || (arr[mid-1]<arr[mid] && arr[mid+1]>arr[mid]))
            return search(arr, size, mid+1, e);
        
        if(mid == size-1 || (arr[mid-1]>arr[mid] && arr[mid+1]<arr[mid]))
            return search(arr,size, s, mid-1);
        
        if((arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) || mid == 0 || mid == size-1)
                return mid;
            
    
        return 0;
    }
    
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int e = arr.size()-1;
        
        
        return search(arr,arr.size(), 0, e);
    }
};