#include <iostream>
using namespace std;

int main() {
    int c;
    cout << "Enter a character: ";
    cin >> c;
    // Use type casting operator (int) to convert the char to int
    char i = (char)c;
    cout << "The integer value of character " << c << " is " << i << endl;

    {int i{ 30000 };
    char d = i; // chars have range -128 to 127

    std::cout << static_cast<int>(d) << '\n';}

    {
        float f { 1.23456789 };
        printf("%f", f);
    }

    {
        int i { 62 };
        // explicit conversion from int to char, so that a char is assigned to variable ch
        char ch { static_cast<char>(i) };
        printf("%c", ch);
    }
    return 0;
}

// int main()
// {
//     int array[10000000]; // allocate 1 million integers (probably 4MB of memory)
//     cout << 1000; 
//     return 0;
// }

