/* 36. Valid Sudoku
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
 * without repetition.
 *
 * Note:
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned rules.
 *  
 * 
 * Example 1:
 * Input: board = 
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: true
 *
 * Example 2:
 * Input: board = 
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: false
 *
 * Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 * 
 * Constraints:
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit 1-9 or '.'.
 */
#include<bitset>
#include<vector>

bool isValidSudoku(std::vector<std::vector<char>> &board) {
  std::vector<std::bitset<9>> boxCheck = std::vector<std::bitset<9>>(9, std::bitset<9>());
  std::vector<std::bitset<9>> colCheck = std::vector<std::bitset<9>>(9, std::bitset<9>());
  std::bitset<9> rowCheck;
  for (int row = 0; row < 9; row++) {
    rowCheck.reset();
    int num, boxIndex;
    for (int col = 0; col < 9; col++) {
      if (board[row][col] == '.') continue;
      else num = board[row][col]-'0';
      boxIndex = (row/3)+(col/3)*3;

      if (rowCheck[num] || colCheck[col][num] || boxCheck[boxIndex][num])
        return false;
      rowCheck[num] = 1;
      colCheck[col][num] = 1;
      boxCheck[boxIndex][num] = 1;
    }
  }
  return true;
}
