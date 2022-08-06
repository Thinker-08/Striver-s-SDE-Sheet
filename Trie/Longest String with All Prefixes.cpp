#include<bits/stdc++.h>
class Trie{
    public:
    class Node{
        public:
            Node* next[26];
            int end;
            Node()
            {
                for(int i=0;i<26;i++)
                    next[i]=NULL;
                end=false;
            }
    };
    Node* tri;
    Trie()
    {
        tri=new Node();
    }
    void insert(string a)
    {
        Node* temp=tri;
        int i=0;
        while(i<a.length())
        {
            if(temp->next[a[i]-'a']==NULL)
            {
                temp->next[a[i]-'a']=new Node();
            }
            temp=temp->next[a[i]-'a'];
            i++;
        }
        temp->end=true;
    }
    bool check(string word)
    {
        Node* temp=tri;
        int i=0;
        while(i<word.length())
        {
            temp=temp->next[word[i]-'a'];
            i++;
        }
        return (temp->end);
    }
};
string completeString(int n, vector<string> &a){
    Trie* obj = new Trie();
    for(int i=0;i<n;i++)
        obj->insert(a[i]);
    vector<string> temp,ans;
    for(int i=0;i<n;i++)
    {
        string x;
        int flag=0;
        for(int j=0;j<a[i].length();j++)
        {
            x+=a[i][j];
            if(!obj->check(x))
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            temp.push_back(a[i]);
        }
    }
    if(temp.empty())
        return "None";
    int maxi=0;
    for(int i=0;i<temp.size();i++)
    {
        int x = temp[i].length();
        maxi=max(maxi,x);
    }
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i].length()==maxi)
            ans.push_back(temp[i]);
    }
    sort(ans.begin(),ans.end());
    return ans[0];
}