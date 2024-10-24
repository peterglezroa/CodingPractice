/* 347. Top K Frequent Elements
 * Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 * 
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 *
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * Constraints:
 * 1 <= nums.length <= 105
 * -104 <= nums[i] <= 104
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 * 
 * Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */
#include<unordered_map>
#include<vector>
#include<queue>

std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
  std::unordered_map<int, int> counter;
  for (int num: nums) {
    if (counter.contains(num)) counter[num]++;
    else counter[num] = 1;
  }

  std::priority_queue<std::pair<int, int>> indexHeap;
  for (const std::pair<int, int> &pair : counter)
    indexHeap.push({ pair.second, pair.first });
  std::vector<int> result;
  for (int i = 0; i < k && !indexHeap.empty(); ++i) {
    result.push_back(indexHeap.top().second);
    indexHeap.pop();
  }
  return result;
}