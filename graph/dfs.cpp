#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> graph;

void dfs(const graph& G, std::vector<bool>& visited, int u) {
  visited[u] = true;
  for (int v : G[u]) {
    if (!visited[v]) dfs(G, visited, v);
  }
}

int main() {
  // Copy graph reading from read_graph
  int N, M;  // Vertices and edges
  std::cin >> N >> M;
  graph G(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    std::cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);  // If directed, remove this
  }

  std::vector<bool> visited(N);
  dfs(G, visited, 0);
  return 0;
}
