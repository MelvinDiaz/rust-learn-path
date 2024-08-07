#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> dp(n + 1, INT_MAX);
  dp[1] = 1;

  for (int k = 2; k <= n; ++k) {
    for (int l = 1; l <= k / 2; ++l) {
      dp[k] = min(dp[k], dp[k - l] + dp[l]);
    }
    for (int l = 2; l <= sqrt(k); ++l) {
      if (k % l == 0) {
        dp[k] = min(dp[k], dp[k / l] + dp[l]);
      }
    }
    string s = to_string(k);
    for (size_t i = 0; i < s.size() - 1; ++i) {
      if (s[i + 1] != '0') {
        dp[k] = min(dp[k],
                    dp[stoi(s.substr(0, i + 1))] + dp[stoi(s.substr(i + 1))]);
      }
    }
  }

  cout << dp[n] << endl;

  return 0;
}
