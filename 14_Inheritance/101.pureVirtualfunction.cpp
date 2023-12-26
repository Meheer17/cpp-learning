#include <string>
#include <string_view>

class Animal
{
protected:
    std::string m_name{};

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name)
        : m_name{name}
    {
    }

public:
    const std::string &getName() const { return m_name; }
    virtual std::string_view speak() const { return "???"; }

    virtual ~Animal() = default;
};

class Cat : public Animal
{
public:
    Cat(std::string_view name)
        : Animal{name}
    {
    }

    std::string_view speak() const override { return "Meow"; }
};

class Dog : public Animal
{
public:
    Dog(std::string_view name)
        : Animal{name}
    {
    }

    std::string_view speak() const override { return "Woof"; }
};