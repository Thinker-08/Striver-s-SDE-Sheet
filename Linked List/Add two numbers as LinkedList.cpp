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
    Node* reverse(Node* head)
    {
        Node* cur=head;
        Node* prev=NULL;
        while(head!=NULL)
        {
            head=head->next;
            cur->next=prev;
            prev=cur;
            cur=head;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* f=reverse(first);
        Node* s=reverse(second);
        Node* ans=new Node(0);
        Node* head=ans;int carry=0;
        while(f!=NULL and s!=NULL)
        {
            ans->data=(f->data+s->data+carry)%10;
            carry=(f->data+s->data+carry)/10;
            ans->next=new Node(0);
            ans=ans->next;
            f=f->next;
            s=s->next;
        }
        while(f!=NULL)
        {
            ans->data=(f->data+carry)%10;
            carry=(f->data+carry)/10;
            ans->next=new Node(0);
            ans=ans->next;
            f=f->next;
        }
        while(s!=NULL)
        {
            ans->data=(s->data+carry)%10;
            carry=(s->data+carry)/10;
            ans->next=new Node(0);
            ans=ans->next;
            s=s->next;
        }
        while(carry)
        {
            ans->data=carry%10;
            carry/=10;
            ans->next=new Node(0);
            ans=ans->next;
        }
        head=reverse(head);
        head=head->next;
        return head;
    }
};


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