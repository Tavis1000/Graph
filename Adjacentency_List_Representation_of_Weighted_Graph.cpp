#include<bits/stdc++.h>
using namespace std;
vector<list<pair<int, int>>> graph;
void add_edge(int src, int des, int wei, bool dir = true){
    graph[src].push_back({des, wei});
    if(dir == true){
        graph[des].push_back({src, wei});
    }
}
void display(vector<list<pair<int, int>>> &graph){
    for(int i = 0; i<graph.size(); i++){
        cout<<i<<" -> ";
        for(auto j : graph[i]){
            cout<<j.first<<" "<<j.second<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int v;
    cin>>v;
    graph.resize(v , list<pair<int, int>> ());
    int n;
    cin>>n;
    while(n--){
        int src, des, wei;
        // bool dir;
        cin>>src>>des>>wei;
        // cin>>dir;
        add_edge(src, des, wei);
    }
    display(graph);
    return 0;
}