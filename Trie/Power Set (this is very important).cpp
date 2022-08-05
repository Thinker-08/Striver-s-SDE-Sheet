//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<string>ans;
	void find(string s,int idx,string temp)
	{
	    if(idx>=s.length())
	    {
	        ans.push_back(temp);
	        return;
	    }
	    find(s,idx+1,temp);
	    find(s,idx+1,temp+s[idx]);
	}
	vector<string> AllPossibleStrings(string s){
	    find(s,0,"");
	    sort(ans.begin(),ans.end());
	    vector<string> x;
	    for(int i=0;i<ans.size();i++)
	    {
	        if(ans[i]=="")
	            continue;
	        x.push_back(ans[i]);
	    }
	    return x;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends