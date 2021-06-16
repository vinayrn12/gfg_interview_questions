// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {

        // Add code here
        Node *zero_start = NULL;
        Node *zero_end = NULL;
        Node *one_start = NULL;
        Node *one_end = NULL;
        Node *two_start = NULL;
        Node *two_end = NULL;

        while(head){
            if(head->data == 0){
                if(zero_end == NULL){
                    zero_start = head;
                    zero_end = zero_start;
                }
                else{
                    zero_end->next = head;
                    zero_end = head;
                }
            }
            else if(head->data == 1){
                if(one_end == NULL){
                    one_start = head;
                    one_end = one_start;
                }
                else{
                    one_end->next = head;
                    one_end = head;
                }
            }
            else{
                if(two_end == NULL){
                    two_start = head;
                    two_end = two_start;
                }
                else{
                    two_end->next = head;
                    two_end = head;
                }
            }
            head = head->next;
        }

        if(zero_start){
            if(one_start){
                zero_end->next = one_start;
                if(two_start){
                    one_end->next = two_start;
                    two_end->next = NULL;
                }
                else
                    one_end->next = NULL;
            }
            else{
                if(two_start){
                    zero_end->next = two_start;
                    two_end->next = NULL;
                }
                else
                    zero_end->next = NULL;
            }
            return zero_start;
        }
        else if(one_start){
            if(two_start){
                one_end->next = two_start;
                two_end->next = NULL;
            }
            else
                one_end->next = NULL;
            return one_start;
        }
        else{
            two_end->next = NULL;
            return two_start;
        }
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends
