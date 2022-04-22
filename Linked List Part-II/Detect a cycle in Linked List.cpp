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
bool hasCycle(ListNode *head)
{
    if(head==NULL)
        return false;
    ListNode* slow=head,*fast;
    if(head->next==head)
        return true;
    else
    {
        if(head->next==NULL)
            return false;
        else
        {
            fast=head->next;
        }
    }
    while(slow->next!=NULL and fast->next!=NULL and fast->next->next!=NULL)
    {
        if(slow==fast)
            return true;
        else
        {
            slow=slow->next;
            fast=fast->next->next;
        }
    }
    return false;
}
int32_t main()
{
    fast1;
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next=head;
    if(hasCycle(head))
        cout<<"YES";
    else 
        cout<<"NO";
    newline;
}


