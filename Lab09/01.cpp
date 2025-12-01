#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        // direction = 1 (directed), 0 (undirected)
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void bfs(int start) {
        unordered_map<int, bool> visited;
        queue<int> q;

        
        q.push(start);
        visited[start] = true;

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            
            for (auto nbr : adj[node]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }
};

int main() {
    graph g;

    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 3, 0);

    g.bfs(0);

    return 0;
}
