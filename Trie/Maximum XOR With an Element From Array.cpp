class Trie{
    public:
    class Node{
        public: 
        bool end;
        Node* next[2];
        Node()
        {
            end=false;
            next[0]=NULL;
            next[1]=NULL;
        }
    };
    Node* trie;
    Trie()
    {
        trie = new Node();
    }
    void insert(int num)
    {
        Node* x = trie;
        for(int i=31;i>=0;i--)
        {
            int temp = (num>>i)&1;
            if(x->next[temp]==NULL)
                x->next[temp]=new Node();
            x = x->next[temp];
        }
        x->end=true;
    }
    int find(int num)
    {
        Node* x = trie;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int a=0;
            int temp = (num>>i)&1;
            if(temp)
            {
                if(x->next[0]==NULL)
                    x = x->next[1], a=1;
                else
                    x = x->next[0], a=0;
                ans=(ans)|(a<<i);
            }
            else
            {
                if(x->next[1]==NULL)
                    x = x->next[0], a=0;
                else
                    x = x->next[1], a=1;
                ans=(ans)|(a<<i);
            }
        }
        cout<<ans<<" "<<num<<endl;
        return ans^num;
    }
};
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1]<b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        sort(nums.begin(), nums.end());
        for(int i=0;i<queries.size();i++)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), cmp);
        Trie* trie = new Trie();
        int j=0;
        for(int i=0;i<queries.size();i++)
        {
            for(;j<nums.size();j++)
            {
                if(nums[j]<=queries[i][1])
                    trie->insert(nums[j]);
                else
                    break;
            }
            if (j > 0) {
                int val = trie->find(queries[i][0]);
                ans[queries[i][2]] = val;
            } else {
                ans[queries[i][2]] = -1;
            }
        }
        return ans;
    }
};
