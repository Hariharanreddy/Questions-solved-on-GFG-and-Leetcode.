// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
void createMap(int in[], int n, map<int, int> &mpp)
    {
        for(int i = 0; i < n ; i++)
        {
            mpp[in[i]] = i;
        }
    }
    
    Node *solve(int in[],int post[], int &postEndIndex, int postStartIndex,
                int InStartIndex, int InEndIndex, map<int, int> &mpp)
    {
        //base case
        if(postStartIndex > postEndIndex || InStartIndex > InEndIndex)
        {
            return NULL;
        }
        
        //take out the element and create a root node
        int element = post[postEndIndex--];
        Node *root = new Node(element);
        
        //find position of that element in Inorder array 
        int pos = mpp[element];
        
        //recursive call to left -> similar to partitioning
        root -> right = solve(in, post, postEndIndex, postStartIndex , pos+1, InEndIndex, mpp);   //do the same for right partition of inorder
        root -> left = solve(in, post, postEndIndex, postStartIndex , InStartIndex, pos-1, mpp);  //do the same for left partition
        
        //return 
        return root;
    }
    


Node *buildTree(int in[], int post[], int n) {
    
        //It will happen in reverse direction of pre order
        int postEndIndex = n-1;
        
        map<int, int> mpp;          //mapping node to index of inorder
        createMap(in , n, mpp);
        
        Node *ans = solve(in, post, postEndIndex, 0, 0, n-1, mpp);
        
        return ans;
        
}
