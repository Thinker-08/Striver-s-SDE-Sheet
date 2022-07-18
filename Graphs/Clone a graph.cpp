Node* cloneGraph(Node* node)
    {
        if(node==NULL)
            return NULL;
        map<Node*,Node*> mp;
        set<Node*> q;
        set<Node*> s;
        q.insert(node);
        int count=1;
        Node* ans;
        while(!q.empty())
        {
            Node* x = *(q.begin());
            q.erase(q.begin());
            if(mp.find(x)==mp.end())
            {
                Node* temp=new Node();
                mp[x]=temp;
                temp->val = x->val;
                if(count==1)
                    ans=temp;
                for(int i=0;i<(x->neighbors).size();i++)
                {
                    if(mp.find((x->neighbors)[i])==mp.end())
                    {
                        Node* y = new Node();
                        mp[(x->neighbors)[i]]=y;
                        y->val = ((x->neighbors)[i])->val;
                        (temp->neighbors).push_back(y);
                    }
                    else
                        (temp->neighbors).push_back(mp[(x->neighbors)[i]]);
                    if(s.find((x->neighbors)[i])==s.end() and q.find((x->neighbors)[i])==q.end())
                        q.insert((x->neighbors)[i]);
                }
            }
            else
            {
                for(int i=0;i<(x->neighbors).size();i++)
                {
                    if(mp.find((x->neighbors)[i])==mp.end())
                    {
                        Node* y = new Node();
                        mp[(x->neighbors)[i]]=y;
                        y->val = ((x->neighbors)[i])->val;
                        (mp[x]->neighbors).push_back(y);
                    }
                    else
                        (mp[x]->neighbors).push_back(mp[(x->neighbors)[i]]);
                    if(s.find((x->neighbors)[i])==s.end() and q.find((x->neighbors)[i])==q.end())
                        q.insert((x->neighbors)[i]);
                }
            }
            s.insert(x);
            count++;
        }
        return ans;
    }