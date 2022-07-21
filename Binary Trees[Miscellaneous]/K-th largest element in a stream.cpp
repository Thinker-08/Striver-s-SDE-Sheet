int cc;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        cc=k;
        for(int i=0;i<nums.size();i++)
            pq.push(nums[i]);
        while(pq.size()>k)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>cc)
            pq.pop();
        return pq.top();
    }