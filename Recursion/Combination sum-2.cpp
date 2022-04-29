#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
vector<vector<int>> ans;
void findCombination(int ind, int target,vector<int>&arr, vector < int > & temp) 
{
    if(target == 0)
    {
        ans.push_back(temp);
        return;
    }
    for(int i=ind;i<arr.size();i++)
    {
        if (i>ind && arr[i]==arr[i-1])
            continue;
        if (arr[i]>target)
            break;
        temp.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], arr, temp);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    sort(candidates.begin(), candidates.end());
    vector<int> temp;
    findCombination(0, target,candidates,temp);
    return ans;
}
int32_t main()
{
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    rep(i,0,n)
        cin>>arr[i];
    vector<vector<int>> ans=combinationSum2(arr,target);
    rep(i,0,ans.size())
    {
        rep(j,0,ans[i].size())
            cout<<ans[i][j]<<" ";
        newline;
    }
}

