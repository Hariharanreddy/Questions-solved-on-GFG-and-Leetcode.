// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/
void insertAttail(Node* &head, Node *&tail, int digit)
    {
        Node *temp = new Node(digit);
        //if list is empty
        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }

Node* findIntersection(Node* head1, Node* head2)
{
    map<int, bool> visited;
    
    Node *ptr1 = head1;
    while(ptr1 != NULL)
    {
        visited[ptr1 -> data] = true;
        ptr1 = ptr1 -> next;
    }
    
    Node *ptr2 = head2;
    Node *newhead = NULL;
    Node *newtail = NULL;
    
    
    while(ptr2 != NULL)
    {
        if(visited[ptr2 -> data] == true)
        {
            insertAttail(newhead, newtail, ptr2 -> data);
            visited[ptr2 -> data] = false;
        }
        ptr2 = ptr2 -> next;
    }

    return newhead;    
    
    
}