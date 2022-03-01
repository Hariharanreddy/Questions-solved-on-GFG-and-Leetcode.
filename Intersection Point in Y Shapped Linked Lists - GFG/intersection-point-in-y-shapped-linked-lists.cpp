// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
bool detectloop(Node *&head1,Node *&slow,Node *&fast)
{
    while(fast != NULL && fast -> next !=NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        
        if(slow == fast)
        {
            return true;
        }
    }
    
    return false;
}



int intersectPoint(Node* head1, Node* head2)
{
    if(head1 == NULL || head2 == NULL)
    {
        return -1;
    }
    
    
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    
    while(ptr1 -> next != NULL)
    {
        ptr1 = ptr1 -> next;
    }
    
    ptr1 -> next = head2;
    
    Node *slow = head1;
    Node *fast = head1;
    
    if(detectloop(head1, slow, fast))
    {
        slow = head1;
        
        while(slow != fast)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return slow -> data;
    }
    else
    {
        return -1;
    }
    
    
    
    
    
}

