
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol54
{

  class Solution
  {
  private:
    bool _search(int x, int y, string &word, int index, vector<vector<char>> &board);

  public:
    bool exist(vector<vector<char>> &board, string word);
  };
}
#endif