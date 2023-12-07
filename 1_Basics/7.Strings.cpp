#include <string>
#include <iostream>
#include <string_view>


using namespace std;

void printSV(std::string_view str) // now a std::string_view
{
    std::cout << str << '\n';
}

int main()
{
    string name {"Meheer"};
    cout << name + '\n';

    cout << "Enter a single word name: ";
    cin >> name;
    cout << name + '\n';

    cout << "Enter a Multi word name: ";
    getline(cin >> ws, name); // read a full line of text into name
    cout << name + '\n';

    cout << name.length() << endl;

    // All these make a copy of the string and its costly 

    //Below this are where no copies are made.
    std::string_view s{ "Hello, world!" }; // now a std::string_view
    printSV(s);

    return 0;
}