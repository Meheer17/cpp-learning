#include <iostream>
#include <iomanip>

int main() {
    std::cout.setf(std::ios::showpos); // turn on the std::ios::showpos flag
    std::cout << 27 << '\n';

    std::cout.setf(std::ios::showpos | std::ios::uppercase); // turn on the std::ios::showpos and std::ios::uppercase flag
    std::cout << 1234567.89f << '\n';

    std::cout.setf(std::ios::showpos); // turn on the std::ios::showpos flag
    std::cout << 27 << '\n';
    std::cout.unsetf(std::ios::showpos); // turn off the std::ios::showpos flag
    std::cout << 28 << '\n';

    std::cout.unsetf(std::ios::dec); // turn off decimal output
    std::cout.setf(std::ios::hex);   // turn on hexadecimal output
    std::cout << 27 << '\n';

    std::cout << std::hex << 27 << '\n'; // print 27 in hex
    std::cout << 28 << '\n';             // we're still in hex
    std::cout << std::dec << 29 << '\n'; // back to decimal

    std::cout << true << ' ' << false << '\n';
    std::cout.setf(std::ios::boolalpha);
    std::cout << true << ' ' << false << '\n';
    std::cout << std::noboolalpha << true << ' ' << false << '\n';
    std::cout << std::boolalpha << true << ' ' << false << '\n';

    {
        std::cout << std::fixed << '\n';
        std::cout << std::setprecision(3) << 123.456 << '\n';
        std::cout << std::setprecision(4) << 123.456 << '\n';
        std::cout << std::setprecision(5) << 123.456 << '\n';
        std::cout << std::setprecision(6) << 123.456 << '\n';
        std::cout << std::setprecision(7) << 123.456 << '\n';

        std::cout << std::scientific << '\n';
        std::cout << std::setprecision(3) << 123.456 << '\n';
        std::cout << std::setprecision(4) << 123.456 << '\n';
        std::cout << std::setprecision(5) << 123.456 << '\n';
        std::cout << std::setprecision(6) << 123.456 << '\n';
        std::cout << std::setprecision(7) << 123.456 << '\n';
    }

    {
        std::cout << -12345 << '\n';                                   // print default value with no field width
        std::cout << std::setw(10) << -12345 << '\n';                  // print default with field width
        std::cout << std::setw(10) << std::left << -12345 << '\n';     // print left justified
        std::cout << std::setw(10) << std::right << -12345 << '\n';    // print right justified
        std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified
    }

    {
        std::cout.fill('*');
        std::cout << -12345 << '\n';                                   // print default value with no field width
        std::cout << std::setw(10) << -12345 << '\n';                  // print default with field width
        std::cout << std::setw(10) << std::left << -12345 << '\n';     // print left justified
        std::cout << std::setw(10) << std::right << -12345 << '\n';    // print right justified
        std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified
    }

    return 0;
}