#include <bits/stdc++.h>
using namespace std;

int main (void) {
    int N = 4;
    int arr[N] = {4, 13, 63, 87};
    int arr2[101] = {};

    for (int i = 0; i < N; i++) {
        if (arr2[100 - arr[i]]) {
            cout << i << "\n";
        }
        arr2[arr[i]] = 1;
    }


    for (int a : arr2) {
        cout << a << ' ';
    }
    return 0;
}