#include <iostream>
#include <vector>
#include <queue>

typedef std::vector<std::vector<int>> graph;

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
  std::vector<int> distance;
  std::queue<int> bfsqueue;
  visited[0]=1;
  bfsqueue.push(0);
  while(!bfsqueue.empty()) {
    int u = bfsqueue.front();
    bfsqueue.pop();

    for(int v: G[u]) {
      if(visited[v]) continue;
      distance[v] = distance[u] + 1;
      visited[v] = true;
      bfsqueue.push(v);
    }
  }
  return 0;
}
