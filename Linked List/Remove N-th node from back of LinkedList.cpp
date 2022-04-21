#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>  
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
struct ListNode
{
    int data;
    struct ListNode* next;
    
    ListNode(int x){
        data = x;
        next = NULL;
    }
};
ListNode* reverse(ListNode* head)
    {
        ListNode* cur=head;
        ListNode* prev=NULL;
        while(cur!=NULL)
        {
            head=head->next;
            cur->next=prev;
            prev=cur;
            cur=head;
        }
        return prev;
    }
void printList(ListNode* node) 
{ 
    while (node != NULL) { 
        cout << node->data<<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 
ListNode* removeNthFromEnd(ListNode* head, int n) {
        head=reverse(head);
        if(n==1)
            return (reverse(head->next));
        ListNode* temp=head;
        int count=1;
        while(temp!=NULL and count+1!=n)
        {
            temp=temp->next;
            count++;
        }
        if(temp->next!=NULL and temp->next->next!=NULL)
            temp->next=temp->next->next;
        else 
            temp->next=NULL;
        temp = reverse(head);
        return temp;
    }
int32_t main()
{
    fast;
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    ListNode* head = new ListNode(v[0]);
    ListNode* temp=head;
    rep(i,1,n)
    {
        temp->next=new ListNode(v[i]);
        temp=temp->next;
    }
    ListNode* ans=removeNthFromEnd(head,target);
    printList(ans);
}


