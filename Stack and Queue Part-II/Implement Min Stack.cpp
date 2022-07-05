stack<int> s;
    vector<int> mini;
    MinStack()
    {
        ;    
    }
    
    void push(int val)
    {
        s.push(val);
        mini.push_back(val);
    }
    
    void pop()
    {
        s.pop();   
        mini.pop_back();
    }
    
    int top()
    {
        return s.top();    
    }
    
    int getMin()
    {
        if(s.empty())
            return 0;
        else
        {
            int mi=INT_MAX; 
            for(int i=0;i<mini.size();i++)
                mi=min(mi,mini[i]);
            return mi;
        }
    }