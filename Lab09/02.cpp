#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void dfsHelper(int node, unordered_map<int, bool> &visited) {
        
        visited[node] = true;
        cout << node << " ";

        
        for (auto nbr : adj[node]) {
            if (!visited[nbr]) {
                dfsHelper(nbr, visited);
            }
        }
    }

    void dfs(int start) {
        unordered_map<int, bool> visited;
        cout << "DFS Traversal: ";
        dfsHelper(start, visited);
    }
};

int main() {
    graph g;

    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 3, 0);

    g.dfs(0);

    return 0;
}
