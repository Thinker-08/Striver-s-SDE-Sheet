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
ListNode* rotateRight(ListNode* head, int k)
{
    if(head==NULL)
        return NULL;
    if(!k)
        return head;
    vector<ListNode*> v;
    while(head!=NULL)
    {
        v.push_back(head);
        head=head->next;
    }
    k=k%v.size();
    if(k==0)
        return v[0];
    v[v.size()-k-1]->next=NULL;
    v[v.size()-1]->next=v[0];
    return v[v.size()-k];
}
int32_t main()
{
    fast1;
    int n,k;
    cin>>n>>k;
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
    ListNode* ans=rotateRight(temp,k);
    printList(ans);
    newline;
}


