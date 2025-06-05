#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getDistances(int start, vector<int>& dist, vector<int>& edges) {
        int d = 0;
        while (start != -1 && dist[start] == INT_MAX) {
            dist[start] = d++;
            start = edges[start];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);

        getDistances(node1, dist1, edges);
        getDistances(node2, dist2, edges);

        int result = -1, minDist = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};


int main(){

}