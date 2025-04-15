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

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    // Code here
    vector<int> dis(V, INT_MAX);
    dis[src] = 0;
    
    for(int f = 0; f<V; f++){
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            if(dis[u] != INT_MAX && dis[u]+w < dis[v]){
                dis[v] = dis[u]+w;
            }
        }
    }
    for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            if(dis[u] != INT_MAX && dis[u]+w < dis[v]){
                return {-1};//negative cycle detection
            }
        }
    for(int i = 0; i<V; i++){
        if(dis[i] == INT_MAX)   dis[i] = 1e8;//can't reach
    }
    
    return dis;
}
void print(vector<int> &ans){
    if(ans.size() == 1 && ans[0] == -1){
        cout<<"Negative cycle detected";
        return;
    }
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
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
    cout<<"Enter the source : ";
    int src;
    cin>>src;

    vector<int> ans = bellmanFord(V, edges, src);// minimum distance from src

    print(ans);
}