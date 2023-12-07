#include <iostream>

int main()
{
    int x { 5 }; // normal integer variable
    int& ref { x }; // ref is now an alias for variable x
    std::cout << x << ref << '\n'; // print 55
    x = 6; // x now has value 6
    std::cout << x << ref << '\n'; // prints 66
    ref = 7; // the object being referenced (x) now has value 7
    std::cout << x << ref << '\n'; // prints 77

    {
        int x { 5 };
        int& ref { x }; // valid: lvalue reference bound to a modifiable lvalue
        const int y { 5 };
        // int& invalidRef { y };  // invalid: can't bind to a non-modifiable lvalue
        // int& invalidRef2 { 0 }; // invalid: can't bind to an rvalue
    }

    return 0;
}