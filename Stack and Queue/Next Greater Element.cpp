vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> v,ans;
        for(int i=0;i<nums2.size();i++)
            v.push_back(nums2[i]);
        for(int i=0;i<nums2.size();i++)
        {
            if(s.empty())
                s.push(i);
            else
            {
                while(!s.empty() and nums2[i]>nums2[s.top()])
                {
                    nums2[s.top()]=nums2[i];
                    s.pop();
                }
                s.push(i);
            }
        }
        while(!s.empty())
        {
            nums2[s.top()]=-1;
            s.pop();
        }
        map<int,int> mp;
        for(int i=0;i<nums2.size();i++)
            mp[v[i]]=nums2[i];
        for(int i=0;i<nums1.size();i++)
            ans.push_back(mp[nums1[i]]);
        return ans;

    }