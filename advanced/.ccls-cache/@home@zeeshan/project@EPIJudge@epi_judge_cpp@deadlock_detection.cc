#include <stdexcept>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/timed_executor.h"
using std::vector;

bool dfs(int i, std::vector<std::vector<int>> const &graph, std::vector<bool> & visited)
{
    //std::cout << "\n" << i << "-->";
    visited[i] = true;
    for(int j=0; j<graph[i].size(); ++j)
    {
        //std::cout << graph[i][j] << " ";
        if(graph[i][j] == i)
            continue;
        if(visited[graph[i][j]])
            return true;
        if(dfs(graph[i][j], graph, visited))
            return true;
            
    }
    return false;
}
bool IsDeadlocked(vector<vector<int>> const & graph) {
  // TODO - you fill in here.
    /*
    for(auto x : graph)
    {
        std::copy(x.begin(), x.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << "\n";
    }
    std::cout << "---\n";
    */
    std::vector<bool> visited(graph.size(), false);
    for(int i=0; i<graph.size(); ++i)
    {
        if(not visited[i] and dfs(i, graph, visited))
            return true;
    }
    return false;
}
struct Edge {
  int from;
  int to;
};

namespace test_framework {
template <>
struct SerializationTrait<Edge> : UserSerTrait<Edge, int, int> {};
}  // namespace test_framework

bool HasCycleWrapper(TimedExecutor& executor, int num_nodes,
                     const vector<Edge>& edges) {
  vector<std::vector<int>> graph;
  if (num_nodes <= 0) {
    throw std::runtime_error("Invalid num_nodes value");
  }
  graph.reserve(num_nodes);

  for (int i = 0; i < num_nodes; i++) {
    graph.push_back(vector<int>{});
  }

  for (const Edge& e : edges) {
    if (e.from < 0 || e.from >= num_nodes || e.to < 0 || e.to >= num_nodes) {
      throw std::runtime_error("Invalid vertex index");
    }
    graph[e.from].push_back(e.to);
  }

  return executor.Run([&] { return IsDeadlocked(graph); });
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "num_nodes", "edges"};
  return GenericTestMain(args, "deadlock_detection.cc",
                         "deadlock_detection.tsv", &HasCycleWrapper,
                         DefaultComparator{}, param_names);
}
