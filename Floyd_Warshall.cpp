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

void floydWarshall(vector<vector<int>> &dis) {
    // Code here
    for(int via = 0; via<dis.size(); via++){
        for(int i = 0; i<dis.size(); i++){
            for(int j = 0; j<dis.size(); j++){
                if(i == j)      dis[i][j] = 0;
                else{
                    dis[i][j] = min(dis[i][j], dis[i][via]+dis[via][j]);
                }
            }
        }
    }
}
void print(vector<vector<int>> &ans){

    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans.size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int V, E;
    cout<<"Enter the number of vertices and edges : ";
    cin>>V>>E;
    cout<<"Enter the edges in the format u, v, w (node u to v with weight w) : "<<endl;
    vector<vector<int>> dist(V, vector<int>(V, 1e8));
    for(int i = 0; i<E; i++){
        int u, v, w;
        cin>>u>>v>>w;
        dist[u][v] = w;
    }
    
    cout<<endl<<"Shortest weighted path from every node to every other node : "<<endl;
    floydWarshall(dist);// minimum distance from all nodes to all

    print(dist);
}