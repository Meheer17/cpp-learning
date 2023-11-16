#include <array>
#include <iostream>
#include <string_view>

namespace Animal
{
    enum Type
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals
    };

    struct Data
    {
        std::string_view name{};
        int legs{};
        std::string_view sound{};
    };

    constexpr std::array types { chicken, dog, cat, elephant, duck, snake };
    constexpr std::array<Data, max_animals> data {{
        { "chicken",    2, "cluck" },
        { "dog",        4, "woof" },
        { "cat",        4, "meow" },
        { "elephant",   4, "pawoo" },
        { "duck",       2, "quack" },
        { "snake",      0, "hissss" },
    }};

    static_assert(std::size(types) == max_animals);
    static_assert(std::size(data) == max_animals);
}

// Teach operator>> how to input an Animal by name
// Consider this magic for now
// We pass color by non-const reference so we can have the function modify its value
std::istream& operator>> (std::istream& in, Animal::Type& animal)
{
    std::string input {};
    std::getline(in >> std::ws, input);

    // See if we can find a match
    for (std::size_t index=0; index < Animal::data.size(); ++index)
    {
        if (input == Animal::data[index].name)
        {
            animal = static_cast<Animal::Type>(index);
            return in;
        }
    }

    // We didn't find a match, so input must have been invalid
    // so we will set input stream to fail state
    in.setstate(std::ios_base::failbit);
    return in;
}

void printAnimalData(Animal::Type type)
{
    const Animal::Data& animal { Animal::data[type] };
    std::cout << "A " << animal.name << " has " << animal.legs << " legs and says " << animal.sound << ".\n";
}

int main()
{
    std::cout << "Enter an animal: ";
    Animal::Type type{};
    std::cin >> type;

    // If users input didn't match
    if (!std::cin)
    {
        std::cin.clear();
        std::cout << "That animal couldn't be found.\n";
        type = Animal::max_animals; // set to invalid option so we don't match below
    }
    else
        printAnimalData(type);


    std::cout << "\nHere is the data for the rest of the animals:\n";
    for (auto a : Animal::types)
    {
        if (a != type)
            printAnimalData(a);
    }

    return 0;
}