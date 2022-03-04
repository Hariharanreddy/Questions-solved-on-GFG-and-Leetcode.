// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/






class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node *findmid(Node *head)
    {
        Node *slow = head;
        Node *fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow;
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
                temp -> next = left;
                left = left -> next;
                temp = temp -> next;
            }
            else
            {
                temp -> next = right;
                right = right -> next;
                temp = temp -> next;
            }
        }
        
        while(left != NULL)
        {
            temp -> next = left;
            left = left -> next;
            temp = temp -> next;
        }
        
        while(right != NULL)
        {
            temp -> next = right;
            right = right -> next;
            temp = temp -> next;
        }
        
        ans = ans -> next;
        
        return ans;

    }
    
    
    
    
    Node* mergeSort(Node* head) {
        
        //base case -> assuming single or empty lists are already sorted
        if(head == NULL || head -> next == NULL)
        {
            return head;
        }
        
        //step 1 = breaking the LL , after finding mid
        Node *mid = findmid(head);
        
        Node *left = head;
        Node *right = mid -> next;
        mid -> next = NULL;           //breaking the LL
        
        
        //step 2 = sort the 2 halves using recursion
        left = mergeSort(left);
        right = mergeSort(right);
        
        //step 3 = merge the 2 halves
        Node *result = merge(left, right);
        
        //step 4 return
        return result;
        
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends