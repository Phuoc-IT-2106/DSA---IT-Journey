#include <iostream>
#include <vector>
#include <random>

int main() {
    // Seed with a real random value, if available
    std::random_device rd;
    // Initialize Mersenne Twister pseudo-random number generator
    std::mt19937 gen(rd());
    // Define the range [1, 100]
    std::uniform_int_distribution<> dis(1, 100);

    std::cout << "Generating 10 random numbers between 1 and 100:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << dis(gen) << " ";
    }
    std::cout << std::endl;

    return 0;
}
