class Trie {
public:
    class Node{
            public: 
                int end;
                Node* next[26];
                Node()
                {
                    for(int i=0;i<26;i++)
                        next[i]=NULL;
                    end=false;
                }
        };
    Node* tri;
    Trie() {
        tri=new Node();
    }
    
    void insert(string word) {
        Node* temp=tri;
        int i=0;
        while(i<word.length())
        {
            if(temp->next[word[i]-'a']==NULL)
                temp->next[word[i]-'a']=new Node();
            temp=temp->next[word[i]-'a'];
            i++;
        }
        temp->end=true;
    }
    
    bool search(string word) {
        Node* temp=tri;
        int i=0;
        while(i<word.length())
        {
            if(temp->next[word[i]-'a']==NULL)
                return false;
            temp=temp->next[word[i]-'a'];
            i++;
        }
        return temp->end;
    }
    
    bool startsWith(string word) {
        Node* temp=tri;
        int i=0;
        while(i<word.length())
        {
            if(temp->next[word[i]-'a']==NULL)
                return false;
            temp=temp->next[word[i]-'a'];
            i++;
        }
        if(temp->end)
            return true;
        for(int i=0;i<26;i++)
        {
            if(temp->next[i]!=NULL)
                return true;
        }
        return false;
    }
};