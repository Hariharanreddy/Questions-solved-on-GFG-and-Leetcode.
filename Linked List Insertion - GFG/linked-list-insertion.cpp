// { Driver Code Starts
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
        cout << node->data <<" "; 
        node = node->next; 
  }  
  cout<<"\n";
} 



 // } Driver Code Ends
/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       // Your code here
       //if its the first element to be inserted
       if(head == NULL)
       {
           Node *temp = new Node(x);
           head = temp;
           return head;
       }
       
       Node *temp = new Node(x);
       temp->next = head;
       head = temp;                 //update head
       
       return head;
       
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       // Your code here
       
       //if its the first element to be inserted
       if(head == NULL)
       {
           Node *temp = new Node(x);
           head = temp;
           return head;
       }
       
       Node *ptr = head;
       while(ptr->next != NULL)
       {
           ptr = ptr->next;
       }
       
       Node *temp = new Node(x);
       ptr->next = temp;
       
       
       return head;
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
        struct Node *head = NULL;
        for (int i = 0; i < n; ++i)
        {
            int data, indicator;
            cin>>data;
            cin>>indicator;
            Solution obj;
            if(indicator)
                head = obj.insertAtEnd(head, data); 
            else
                head = obj.insertAtBegining(head, data);
        }
        printList(head); 
    }
    return 0; 
} 

  // } Driver Code Ends