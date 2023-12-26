#include <fstream>
#include <iostream>

int main()
{
    // ofstream is used for writing files
    // We'll make a file called Sample.txt
    std::ofstream outf{"./17_IO/Sample.txt"};

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
        return 1;
    }

    // We'll write two lines into this file
    outf << "This is line 1\n";
    outf << "This is line 2\n";

    {
        // ifstream is used for reading files
        // We'll read from a file called Sample.txt
        std::ifstream inf{"./17_IO/Sample.txt"};

        // If we couldn't open the input file stream for reading
        if (!inf)
        {
            // Print an error and exit
            std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
            return 1;
        }

        // While there's still stuff left to read
        while (inf)
        {
            // read stuff from the file into a string and print it
            std::string strInput;
            std::getline(inf, strInput);
            std::cout << strInput << '\n';
        }

        {
            inf.seekg(14, std::ios::cur);  // move forward 14 bytes
            inf.seekg(-18, std::ios::cur); // move backwards 18 bytes
            inf.seekg(22, std::ios::beg);  // move to 22nd byte in file
            inf.seekg(24);                 // move to 24th byte in file
            inf.seekg(-28, std::ios::end); // move to the 28th byte before end of the file

            inf.seekg(0, std::ios::beg); // move to beginning of file
            inf.seekg(0, std::ios::end); // move to end of file
        }
    }

    {
        // We'll pass the ios:app flag to tell the ofstream to append
        // rather than rewrite the file. We do not need to pass in std::ios::out
        // because ofstream defaults to std::ios::out
        std::ofstream outf{"./17_IO/Sample.txt", std::ios::app};

        // If we couldn't open the output file stream for writing
        if (!outf)
        {
            // Print an error and exit
            std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
            return 1;
        }

        outf << "This is line 3\n";
        outf << "This is line 4\n";

        return 0;

        // When outf goes out of scope, the ofstream
        // destructor will close the file
    }

    {
        std::ofstream outf{"./17_IO/Sample.txt"};
        outf << "This is line 1\n";
        outf << "This is line 2\n";
        outf.close(); // explicitly close the file

        // Oops, we forgot something
        outf.open("Sample.txt", std::ios::app);
        outf << "This is line 3\n";
        outf.close();
    }
    
    return 0;

    // When outf goes out of scope, the ofstream
    // destructor will close the file
}