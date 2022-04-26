// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool cmp(Item &a,Item &b)
    {
        return (double)a.value/(double)a.weight> (double)b.value/(double)b.weight;
        
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans=0;
        sort(arr,arr+n,cmp);
        int i=0;
        while(i<n and W!=0)
        {
            if(arr[i].weight<W)
            {
                ans+=arr[i].value;
                W=W-arr[i].weight;
                i++;
            }
            else
            {
                ans+=double(arr[i].value*W)/double(arr[i].weight);
                W=0;
            }
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends