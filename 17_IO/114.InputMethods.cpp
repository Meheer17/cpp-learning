#include <iomanip>
#include <iostream>

int main()
{
    char ch;

    while (std::cin.get(ch))
        std::cout << ch;

    char buf[10];
    std::cin >> std::setw(10) >> buf;

    char strBuf[11];
    std::cin.get(strBuf, 11);
    std::cout << strBuf << '\n';
    {
        char strBuf[11];
        // Read up to 10 characters
        std::cin.get(strBuf, 11);
        std::cout << strBuf << '\n';

        // Read up to 10 more characters
        std::cin.get(strBuf, 11);
        std::cout << strBuf << '\n';
    }

    {
        char strBuf[100];
        std::cin.getline(strBuf, 100);
        std::cout << strBuf << '\n';
        std::cout << std::cin.gcount() << " characters were read" << '\n';
    }

    {
        std::string strBuf;
        std::getline(std::cin, strBuf);
        std::cout << strBuf << '\n';
    }

    return 0;
}