// I/O and formatting
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

// Data structures
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <list>

// Algorithms and utilities
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <bitset>

// Strings
#include <string>
#include <string_view>

// Other useful libraries
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <chrono>
#include <random>
#include <array>
#include <tuple>
#include <limits>

// Chota
#define ll long long int

// For faster I/O
#define fast_io() std::ios::sync_with_stdio(false); std::cin.tie(nullptr)

// Constants
const int MOD = 1e9 + 7;
const long long int INF = LLONG_MAX;
const double EPS = 1e-9;

// Utility functions
template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

using namespace std;

long long dij(int src, int des, int v, vector<vector<pair<int, int>>> &adj){
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>> > pq;
    vector<long long> dis(v, INT_MAX);
    dis[src] = 0;
    pq.push({0, src});
    
    while(pq.size()){
        int s = pq.top().second;
        long long w = pq.top().first;
        pq.pop();
        
        for(auto i : adj[s]){
            int d = i.first;
            long long wt = i.second+w;
            if(s == src && d == des || s == des && d == src)    continue;
            if(wt < dis[d]){
                pq.push({wt, d});
                dis[d] = wt;
            }
        }
    }
    
    return dis[des];
}
int findMinCycle(int V, vector<vector<int>>& edges) {
    // code here
    long long ans = INT_MAX;
    vector<vector<pair<int, int>>> adj(V);
    for(int i = 0; i<edges.size(); i++){
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    for(int i = 0; i<edges.size(); i++){
        ans = min(ans, edges[i][2]+dij(edges[i][0], edges[i][1], V, adj));
    }
    return (int)ans;
}

int main() {
    int V, E;
    cout<<"Enter the number of vertices and edges : ";
    cin>>V>>E;
    cout<<"Enter the edges in the format u, v, w (node u to v with weight w) : "<<endl;

    vector<vector<int>> edges(E, vector<int> (3));
    for(int i = 0; i<E; i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
    }

    int result = findMinCycle(V, edges);
    if (result == -1)
        cout<<"No cycle found.\n";
    else
        cout<<"Minimum cycle length: "<<result<<endl;

    return 0;
}