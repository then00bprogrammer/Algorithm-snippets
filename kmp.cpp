#include <bits/stdc++.h>
using namespace std;

class SubstringSearch {
public:
  /**
   * Slow method of pattern matching
   */
  bool hasSubstring(string text, string pattern) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < text.size() && j < pattern.size()) {
      if (text[i] == pattern[j]) {
        ++i;
        ++j;
      } else {
        j = 0;
        ++k;
        i = k;
      }
    }
    return (j == pattern.size());
  }

  /**
   * Compute temporary array to maintain size of suffix which is same as prefix
   * Time/space complexity is O(size of pattern)
   */
  vector<int> computeTemporaryArray(string pattern) {
    vector<int> lps(pattern.size());
    int index = 0;
    for (int i = 1; i < pattern.size();) {
      if (pattern[i] == pattern[index]) {
        lps[i] = index + 1;
        ++index;
        ++i;
      } else {
        if (index != 0) {
          index = lps[index - 1];
        } else {
          lps[i] = 0;
          ++i;
        }
      }
    }
    return lps;
  }

  /**
   * KMP algorithm of pattern matching.
   */
  bool kmp(string text, string pattern) {
    vector<int> lps = computeTemporaryArray(pattern);
    int i = 0;
    int j = 0;
    while (i < text.size() && j < pattern.size()) {
      if (text[i] == pattern[j]) {
        ++i;
        ++j;
      } else {
        if (j != 0) {
          j = lps[j - 1];
        } else {
          ++i;
        }
      }
    }
    return (j == pattern.size());
  }
};

int main() {
  SubstringSearch ss;
  string str = "abcxabcdabcdabcy";
  string subString = "abcdabcy";
  bool result = ss.kmp(str, subString);
  cout << boolalpha << result << endl;
  return 0;
}
