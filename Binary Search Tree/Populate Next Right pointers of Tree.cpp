Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int count=q.size();
            while(count--)
            {
                Node* temp=q.front();
                q.pop();
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                if(count==0)
                    temp->next=NULL;
                else
                    temp->next=q.front();
            }
        }
        return root;
    }