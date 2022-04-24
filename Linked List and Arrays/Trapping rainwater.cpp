int trap(vector<int>& arr)
{
    stack<int> s;
    int ans=0;
    for(int i=0;i<arr.size();i++)
    {
        while(!s.empty() and arr[s.top()]<arr[i])
        {
            int temp=arr[s.top()];
            s.pop();
            if(s.empty())
                break;
            ans+=(min(arr[i],arr[s.top()])-temp)*(i-s.top()-1);
        }
        s.push(i);
    }
    return ans;
}