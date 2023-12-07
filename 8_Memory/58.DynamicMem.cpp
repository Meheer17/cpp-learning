#include <iostream>
using namespace std;

int Dangling()
{
    int* ptr{ new int }; // dynamically allocate an integer
    *ptr = 7; // put a value in that memory location

    delete ptr; // return the memory to the operating system.  ptr is now a dangling pointer.

    std::cout << *ptr; // Dereferencing a dangling pointer will cause undefined behavior
    delete ptr; // trying to deallocate the memory again will also lead to undefined behavior.

    return 0;
}

int Danger()
{
    int* ptr{ new int{} }; // dynamically allocate an integer
    int* otherPtr{ ptr }; // otherPtr is now pointed at that same memory location

    delete ptr; // return the memory to the operating system.  ptr and otherPtr are now dangling pointers.
    ptr = nullptr; // ptr is now a nullptr

    // however, otherPtr is still a dangling pointer!

    return 0;
}

int main()
{
    int *x{new int};
    *x = 7;
    cout << x << " " << *x << "\n"; 
    
    int* ptr1{ new int (5) }; // use direct initialization 
    int* ptr2{ new int { 6 } }; // use uniform initialization
    
    int* value { new (std::nothrow) int{} }; // ask for an integer's worth of memory
    if (!value) // handle case where new returned null
    {
        // Do error handling here
        std::cerr << "Could not allocate memory\n";
    }

    // assume ptr has previously been allocated with operator new
    delete ptr1; // return the memory pointed to by ptr to the operating system
    ptr1 = nullptr; // set ptr to be a null pointer
    delete ptr2;
    ptr2 = nullptr;

    // Memory Leaks Handle
    {
        int value{ 5 };
        int* ptr{ new int{} }; // allocate memory
        delete ptr; // return memory back to operating system
        ptr = &value;
    } // reassign pointer to address of value

    Dangling();
    Danger();
    return 0;
}