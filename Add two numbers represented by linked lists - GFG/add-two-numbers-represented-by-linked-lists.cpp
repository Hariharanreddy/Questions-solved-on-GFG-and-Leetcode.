// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    void reverse(struct Node* &head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *forward;
        
        while(curr != NULL)
        {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        
        //updating head
        head = prev;
    }
    
    void insertathead(struct Node* &head, int digit)
    {
        Node *temp = new Node(digit);
        //if list is empty
        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            Node *ptr = head;
            head = temp;
            temp -> next = ptr;
        }
    }
    
    
    struct Node* add(struct Node* first, struct Node* second)
    {
        
        int carry = 0;
        
        Node *ansHead = NULL;
        
        while(first != NULL && second != NULL)
        {
            int sum = carry + first -> data + second -> data;
            int digit = sum%10;
            
            insertathead(ansHead, digit);
            
            
            //update carry, first , second
            carry = sum/10;
            first = first -> next;
            second = second -> next;
            
        }
        
        while(first != NULL)
        {
            int sum = carry + first -> data;
            int digit = sum%10;
            insertathead(ansHead, digit);
            carry = sum/10;
            first = first -> next;
     
        }
        
        while(second != NULL)
        {
            int sum = carry + second -> data;
            int digit = sum%10;
            insertathead(ansHead, digit);
            carry = sum/10;
            second = second -> next;
     
        }
        
        if(carry != 0)
        {
            insertathead(ansHead, carry);
        }
        
        return ansHead;
        
        
    }
    
    
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //step 1 reverse the 2 nodes
        reverse(first);
        reverse(second);
        
        //step 2 add the two nodes
        Node *ans = add(first, second);
        
        //step 4 return
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
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends