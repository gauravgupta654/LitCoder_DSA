#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU {
private:
    vector<int> parent, rank;
    
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return false; // Already connected
        }
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
    
    int countComponents() {
        int components = 0;
        for (int i = 0; i < parent.size(); i++) {
            if (find(i) == i) {
                components++;
            }
        }
        return components;
    }
};

int minOperationsToConnect(int N, vector<pair<int, int>>& routes) {
    DSU dsu(N);
    int extraEdges = 0;
    
    for (const auto& route : routes) {
        int u = route.first;
        int v = route.second;
        
        if (!dsu.unite(u, v)) {
            extraEdges++;
        }
    }
    
    int components = dsu.countComponents();
    
    int neededEdges = components - 1;
    
    if (extraEdges >= neededEdges) {
        return neededEdges;
    }
    
    return -1; // Not possible
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> routes(M);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        routes[i] = {u, v};
    }
    
    int result = minOperationsToConnect(N, routes);
    cout << result << endl;
    
    return 0;
}
