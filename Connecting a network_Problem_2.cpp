#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) {
        return -1;
    }
    
    vector<vector<int>> adj(n);
    for (auto& conn : connections) {
        adj[conn[0]].push_back(conn[1]);
        adj[conn[1]].push_back(conn[0]);
    }
    
    vector<bool> visited(n, false);
    int components = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }
    
    return components - 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> connections;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        connections.push_back({a, b});
    }
    
    int result = makeConnected(n, connections);
    cout << result << endl;
    
    return 0;
}
