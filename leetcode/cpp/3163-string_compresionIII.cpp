/* 3163. String Compression III
 * Given a string word, compress it using the following algorithm:
 * 
 * Begin with an empty string comp. While word is not empty, use the following
 * operation:
 * Remove a maximum length prefix of word made of a single character c
 * repeating at most 9 times.
 * Append the length of the prefix followed by c to comp.
 * Return the string comp.
 * 
 * Example 1:
 * Input: word = "abcde"
 * Output: "1a1b1c1d1e"
 * Explanation:
 * Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c",
 * "d", and "e" as the prefix in each operation.
 * For each prefix, append "1" followed by the character to comp.
 * 
 * Example 2:
 * Input: word = "aaaaaaaaaaaaaabb"
 * Output: "9a5a2b"
 * Explanation:
 * Initially, comp = "". Apply the operation 3 times, choosing "aaaaaaaaa",
 * "aaaaa", and "bb" as the prefix in each operation.
 * 
 * For prefix "aaaaaaaaa", append "9" followed by "a" to comp.
 * For prefix "aaaaa", append "5" followed by "a" to comp.
 * For prefix "bb", append "2" followed by "b" to comp.
 *  
 * 
 * Constraints:
 * 1 <= word.length <= 2 * 105
 * word consists only of lowercase English letters.
 */
#include<string>

class Solution {
public:
    std::string compressedString(std::string word) {
        char cur = 0;
        int amount = 0;
        std::string res = "";
        for (char c : word) {
            if (c == cur) {
                if (amount >= 9) {
                    res += std::to_string(amount)+cur;
                    amount = 1;
                } else amount++;
            } else {
                if (amount)
                    res += std::to_string(amount)+cur;
                cur = c;
                amount = 1;
            }
        }
        res += std::to_string(amount) + cur;
        return res;
    }
};
