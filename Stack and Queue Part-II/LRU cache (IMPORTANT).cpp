#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
class LRUCache
{
    public:
        list<pair<int,int>> l;
    map<int,pair<list<pair<int,int>>::iterator,int>> mp;
    int cap;    
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        pair<list<pair<int,int>>::iterator,int> temp=mp[key];
        mp.erase(key);
        l.erase(temp.first);
        l.push_front({key,temp.second});
        mp[key]={l.begin(),temp.second};
        return mp[key].second;
    }
    
    void set(int key, int value) {
        if(mp.find(key)==mp.end())
        {
            if(l.size()==cap)
            {
                mp.erase(l.back().first);
                l.pop_back();
                l.push_front({key,value});
                mp[key]={l.begin(),value};
                
            }
            else
            {
                l.push_front({key,value});
                mp[key]={l.begin(),value};
            }
        }
        else
        {
            l.erase(mp[key].first);
            mp.erase(key);
            l.push_front({key,value});
            mp[key]={l.begin(),value};
        }
    }
};

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}