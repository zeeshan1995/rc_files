#include <deque>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::deque;
using std::vector;

bool PathElementIsFeasible(int x, int y, bool type, vector<deque<bool>>& image_ptr)
{
  if (!(0 <= x && x < image_ptr.size() && 0 <= y &&
        y < image_ptr[x].size() && image_ptr[x][y] == type)) {
    return false;
  }
  return true;
}


void FlipColor(int x, int y, vector<deque<bool>>& image_ptr) {
  // TODO - you fill in here.
  image_ptr[x][y] = !image_ptr[x][y];
  std::vector<std::pair<int, int>> shift = {{0,-1}, {0,1}, {-1,0}, {1,0}};

  for(auto s : shift)
  {
      int next_x = s.first + x, next_y = s.second + y;
      if(PathElementIsFeasible(next_x, next_y, !image_ptr[x][y], image_ptr))
          FlipColor(next_x, next_y, image_ptr);
  }
  return;
}

vector<vector<int>> FlipColorWrapper(TimedExecutor& executor, int x, int y,
                                     vector<vector<int>> image) {
  vector<deque<bool>> b;
  b.reserve(image.size());
  for (const vector<int>& row : image) {
    deque<bool> tmp;
    tmp.resize(row.size());
    for (int i = 0; i < row.size(); ++i) {
      tmp[i] = static_cast<bool>(row[i]);
    }
    b.push_back(tmp);
  }

  executor.Run([&] { FlipColor(x, y, b); });

  image.resize(b.size());

  for (int i = 0; i < image.size(); ++i) {
    image[i].resize(b.size());
    for (int j = 0; j < image[i].size(); ++j) {
      image[i][j] = b[i][j];
    }
  }
  return image;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "x", "y", "image"};
  return GenericTestMain(args, "matrix_connected_regions.cc", "painting.tsv",
                         &FlipColorWrapper, DefaultComparator{}, param_names);
}
