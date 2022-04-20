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
ListNode* middleNode(ListNode* head) {
        vector<ListNode*> v;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp);
            temp=temp->next;
        }
        return v[v.size()/2];
}

int32_t main()
{
    fast;
    int n;
    cin>>n;
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
    ListNode* ans=middleNode(head);
    cout<<ans->data;
}


