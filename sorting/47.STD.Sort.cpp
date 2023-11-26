#include <algorithm> // for std::sort
#include <iostream>
#include <iterator> // for std::size

int main()
{
	int array[]{ 30, 50, 20, 10, 40 };
    std::cout << std::begin(array) << " " << std::end(array) << "\n";
	std::sort(std::begin(array), std::end(array));

	for (int i{ 0 }; i < static_cast<int>(std::size(array)); ++i)
		std::cout << array[i] << ' ';
    
	std::cout << '\n';
    for(int i : array)
    {
        std::cout << i << " "; 
    }

	std::cout << '\n';

	return 0;
}