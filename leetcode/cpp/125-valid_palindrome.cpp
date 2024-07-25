/* 125. Valid Palindrome
 * A phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads the
 * same forward and backward. Alphanumeric characters include letters and
 * numbers.
 *
 * Given a string s, return true if it is a palindrome, or false otherwise.
 * 
 * Example 1:
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 *
 * Example 2:
 * Input: s = "race a car"
 * Output: false
 *
 * Example 3:
 * Input: s = " "
 * Output: true
 */
#include <string>
#include <ctype.h>


bool isPalindrome(std::string s) {
  if (s.length() == 0) return false;
  std::string::iterator back=s.begin(), front=s.end()-1;
  char b, f;
  while(back < front) {
    if (!isalpha(*back) && !isdigit(*back)) {
      back++;
      continue;
    }

    if (!isalpha(*front) && !isdigit(*front)) {
      front--;
      continue;
    }

    if(tolower(*back) != tolower(*front)) return false;
    back++; front--;
  }
  return true;
}
