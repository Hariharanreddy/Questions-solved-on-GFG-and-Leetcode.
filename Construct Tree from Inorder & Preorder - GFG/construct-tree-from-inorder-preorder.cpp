// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int findpos(int in[], int PreEndindex, int element)
    {
        for(int i = 0 ; i<PreEndindex ; i++)
        {
            if(in[i] == element)
            {
                return i;
            }
        }
        
        return -1;
    }
    
    
    Node *solve(int in[],int pre[], int &PreStartindex, int PreEndindex, int InStartIndex, int InEndIndex)
    {
        //base case
        if(PreStartindex == PreEndindex || InStartIndex > InEndIndex)
        {
            return NULL;
        }
        
        //take out the element and create a root node
        int element = pre[PreStartindex++];
        Node *root = new Node(element);
        
        //find position of that element in Inorder array 
        int pos = findpos(in, PreEndindex, element);
        
        //recursive call to left -> similar to partitioning
        root -> left = solve(in, pre, PreStartindex, PreEndindex, InStartIndex, pos-1);  //do the same for left partition of inorder
        root -> right = solve(in, pre, PreStartindex, PreEndindex, pos+1, InEndIndex);   //do the same for right partition of inorder
        
        //return 
        return root;
    }
    
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int PreStartindex = 0;
        
        Node *ans = solve(in, pre, PreStartindex, n, 0, n-1);
        
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
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends