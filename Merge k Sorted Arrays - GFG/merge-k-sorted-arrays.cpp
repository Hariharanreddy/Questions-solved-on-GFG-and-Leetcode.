// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    class Node{
      
      public:
      
      int data;
      int i;
      int j;
      
      Node(int data, int row, int col)
      {
          this -> data = data;
          i = row;
          j = col;
      }
    };
    
    //custom comparator for minHeap
    class compare{
        
        public:
        bool operator()(Node *a, Node *b)
        {
            return a->data > b->data;
        }
        
    };
    
    
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //final answer storage
        vector<int> ans;
        
        //Minheap creation
        priority_queue<Node *, vector<Node *>, compare> pq;
        
        //store all the 1st col elements of 2d vector in minheap
        for(int i=0 ; i<k ; i++)
        {
            Node *temp = new Node(arr[i][0], i, 0);
            pq.push(temp);
        }
        
        while(!pq.empty())
        {
            Node *temp = pq.top();
            pq.pop();
            
            //store the smallest element
            ans.push_back(temp->data);
            int row = temp->i;
            int col = temp->j;
            
            //check if its not exciding the limits
            if(col+1 < k)
            {
                Node *newNode = new Node(arr[row][col+1], row, col+1);
                pq.push(newNode);
            }
            
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends