#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol54;
using namespace std;

/*takeaways
  - start from each location on the board
    and perform a DFS to find the word
  - time complexity O(m*n*4^l)
  - space complexity O(m*n + l)
    - m*n if we count the board
    - the recursive call is at most l level
*/

bool Solution::exist(vector<vector<char>> &board, string word)
{
  auto h = board.size(), w = board[0].size();

  for (auto i = 0; i < h; i++)
    for (auto j = 0; j < w; j++)
      if (_search(j, i, word, 0, board))
        return true;

  return false;
}
/* DFS search */
bool Solution::_search(int x, int y, string &word, int index, vector<vector<char>> &board)
{
  auto h = board.size(), w = board[0].size();
  /* word[index] != board[y][x] also covers the case
     where the node has been visited during this round
     of search
  */
  if (x < 0 || y < 0 || x == w || y == h || word[index] != board[y][x])
    return false;

  if (index == word.size() - 1)
    return true;
  /* visiting neighbors */
  auto c = board[y][x];
  board[y][x] = '*';
  auto result = _search(x, y - 1, word, index + 1, board) ||
                _search(x, y + 1, word, index + 1, board) ||
                _search(x - 1, y, word, index + 1, board) ||
                _search(x + 1, y, word, index + 1, board);

  board[y][x] = c;
  return result;
}