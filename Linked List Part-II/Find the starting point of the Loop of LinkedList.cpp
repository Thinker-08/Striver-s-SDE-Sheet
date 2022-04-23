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
bool checkCycle(ListNode* head)
{
    if(head==NULL)
        return false;
    if(head->next==NULL)
        return false;
    ListNode* slow=head;
    ListNode* fast=head;
    while(slow->next!=NULL and fast->next!=NULL and fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}
ListNode *detectCycle(ListNode *head)
{
    if(!checkCycle(head))
        return NULL;
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return NULL;
    ListNode* slow=head;
    ListNode* fast=head;
    while(slow->next!=NULL and fast->next!=NULL and fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            break;
    }
    slow=head;
    while(slow->next!=NULL and fast->next!=NULL)
    {
        if(slow==fast)
            return slow;
        slow=slow->next;
        fast=fast->next;
    }
    return NULL;
}
int32_t main()
{
    fast1;
    ListNode* head= new ListNode(0);
    head->next=new ListNode(1);
    head->next->next=new ListNode(2);
    head->next->next->next=head->next->next;
    ListNode* temp=detectCycle(head);
    if(temp!=NULL)
        cout<<temp->data;
    else
        cout<<"NO";
    newline;
}


