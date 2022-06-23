// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
   priority_queue<int> pq1;
   priority_queue<int,vector<int>,greater<int>> pq2;
    void insertHeap(int &x)
    {
        if(pq1.size()==pq2.size())
        {
            if(pq1.size()==0)
            {
                pq1.push(x);
                return;
            }
            if(x<pq1.top())
                pq1.push(x);
            else
            {
                pq2.push(x);
            }
        }
        else
        {
            if(pq1.size()>pq2.size())
            {
                if(x>pq1.top())
                {
                    pq2.push(x);
                }
                else
                {
                    pq2.push(pq1.top());
                    pq1.pop();
                    pq1.push(x);
                }
            }
            else
            {
                if(x<pq2.top())
                    pq1.push(x);
                else
                {
                    pq1.push(pq2.top());
                    pq2.pop();
                    pq2.push(x);
                }
            }
        }
    }
    double getMedian()
    {
        if(pq1.size()==pq2.size())
            return (pq1.top()*1.0+pq2.top()*1.0)/2*1.0;
        else
        {
            if(pq1.size()>pq2.size())
                return pq1.top();
            else
                return pq2.top();
        }
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends