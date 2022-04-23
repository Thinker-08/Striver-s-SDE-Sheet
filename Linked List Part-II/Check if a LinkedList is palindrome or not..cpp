#include<bits/stdc++.h>
#define fast1 ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
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
void printList(ListNode* node) 
{ 
    while (node != NULL) { 
        cout << node->data<<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 
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
bool isPalindrome(ListNode* head)
{
    if(head->next==NULL)
        return true;
    ListNode* slow=head;
    ListNode* fast=head;
    while(slow->next!=NULL and fast->next!=NULL and fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    fast=reverse(slow->next);
    slow->next=NULL;
    while(fast->next!=NULL and head->next!=NULL)
        
    {
        if(fast->data==head->data)
        {
            fast=fast->next;
            head=head->next;
        }
        else
            return false;
    }
    if(fast!=NULL and head!=NULL and fast->data==head->data)
        return true;
    else
        return false;
}
int32_t main()
{
    fast1;
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    ListNode* head=new ListNode(v[0]);
    ListNode* temp=head;
    rep(i,1,n)
    {
        head->next=new ListNode(v[i]);
        head=head->next;
    }
    if(isPalindrome(temp))
        cout<<"YES";
    else
        cout<<"NO";
    newline;
}


