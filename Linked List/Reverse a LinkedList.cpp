#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>  
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
struct List
{
    int data;
    List* next;
    List(int val)
    {
        data = val;
        next = NULL;
    }
};
List* a = NULL;
void insert(List* head,int val)
{
    List* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new List(val);
}

void display(List* head)
{
    List* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

List* reverse(List* head)
{
    List* prev = NULL;
    List* cur = head;
    while(cur!=NULL)
    {
        cur = cur->next;
        head->next = prev;
        prev = head;
        head = cur;
    }
    return prev;
}
int32_t main()
{
    fast;
    List* head = new List(1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    display(head);
    cout<<"\n";
    List* newhead = reverse(head);
    display(newhead); 
}