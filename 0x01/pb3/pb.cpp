#include <iostream>

int main () {

    int n = 9;

    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) {
            std::cout << 1 << std::endl; //O(n)
        } else {
            std::cout << 0 << std::endl;
        }
    }

    return 0;
}