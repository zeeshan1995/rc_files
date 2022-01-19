#include <stdexcept>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::string;
using std::vector;

void dfs(int x, int y, vector<vector<char>> const & board, std::vector<std::vector<bool>> & visited)
{
    visited[x][y] = true;

    std::vector<std::pair<int, int>> shift{{0,1}, {0,-1}, {1,0}, {-1,0}};
    for(auto const next : shift)
    {
        int next_x = x + next.first;
        int next_y = y + next.second;

        if(next_x >= 0 and next_x < board.size() and
           next_y >= 0 and next_y < board[x].size() and 
           board[x][y] == 'W' && visited[x][y]==false)
            dfs(next_x, next_y, board, visited);
    }
}


void FillSurroundedRegions(vector<vector<char>>* board_ptr) {
  // TODO - you fill in here.
  auto & board = *board_ptr;
  if(board.empty())
      return;

  std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board.front().size(), false));

  const int n = board.size()-1;
  for(int j = 0; j<board[0].size(); ++j)
  {
      if(visited[0][j]==false and board[0][j] == 'W')
          dfs(0, j, board, visited);

      if(visited[n][j]==false and board[n][j] == 'W')
          dfs(n, j, board, visited);
  }

  for(int i = 0; i<=n; ++i)
  {
      if(visited[i][0]==false and board[i][0] == 'W')
          dfs(i, 0, board, visited);

      if(visited[i][n]==false and board[i][n] == 'W')
          dfs(i, n, board, visited);
  }


  for(int i=0; i<board.size(); ++i)
  {
      for(int j=0; j<board[i].size(); ++j)
      {
          if(visited[i][j]==false and board[i][j] == 'W')
              board[i][j] = 'B';
      }
  }
  return;
}
vector<vector<string>> FillSurroundedRegionsWrapper(
    TimedExecutor& executor, vector<vector<string>> board) {
  vector<vector<char>> char_vector;
  char_vector.resize(board.size());
  for (int i = 0; i < board.size(); i++) {
    for (const string& s : board[i]) {
      if (s.size() != 1) {
        throw std::runtime_error("String size is not 1");
      }
      char_vector[i].push_back(s[0]);
    }
  }

  executor.Run([&] { FillSurroundedRegions(&char_vector); });

  board.clear();
  board.resize(char_vector.size(), {});
  for (int i = 0; i < board.size(); i++) {
    for (char c : char_vector[i]) {
      board[i].emplace_back(1, c);
    }
  }

  return board;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "board"};
  return GenericTestMain(
      args, "matrix_enclosed_regions.cc", "matrix_enclosed_regions.tsv",
      &FillSurroundedRegionsWrapper, DefaultComparator{}, param_names);
}
