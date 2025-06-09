#include <bits/stdc++.h>
using namespace std;
  stack<int> S;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N; // 첫째 줄에 명령 개수 입력
  while (N--) {
    int cmd;
    cin >> cmd;

    if (cmd == 0) {
      S.pop();
    } else {
      S.push(cmd);
    }

  }

  int sum = 0;
  while (!S.empty()) {
    int x = S.top();
    sum += x;
    S.pop();
  }

  cout << "sum=" <<sum << " ";
  
}
