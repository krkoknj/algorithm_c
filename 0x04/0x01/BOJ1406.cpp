#include <bits/stdc++.h>
using namespace std;

void printList(const list<char>& L, list<char>::const_iterator it) {
    cout << "리스트 원소 : [";
    for (char c : L) {
        cout << c;
    }
    cout << "]" << '\n';

      // 2) 위치(인덱스) 계산: begin()으로부터의 거리
      auto idx = distance(L.begin(), it);
      cout << "it 위치 인덱스: " << idx;
  
      // 3) it가 끝(end)이 아니면, *it도 출력
      if (it != L.end())
          cout << ", *it = '" << *it << "'";
      else
          cout << " (it == end())";
      cout << "\n\n";
}


int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string S;
    cin >> S;
    
    list<char> L(S.begin(), S.end());
    auto it = L.end();
    int M;
    cin >> M;
    cin.ignore();

    string line;
    while (M--) {
        getline(cin, line);
        char cmd = line[0];

        if (cmd == 'P') {
            char x = line[2];
            L.insert(it, x);
            printList(L, it);
        }
        else if (cmd == 'L') {
            if (L.begin() != it) {
                --it;
                printList(L, it);
            };
        }
        else if (cmd == 'D') {
            if (L.end() != it){ 
                ++it;
                printList(L, it);
            };
        }
        else if (cmd == 'B') {
            if (L.begin() != it) {
                it--;
                it = L.erase(it);
                printList(L, it);
            }
                
        }
    }

    for (char c : L) {
        cout << c;
    }

    return 0;
}


