class Solution {
public:
    class Trie
    {
        public:
        class Node{
            public:
                Node* next[2];
                Node()
                {
                    next[0]=NULL;
                    next[1]=NULL;
                }
        };
        Node* tri;
        Trie()
        {
            tri=new Node();
        }
        void insert(int num)
        {
            Node* temp=tri;
            for(int i=31;i>=0;i--)
            {
                int bit = (num>>i)&1;
                if(temp->next[bit]==NULL)
                    temp->next[bit]=new Node();
                temp=temp->next[bit];
            }
        }
        int get_ans(vector<int> &nums)
        {
            int maxi=0;
            for(int i=0;i<nums.size();i++)
            {
                Node* temp=tri;
                int cur=0;
                for(int j=31;j>=0;j--)
                {
                    if((nums[i]>>j)&1)
                    {
                        if(temp->next[0]==NULL)
                        {
                            temp=temp->next[1];
                            cur=cur<<1;
                        }
                        else
                        {
                            temp=temp->next[0];
                            cur=cur<<1;
                            cur=cur|1;
                        }
                    }
                    else
                    {
                        if(temp->next[1]==NULL)
                        {
                            temp=temp->next[0];
                            cur=cur<<1;
                        }
                        else
                        {
                            temp=temp->next[1];
                            cur=cur<<1;
                            cur=cur|1;
                        }
                    }
                }
                maxi=max(maxi,cur);
            }
            return maxi;
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        Trie* temp= new Trie();
        for(int i=0;i<nums.size();i++)
        {
            temp->insert(nums[i]);
        }
        int ans=temp->get_ans(nums);
        return ans;
    }
};
