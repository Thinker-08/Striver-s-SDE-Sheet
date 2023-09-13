//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void insert(string &x, multiset<string> &temp, string s, int i)
	    {
	        if(i>=s.length())
	        {
	            temp.insert(x);
	            return;
	        }
	        x+=s[i];
	        insert(x, temp, s, i+1);
	        x.pop_back();
	        insert(x, temp, s, i+1);
	        
	    }
		vector<string> AllPossibleStrings(string s){
		    multiset<string> temp;
		    string x;
		    insert(x, temp, s, 0);
		    vector<string> ans;
		    temp.erase(temp.begin());
		    for(auto it:temp)
		        ans.push_back(it);
		    return ans;
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
