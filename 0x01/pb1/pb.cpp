#include <iostream>
int main () {
    int n = 10000;
    int result = 0;
    for (int i = 0; i < n; i++) { //O(n)
        if (i % 3 == 0 || i % 5 == 0) {
            result += i;
        }
    }

    std::cout << "The sum of all multiples of 3 or 5 below " << n << " is: " << result << std::endl;
    return 0;
}