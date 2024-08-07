#include <bits/stdc++.h>
using namespace std;

void bottomUpCutRod(vector<int> &p, int n, vector<int> &r, vector<int> &s){
  r.resize(n+1);
  s.resize(n+1);
  r[0] = 0;
  for(int j = 1; j <= n; j++){
    int q = INT_MIN;
    for (int i = 1; i <= j; ++i) {
      if(q < p[i-1] + r[j-i]){
        q = p[i-1] + r[j-i];
        s[j] = i;
      }
    }
    r[j] = q;
  }
}

int main () {

  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> r;
  vector<int> s;

  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  bottomUpCutRod(p, n, r, s);

  cout << r[n] << endl;
  return 0;
}
