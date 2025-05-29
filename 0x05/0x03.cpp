#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;               // 첫째 줄에 명령 개수 입력

    stack<int> S;
    while (N--) {           // N번 반복(명령을 모두 처리하면 종료)
        string cmd;
        cin >> cmd;         // 명령어 읽기

        if (cmd == "push") {
            int x;
            cin >> x;       // push일 때만 추가 정수 읽기
            S.push(x);
        }
        else if (cmd == "pop") {
            if (S.empty()) {
                cout << -1 << "\n";
            } else {
                cout << S.top() << "\n";
                S.pop();
            }
        }
        else if (cmd == "size") {
            cout << S.size() << "\n";
        }
        else if (cmd == "empty") {
            cout << S.empty() << "\n";
        }
        else if (cmd == "top") {
            if (S.empty()) {
                cout << -1 << "\n";
            } else {
                cout << S.top() << "\n";
            }
        }
    }

    return 0;
}
