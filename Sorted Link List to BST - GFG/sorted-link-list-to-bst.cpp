// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


 // } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
    void storeNodesdata(LNode *head,vector<int> &vec)
    {
        LNode *temp = head;
        
        while(temp != NULL)
        {
            vec.push_back(temp->data);
            temp = temp -> next;
        }
    }
    
    TNode* createBST(int s, int e, vector<int> &vec)
    {
        if(s>e)
        {
          return NULL;
        }
        
        int mid = (s+e+1)/2;
        TNode* newRoot = new TNode(vec[mid]);
        
        newRoot -> left = createBST(s, mid-1 , vec);
        newRoot -> right = createBST(mid+1, e , vec);
        
        return newRoot;
    }
    
    TNode* sortedListToBST(LNode *head) {
        
        //store linkedlist in vector
        vector<int> vec;
        
        storeNodesdata(head, vec);
        
        int s = 0, e = vec.size()-1;
        return createBST(s, e, vec);
        
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

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends