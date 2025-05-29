#include <bits/stdc++.h>
using namespace std;

int main (void) {
    list<char> li = {'d', 'm', 'i', 'h'};
    auto t = li.end();
    cout << (t == li.end()) << '\n';

    for (char x : li) {
        cout << x << ' ';
    }
}