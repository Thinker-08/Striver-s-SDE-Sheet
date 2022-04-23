#include<bits/stdc++.h>
#define fast1 ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>  
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;
    
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
    
};


void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int32_t main(void) {

    int t;
    cin>>t;
    while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
    struct Node * head=NULL;
    struct Node * pre=NULL;
    struct Node * tempB=NULL;
    struct Node * preB=NULL;
        cin>>n;
        int work[n];
        for(int i=0;i<n;i++)
            cin>>work[i];
        for(int i=0;i<n;i++){
            m=work[i];
            --m;
            int data;
            scanf("%d",&data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;
            
            if(flag){
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else{
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for(int j=0;j<m;j++){
                
                int temp_data;
                scanf("%d",&temp_data);
                tempB = new Node(temp_data);

                if(flag1){
                    temp->bottom=tempB;
                    preB=tempB;
                    flag1=0;
                }
                else{
                    preB->bottom=tempB;
                    preB=tempB;
                }
            }
        }
           Node *fun = head;
           Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

    }
    return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* mergeLists(Node* a,Node* b)
{
    Node* head=new Node(0);
    Node* temp=head;
    while(a!=NULL and b!=NULL)
    {
        if(a->data<b->data)
        {
            head->bottom=new Node(a->data);
            head=head->bottom;
            a=a->bottom;
        }
        else
        {
            head->bottom=new Node(b->data);
            head=head->bottom;
            b=b->bottom;
        }
    }
    if(a!=NULL)
        head->bottom=a;
    if(b!=NULL)
        head->bottom=b;
    return temp->bottom;
}
Node *flatten(Node *root)
{
    if(root==NULL)
        return NULL;
    root->next = flatten(root->next);
    return (mergeLists(root,root->next));
}