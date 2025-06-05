#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dfs(vector<vector<int>>& graph, int u, int prev, int k) {
        if (k == 0) return 1;
        int res = 0;
        for (const int v : graph[u])
            if (v != prev) res += dfs(graph, v, u, k - 1);
        return 1 + res;
    }
    vector<vector<int>> buildGraph(const vector<vector<int>>& edges) {
        vector<vector<int>> graph(edges.size() + 1);
        for (const vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return graph;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int> ans;
        vector<vector<int>> graph1 = buildGraph(edges1);
        vector<vector<int>> graph2 = buildGraph(edges2);
        int maxReachableInGraph2 = 0;

        if (k > 0)
            for (int i = 0; i < edges2.size() + 1; ++i)
                maxReachableInGraph2 = max(maxReachableInGraph2, dfs(graph2, i, -1, k - 1));
        for (int i = 0; i < edges1.size() + 1; ++i)
            ans.push_back(maxReachableInGraph2 + dfs(graph1, i, -1, k));
        return ans;
    }
};

int main(){

}