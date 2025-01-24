class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n = graph.size();
    vector<int> outDegree(n, 0); 
    vector<vector<int>> reverseGraph(n); 
    queue<int> q; 
    vector<int> safeNodes;

    for (int i = 0; i < n; ++i) {
        for (int neighbor : graph[i]) {
            reverseGraph[neighbor].push_back(i);
        }
        outDegree[i] = graph[i].size();
    }

    for (int i = 0; i < n; ++i) {
        if (outDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);

        for (int predecessor : reverseGraph[node]) {
            --outDegree[predecessor];
            if (outDegree[predecessor] == 0) {
                q.push(predecessor);
            }
        }
    }
    sort(safeNodes.begin(), safeNodes.end());

    return safeNodes;
}
};