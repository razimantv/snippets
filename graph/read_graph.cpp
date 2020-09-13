#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> graph; // Uweighted and undirected

int main() {
  int N, M;  // Vertices and edges
  std::cin >> N >> M;
  graph G(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    std::cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u); // If directed, remove this
  }
  return 0;
}
