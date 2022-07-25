#include<bits/stdc++.h>
using namespace std;

int main(){
	int N=5,m=6;
	vector<pair<int,int> > adj[N]; 
	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});
    int parent[N];   
    int distance[N]; 
    bool visited[N]; 
    for (int i = 0; i < N; i++) 
        distance[i] = INT_MAX, visited[i] = false; 
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    distance[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop();     
        visited[u] = true; 
        for (auto it : adj[u])
        {
            if (visited[it.first] == false && it.second < distance[it.first])
            {
                parent[it.first] = u;
	            distance[it.first] = it.second; 
                pq.push({distance[it.first], it.first});    
            }
        }      
    } 
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}