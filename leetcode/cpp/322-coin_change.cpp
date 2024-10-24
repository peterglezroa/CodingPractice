/* 322. Coin Change
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 *
 * Return the fewest number of coins that you need to make up that amount. If
 * that amount of money cannot be made up by any combination of the coins,
 * return -1.
 *
 * You may assume that you have an infinite number of each kind of coin.
 *
 * Example 1:

 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 * Example 2:
 * Input: coins = [2], amount = 3
 * Output: -1
 *
 * Example 3:
 * Input: coins = [1], amount = 0
 * Output: 0
 * 
 * Constraints:
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 231 - 1
 * 0 <= amount <= 104
 */
#include<vector>
int coinChange(std::vector<int> &coins, int amount) {
  if (amount == 0) return 0;
  std::vector<int> dp = std::vector<int>(amount+1, -1);
  dp[0] = 0;
  for(int c : coins) if (c <= amount) dp[c] = 1;

  for (int i = 1; i <= amount; i++) {
    for (int c: coins)
      if (c <= i && i-c >= 0 && dp[i-c] != -1)
        dp[i] = (dp[i] == -1)? dp[i-c]: std::min(dp[i], dp[i-c]);
    if (dp[i] != -1) dp[i]++;
  }
  return dp[amount];
}