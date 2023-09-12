class Trie {
public:
    class Node {
        public: 
            bool end;
            Node* next[26];
        Node()
        {
            end=false;
            for(int i=0;i<26;i++)
                next[i]=NULL;
        }
    };
    Node* trie;
    Trie() {
        trie = new Node();
    }
    
    void insert(string word) {
        Node* temp = trie;
        for(int i=0;i<word.length();i++)
        {
            if(temp->next[word[i]-'a']==NULL)
                temp->next[word[i]-'a'] = new Node();
            temp=temp->next[word[i]-'a'];
        }
        temp->end=true;
    }
    
    bool search(string word) {
        Node* temp=trie;
        for(int i=0;i<word.length();i++)
        {
            if(temp->next[word[i]-'a']==NULL)
                return false;
            temp=temp->next[word[i]-'a'];
        }
        if(temp->end)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* temp=trie;
        for(int i=0;i<prefix.length();i++)
        {
            if(temp->next[prefix[i]-'a']==NULL)
                return false;
            temp=temp->next[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
