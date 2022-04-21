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

void printList(ListNode* node) 
{ 
    while (node != NULL) { 
        cout << node->data<<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 
ListNode* sorted(ListNode* head1,ListNode* head2) 
{
    if(head1==NULL)
        if(head2==NULL)
            return NULL;
        else
            return head2;
    else           
        if(head2==NULL)
            return head1;
        else
        {
            ListNode* temp, *ans;
            if(head1->data<head2->data)
            {
                temp=head1;
                ans=head1;
                head1=head1->next;
            }
            else
            {
                temp=head2;
                ans=head2;
                head2=head2->next;
            }
            while(head1!=NULL and head2!=NULL)
            {
                if(head1->data<head2->data)
                {
                    temp->next=new ListNode(head1->data);
                    temp=temp->next;
                    head1=head1->next;
                }
                else
                {
                    temp->next = new ListNode(head2->data);
                    temp=temp->next;
                    head2=head2->next;
                }
            }
            while(head1!=NULL)
            {
                temp->next = new ListNode(head1->data);
                head1=head1->next;
                temp=temp->next;
            }
            while(head2!=NULL)
            {
                temp->next = new ListNode(head2->data);
                head2=head2->next;
                temp=temp->next;
            }
            return ans;
        }
}
int32_t main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<int> v(n),v2(m);
    rep(i,0,n)
        cin>>v[i];
    rep(i,0,m)
        cin>>v2[i];
    ListNode* head = new ListNode(v[0]);
    ListNode* head1 = new ListNode(v2[0]);
    ListNode* temp=head;
    rep(i,1,n)
    {
        temp->next=new ListNode(v[i]);
        temp=temp->next;
    }
    temp=head1;
    rep(i,1,m)
    {
        temp->next=new ListNode(v2[i]);
        temp=temp->next;
    }
    ListNode* ans=sorted(head,head1);
    printList(ans);
}


