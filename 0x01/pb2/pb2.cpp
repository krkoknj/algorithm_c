#include <iostream>

int main () {
    int n = 4;
    int arr[n] = {4, 13, 63, 87};

    for (int i=0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { //O(n^2)
            if (arr[i] + arr[j] == 100) {
                std::cout << 1 << std::endl;
            } else {
                std::cout << 0 << std::endl;
            }
        }
    }

    return 0;
}