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
ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
{
    unordered_set<ListNode*> s;
    while(head1!=NULL)
    {
        s.insert(head1);
        head1=head1->next;
    }
    while(head2!=NULL)
    {
        if(s.find(head2)!=s.end())
            return head2;
        else
            head2=head2->next;
    }
    return NULL;
}
int32_t main()
{
    fast;
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next = new ListNode(3);
    ListNode* head1 = new ListNode(4);
    head1->next = head->next->next;
    head->next->next->next=new ListNode(5);
    ListNode* ans=getIntersectionNode(head,head1);
    cout<<ans->data;
    newline;
}


