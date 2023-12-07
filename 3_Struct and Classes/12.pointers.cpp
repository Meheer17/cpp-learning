#include <iostream>

using namespace std;

int main()
{
    int x { 5 };    // normal variable
    int& ref { x }; // a reference to an integer (bound to x)
    int* ptr { &x } ;       // a pointer to an integer
    cout << x << "\n" << ref << "\n" << &ptr << "\n" << ptr;

    {
       int x{ 5 };
       int* ptr{ &x }; // initialize ptr with address of variable x

       std::cout << x << '\n';    // print x's value
       std::cout << *ptr << '\n'; // print the value at the address that ptr is holding (x's address)

       *ptr = 6; // The object at the address held by ptr (x) assigned value 6 (note that ptr is dereferenced here)

       std::cout << x << '\n';
       std::cout << *ptr << '\n'; // print the value at the address that ptr is holding (x's address)

    }

    {
        int v{ 5 };

        int* ptr0 { &v };             // points to an "int" but is not const itself, so this is a normal pointer.
        const int* ptr1 { &v };       // points to a "const int" but is not const itself, so this is a pointer to a const value.
        int* const ptr2 { &v };       // points to an "int" and is const itself, so this is a const pointer (to a non-const value).
        const int* const ptr3 { &v }; // points to an "const int" and is const itself, so this is a const pointer to a const value.

        // if the const is on the left side of the *, the const belongs to the value
        // if the const is on the right side of the *, the const belongs to the pointer

    }   

    return 0;
}