vector<int> Solution::dNums(vector<int> &A, int B) {
    if(B>A.size())
        return {};
    else
    {
        map<int,int> mp;
        vector<int>ans;
        int i=0,j=0;
        while(j<A.size())
        {
            if(j-i+1<B)
                mp[A[j]]++;
            else
            {
                mp[A[j]]++;
                ans.push_back(mp.size());
                if(mp[A[i]]==1)
                    mp.erase(A[i]);
                else
                    mp[A[i]]--;
                i++;    
            }
            j++;
        }
        return ans;
    }
}
