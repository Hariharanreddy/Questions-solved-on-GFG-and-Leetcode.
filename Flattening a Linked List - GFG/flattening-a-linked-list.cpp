// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */

void insertattail(int data ,Node* &head, Node* &tail)
{
    Node *newNode = new Node(data);
    //empty list
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail -> next = newNode;
        tail = tail -> next;
    }
    
}

Node *merge(Node *left, Node *right)
    {
        if(left == NULL)
        return right;
        
        if(right == NULL)
        return left;
        
        //using a dummy node 
        Node *ans = new Node(-1);
        Node *temp = ans;
        
        while(left != NULL && right != NULL)
        {
            if(left -> data < right -> data)
            {
                temp -> bottom = left;
                left = left -> bottom;
                temp = temp -> bottom;
            }
            else
            {
                temp -> bottom = right;
                right = right -> bottom;
                temp = temp -> bottom;
            }
        }
        
        while(left != NULL)
        {
            temp -> bottom = left;
            left = left -> bottom;
            temp = temp -> bottom;
        }
        
        while(right != NULL)
        {
            temp -> bottom = right;
            right = right -> bottom;
            temp = temp -> bottom;
        }
        
        ans = ans -> bottom;
        
        return ans;

    }

    
Node *flatten(Node *head)
{
   //base case
   if(head == NULL || head -> next == NULL)
        return head;
   
   
   
   Node *ptr = head -> next;     
   Node *down = head;            //first breaking the linked list
   down -> next = NULL;
   
   Node *right = flatten(ptr);   //bhai tuh mujhe flat karke de

   
   
   Node *result = merge(down, right);
   
   return result;

   
}

