#include <iostream>

int main() {

    {
        std::stringstream os;
        os << "en garde!\n"; // insert "en garde!" into the stringstream
    }

    {
        std::stringstream os;
        os.str("en garde!"); // set the stringstream buffer to "en garde!"
    }

    {
        std::stringstream os;
        os << "12345 67.89\n";
        std::cout << os.str();
    } 

    {
        std::stringstream os;
        os << "12345 67.89"; // insert a string of numbers into the stream

        std::string strValue;
        os >> strValue;

        std::string strValue2;
        os >> strValue2;

        // print the numbers separated by a dash
        std::cout << strValue << " - " << strValue2 << '\n';
    }

    return 0;
}