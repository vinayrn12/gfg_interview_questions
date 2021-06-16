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
    Node *reverse_list(Node *head){
        Node *currptr = head;
        Node *prevptr = NULL;
        Node *forwptr = NULL;

        while(currptr->next){
            forwptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = forwptr;
        }
        currptr->next = prevptr;
        return currptr;
    }

    void addBack(Node *&head, Node *&last, int data){

        Node *newNode=new Node(data);
        //   newNode->data=data;
        newNode->next=NULL;

        if(last==NULL)
            head=newNode;
        else
            last->next=newNode;
        last=newNode;

    }

    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse_list(first);
        second = reverse_list(second);

        Node *res;
        Node *last=NULL; // Last node of new list
        int sum,carry=0;

        while(first || second){
            int a = (first) ? first->data : 0;
            int b = (second) ? second->data : 0;

            sum = (a + b + carry);
            carry = sum / 10;
            sum %= 10;

            addBack(res, last, sum);

            if(first)
                first = first->next;

            if(second)
                second = second->next;
        }

        if(carry)
            addBack(res, last, carry);

        return reverse_list(res);
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
