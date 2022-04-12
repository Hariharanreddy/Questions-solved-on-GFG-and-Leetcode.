// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    
    class Node{
        
        public:
        int data;
        int i;
        int j;
        
        Node(int d, int r, int c)
        {
            data = d;
            i = r;
            j = c;
        }
    };
    
    class compare{
        public:
        bool operator()(Node *a, Node* b)
        {
            return a->data > b->data;
        }
    };
    
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        //to store final answer
        pair<int, int> ans; 
        
        //maxi and mini
        int mini = INT_MAX, maxi = INT_MIN;
        
        
        //Min-Heap
        priority_queue<Node*, vector<Node *>, compare> pq;
        
        //Store First columnq elements in heap as well as track maxi
        for(int i=0 ; i<k ; i++)
        {
            int element = arr[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);
            Node *temp = new Node(element, i, 0);
            pq.push(temp);
        }
        
        //previous maxi and mini
        int start = mini, end = maxi;
        
        //now iterate whole array with help of minheap
        while(!pq.empty())
        {
            Node *temp = pq.top();
            pq.pop();
            
            //take out everything
            int row = temp->i;
            int col = temp->j;
            int mini = temp->data;
            
            //update maxi and mini is range is smaller
            if(maxi - mini < end - start)
            {
                end = maxi;
                start = mini;
            }
            
            if(col + 1 < n)
            {
                Node *newNode = new Node(arr[row][col+1], row, col+1);
                pq.push(newNode);
                
                //update maxi
                maxi = max(maxi, arr[row][col+1]);
            }
            else
            {
                break;
            }
        }
        
        ans.first = start;
        ans.second = end;
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends