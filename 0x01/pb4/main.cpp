#include <iostream>

int main () {
    int N = 2;
    int result = 1;

    for (int i = N / 2; i > 0; i = i / 2) { //O(log n)
        result = result * 2;
    }

    std::cout << "The result is: " << result << std::endl; 
    
    return 0;
}