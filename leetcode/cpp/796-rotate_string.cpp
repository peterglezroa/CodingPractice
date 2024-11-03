/* 796. Rotate String
 * Given two strings s and goal, return true if and only if s can become goal
 * after some number of shifts on s.
 * 
 * A shift on s consists of moving the leftmost character of s to the rightmost
 * position.
 * 
 * For example, if s = "abcde", then it will be "bcdea" after one shift.
 *  
 *
 * Example 1:
 * Input: s = "abcde", goal = "cdeab"
 * Output: true
 *
 * Example 2:
 * Input: s = "abcde", goal = "abced"
 * Output: false
 * 
 * Constraints:
 * 1 <= s.length, goal.length <= 100
 * s and goal consist of lowercase English letters.
 */
#include<string>

class Solution {
    bool rotateString(std::string s, std::string goal) {
        if (s.length() != goal.length()) return false;

        int sIndx, gIndx = 0, startAt = 0;

    findMatching:
        for (; startAt < s.length() && s[startAt] != goal[gIndx]; startAt++) {}
        if (startAt == s.length()) return false;

        gIndx++;
        for (sIndx = startAt+1; gIndx++ < goal.length(); gIndx++) {
            if (goal[gIndx] != s[sIndx%s.length()]) {
                gIndx++;
                startAt++;
                goto findMatching;
            }
            sIndx++;
        }
        return true;
    }
}
