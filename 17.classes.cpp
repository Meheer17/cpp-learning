// Member function version
#include <iostream>

// struct Date
// {
//     int m_year {};
//     int m_month {};
//     int m_day {};

//     void print() // defines a member function named print
//     {
//         std::cout << m_year << '/' << m_month << '/' << m_day;
//     }
// };

// int main()
// {
//     Date today { 2020, 10, 14 }; // aggregate initialize our struct

//     today.m_day = 16; // member variables accessed using member selection operator (.)
//     today.print();  // member functions also accessed using member selection operator (.)

//     return 0;
// }

class Date
{
// Any members defined here would default to private

public: // here's our public access specifier

    void print() const // public due to above public: specifier
    {
        // members can access other private members
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }

private: // here's our private access specifier

    int m_year { 2020 };  // private due to above private: specifier
    int m_month { 14 }; // private due to above private: specifier
    int m_day { 10 };   // private due to above private: specifier
};

int main()
{
    Date d{};
    d.print();  // okay, main() allowed to access public members

    return 0;
}