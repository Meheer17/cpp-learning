#include <iostream>
#include <vector>

int main()
{
    std::vector<int> data( 10 ); // vector containing 10 int elements, value-initialized to 0
    
    std::vector primes { 2, 3, 5, 7, 11 }; // hold the first 5 prime numbers (as int)

    std::cout << "The first prime number is: " << primes[0] << '\n';
    std::cout << "The second prime number is: " << primes[1] << '\n';
    std::cout << "The sum of the first 5 primes is: " << primes[0] + primes[1] + primes[2] + primes[3] + primes[4] << '\n';

    {
        std::vector primes { 2, 3, 5, 7, 11 }; // hold the first 5 prime numbers (as int)

        std::cout << "An int is " << sizeof(int) << " bytes\n";
        std::cout << &(primes[0]) << '\n';
        std::cout << &(primes[1]) << '\n';
        std::cout << &(primes[2]) << '\n';

    }

    return 0;
}