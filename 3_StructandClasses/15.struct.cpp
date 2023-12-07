#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

struct Something
{
    int x;       // no default initialization value (bad)
    int y {};    // value-initialized by default
    int z { 2 }; // explicit default value
};

int main()
{
    Employee joe {};
    joe.id = 14;
    joe.age = 32;
    joe.wage = 60000.0;
    // Employee joe { 14, 32, 60000.0} OR Employee joe { .id = 14 or .id { 14 }}

    Employee frank {};
    frank.id = 15;
    frank.age = 28;
    frank.wage = 45000.0;

    int totalAge { joe.age + frank.age };

    if (joe.wage > frank.wage)
        std::cout << "Joe makes more than Frank\n";
    else if (joe.wage < frank.wage)
        std::cout << "Joe makes less than Frank\n";
    else
        std::cout << "Joe and Frank make the same amount\n";

    // Frank got a promotion
    frank.wage += 5000.0;

    // Today is Joe's birthday
    ++joe.age; // use pre-increment to increment Joe's age by 1


    {
        Something s1;             // No initializer list: s1.x is uninitialized, s1.y and s1.z use defaults
        Something s2 { 5, 6, 7 }; // Explicit initializers: s2.x, s2.y, and s2.z use explicit values (no default values are used)
        Something s3 {};          // Missing initializers: s3.x is value initialized, s3.y and s3.z use defaults
    }

    return 0;
}