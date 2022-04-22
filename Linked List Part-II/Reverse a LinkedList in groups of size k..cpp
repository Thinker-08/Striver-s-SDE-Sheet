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
int lengthOfLinkedList(ListNode* head)
{
    int length = 0;
    while(head != NULL)
    {
        ++length;
        head = head->next;
    }
    return length;
}
ListNode* reverseKGroup(ListNode* head, int k) 
{ 
    if(head == NULL||head->next == NULL) 
        return head;
    int length = lengthOfLinkedList(head);
    ListNode* testing_head = new ListNode(0);
    testing_head->next = head;
    ListNode* pre =testing_head;
    ListNode* cur;
    ListNode* nex;

    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    return testing_head->next;
}
int32_t main()
{
    fast;
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    ListNode* head=new ListNode(v[0]);
    ListNode* temp=head;
    rep(i,1,n)
    {
        temp->next=new ListNode(v[i]);
        temp=temp->next;
    }
    printList(head);
    ListNode* ans=reverseKGroup(head,k);
    printList(ans);
    newline;
}


