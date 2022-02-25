// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        cout<< countNodesinLoop(head) << endl;
    }
	return 0;
}
// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
bool detectLoop(struct Node* head, struct Node*& slow, struct Node*& fast) {
    

    while(fast != NULL && fast -> next != NULL)
    {

        //cycle is present
        if(slow == fast)
        {
            //cout<<slow -> data<<" "<<fast->data<<endl;
            return true;
        }
        
        fast = fast -> next -> next;
        slow = slow -> next;
        //cout<<slow -> data<<" "<<fast->data<<endl;

    }
    
    return false;

}


int countNodesinLoop(struct Node *head)
{
    //for single node or empty list
    if(head == NULL || head -> next == NULL)
    {
        return 0;
    }
    
    struct Node *slow = head;
    struct Node *fast = head -> next;
    
    if(detectLoop(head, slow, fast))
    {
        int count = 1;
        //cout<<slow -> data<<" "<<fast->data<<endl;
        
        slow = slow -> next;
        while(slow != fast)
        {
            count++;
            slow = slow -> next;
        }
        
        return count;
    }
    else
    {
        return 0;
    }

    
}