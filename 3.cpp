#include <iostream>

void print_rectangle(int x, int y = -1) {
    if (y == -1) { // if only one argument is passed
        y = x; // make y equal to x to print a square
    }

    for (int i = 0; i < y; i++) { // iterate through rows
        for (int j = 0; j < x; j++) { // iterate through columns
            std::cout << "X "; // print a "block"
        }
        std::cout << std::endl; // move to the next row
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	std::cout << "x = 2, y = 5: " << std::endl;
	print_rectangle(2, 5);

	std::cout << "x = 3, y = 3: " << std::endl;
	print_rectangle(3, 3);

	std::cout << "x = 4: " << std::endl;
	print_rectangle(4);

	return 0;
};
