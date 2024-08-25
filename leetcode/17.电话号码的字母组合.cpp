/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start

// 官方题解
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> combinations;
    if (digits.empty()) {
      return combinations;
    }
    unordered_map<char, string> phoneMap{{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                                         {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    string combination;
    backtrack(combinations, phoneMap, digits, 0, combination);
    return combinations;
  }

  void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap,
                 const string& digits, int index, string& combination) {
    if (index == digits.length()) {
      combinations.push_back(combination);  // 已经到底，将当前组合推入结果
    } else {
      char digit = digits[index];
      const string& letters = phoneMap.at(digit);
      for (const char& letter : letters) {  // 迭代当前的每一个字母
        combination.push_back(letter);      // 推入当前字母
        backtrack(combinations, phoneMap, digits, index + 1, combination);
        combination.pop_back();  // 弹出当前字母
      }
    }
  }
};

// 回溯
// @lc code=end

class Solution3 {
 private:
  std::map<char, string> dailmap{
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
  };

 public:
  vector<string> traceback(string digits, int L, vector<string> prefix) {
    vector<string> res;
    if (L >= digits.size()) {
      return prefix;
    } else {
      vector<string> curprefix;
      for (string p : prefix) {
        for (char c : dailmap[digits[L]]) {
          curprefix.push_back(p + c);
        }
      }
      return traceback(digits, L + 1, curprefix);
    }
  }
  vector<string> letterCombinations(string digits) {
    vector<string> prefix(0);
    if (digits.size() == 0) {
      return prefix;
    }
    for (char c : dailmap[digits[0]]) {
      string s{c};
      prefix.push_back(std::move(s));
    }
    return traceback(digits, 1, prefix);
  }
};

class Solution2 {
 private:
  std::map<char, string> dailmap{
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
  };

 public:
  vector<string> letterCombinations(string digits) {
    vector<string> tvec(0);
    vector<string> rvec(0);
    for (char d : digits) {
      if (rvec.empty()) {
        for (char c : dailmap[d]) {
          string s{c};
          rvec.push_back(std::move(s));
        }
      } else {
        tvec = rvec;
        rvec.clear();
        for (string s : tvec) {
          for (char c : dailmap[d]) {
            rvec.push_back(s + c);
          }
        }
      }
    }
    return rvec;
  }
};

int main() {
  Solution s;
  vector<string> r = s.letterCombinations("23");
  return 0;
}
