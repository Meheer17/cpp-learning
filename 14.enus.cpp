#include <iostream>

enum Pet
{
    cat, // assigned 0
    dog, // assigned 1
    pig, // assigned 2
    whale, // assigned 3
};

// Consider this magic for now
// We pass pet by reference so we can have the function modify its value
std::istream& operator>> (std::istream& in, Pet& pet)
{
    int input{};
    in >> input; // input an integer

    pet = static_cast<Pet>(input);
    return in;
}
enum Color
{
    black,
    red,
    blue,
};

int main()
{
    Pet myPet { cat }; // { black } compile error: black is not an enumerator of Pet
    Color shirt { black }; // { pig } compile error: pig is not an enumerator of Color

    {
        std::cout << "Enter a pet (0=cat, 1=dog, 2=pig, 3=whale): ";
        int input{};
        std::cin >> input; // input an integer
        Pet pet{ static_cast<Pet>(input) }; // static_cast our integer to a Pet
    }

    { // MAGIC CODE
        std::cout << "Enter a pet (0=cat, 1=dog, 2=pig, 3=whale): ";
        Pet pet{};
        std::cin >> pet; // input our pet using std::cin
        std::cout << pet << '\n'; // prove that it worked
    }

    {
        enum class Color
        {
            red,
            blue,
        };

        Color shirt { Color::red };

        if (shirt == Color::red) // this Color to Color comparison is okay
            std::cout << "The shirt is red!\n";
        else if (shirt == Color::blue)
            std::cout << "The shirt is blue!\n";
    }


    {
        enum class Color
        {
            red,
            blue,
        };

        Color color { Color::blue };

        // std::cout << color << '\n'; // won't work, because there's no implicit conversion to int
        std::cout << static_cast<int>(color) << '\n';   // explicit conversion to int, will print 1
        // std::cout << std::to_underlying(color) << '\n'; // convert to underlying type, will print 1 (C++23)
    }


    return 0;
}