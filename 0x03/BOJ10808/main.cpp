#include <bits/stdc++.h>
using namespace std;

int main (void) {
    char alphabet[] = "baekjoon";
    int arr[26] = {};
    for (int a : alphabet) {
        arr[a - 97] += 1;
    }

    for (int a : arr) {
        cout << a << ' ';
    }
    return 0;
}