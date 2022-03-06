// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node *head)
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
        
        return prev;
    }
    
    void insertAthead(Node *&head, int digit)
    {
        Node *temp = new Node(digit);
        //if empty
        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            temp -> next = head;
            head = temp;
        }
    }
    
    Node* addOne(Node *head) 
    {
        
        int carry = 1;
        Node *ptr = reverse(head);
        
        Node *newhead = NULL;
        Node *newtail = NULL;
        
        
        while(ptr != NULL)
        {
            int sum = carry + ptr -> data;
            int digit = sum%10;
            insertAthead(newhead, digit);
            carry = sum/10;
            
            ptr = ptr -> next;
        }
        
        if(carry > 0)
        {
            insertAthead(newhead, 1);
        }
        
        return newhead;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends