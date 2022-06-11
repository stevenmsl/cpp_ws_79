#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol54;

/*
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

tuple<vector<vector<char>>>
testFixture1()
{
  auto input = vector<vector<char>>{
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}};

  return make_tuple(input);
}

void test1()
{
  auto f = testFixture1();
  auto board = get<0>(f);
  Solution sol;

  cout << "Expect to see 1: " << sol.exist(board, "ABCCED") << endl;
  cout << "Expect to see 1: " << sol.exist(board, "SEE") << endl;
  cout << "Expect to see 0: " << sol.exist(board, "ABCB") << endl;
}

main()
{
  test1();
  return 0;
}