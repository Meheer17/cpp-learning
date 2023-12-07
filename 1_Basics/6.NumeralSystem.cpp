#include <iostream>
#include <bitset> // for std::bitset
#include <format> // C++20
// #include <print> // C++23

using namespace std;


int bit()
{
	// std::bitset<8> means we want to store 8 bits
	std::bitset<8> bin1{ 0b1100'0101 }; // binary literal for binary 1100 0101
	std::bitset<8> bin2{ 0xC5 }; // hexadecimal literal for binary 1100 0101

	std::cout << bin1 << '\n' << bin2 << '\n';
	std::cout << std::bitset<4>{ 0b1010 } << '\n'; // create a temporary std::bitset and print it

	return 0;
}

int print()
{
    int x { 12 };
    std::cout << x << '\n'; // decimal (by default)
    std::cout << std::hex << x << '\n'; // hexadecimal
    std::cout << x << '\n'; // now hexadecimal
    std::cout << std::oct << x << '\n'; // octal
    std::cout << std::dec << x << '\n'; // return to decimal
    std::cout << x << '\n'; // decimal

    return 0;
}

int binprint()
{
    // std::bitset<8> means we want to store 8 bits
	std::bitset<8> bin1{ 0b1100'0101 }; // binary literal for binary 1100 0101
	std::bitset<8> bin2{ 0xC5 }; // hexadecimal literal for binary 1100 0101

	std::cout << bin1 << '\n' << bin2 << '\n';
	std::cout << std::bitset<4>{ 0b1010 } << '\n'; // create a temporary std::bitset and print it

    return 0;
}

// int formated()
// {
//     // std::cout << std::format("{:b}\n", 0b1010); // C++20
//     // std::cout << std::format("{:#b}\n", 0b1010); // C++20

//     // std::print("{:b} {:#b}\n", 0b1010, 0b1010); // C++23

//     return 0;

// }

int main()
{
    int o{ 012 }; // 0 before the number means this is octal
    cout << o << '\n';

    int h{ 0xF }; // 0x before the number means this is hexadecimal
    std::cout << h << '\n';

    int vbin{};        // assume 16-bit ints
    vbin = 0b1;        // assign binary 0000 0000 0000 0001 to the variable
    vbin = 0b11;       // assign binary 0000 0000 0000 0011 to the variable
    vbin = 0b1010;     // assign binary 0000 0000 0000 1010 to the variable
    vbin = 0b11110000; // assign binary 0000 0000 1111 0000 to the variable

    int bin { 0b1011'0010 };  // assign binary 1011 0010 to the variable
    long value { 2'132'673'462 }; // much easier to read than 2132673462
    
    bit();
    print();
    binprint();
    // formated();

    return 0;
}