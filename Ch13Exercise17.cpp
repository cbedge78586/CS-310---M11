// Charles Edge
// CS310-T301
// M10: Assignment
// Source CH13, Programming Exercise 17

#include <iostream>
#include <random>
#include <stdexcept>

// The core function to generate numbers and handle exceptions
void generate_numbers(int count) {

    std::random_device rd;

// Generates random numbers
    std::mt19937 generator(rd());

// Creates real numbers between 10.0 and 100.0
    std::uniform_real_distribution<double> distribution(10.0, 100.0);

    std::cout << "*********************************************************\n";
    std::cout << "       Random Number Generation (10 to 100)\n";
    std::cout << "(An exception will occur if a number > 75 is generated.)\n";
    std::cout << "*********************************************************\n\n";

// Loop to generate the required count of numbers 
    for (int i = 1; i <= count; ++i) {
        try {
            double random_number = distribution(generator);

// Define simple exception condition, in this case if greater than 75
            if (random_number > 75) {

// Std exception will output error message
                throw std::runtime_error("Value is too high! We found a number > 75.");
            }

// If no exception, print the number
            std::cout << "# " << i << ": " << random_number << std::endl;

        }
        catch (const std::exception& e) {

// Shows exception, if number is greater than 75, prints iteration that stopped process
            std::cerr << "*********************************************************\n";
            std::cerr << "                !!! Error 404 !!!\n";
            std::cerr << "    Error: " << e.what() << "\n";
            std::cerr << "    The RNG process has stopped at iteration " << i << ".\n";
            std::cerr << "*********************************************************\n";

// Stops loop 
            break;
        }
    }

// Outputs that the process has been completed
    std::cout << "\n";
    std::cout << "*********************************************************\n";
    std::cout << "     Random Number Generation process complete \n";
    std::cout << "*********************************************************\n";
}

int main() {

// Call the function to run the program logic
    generate_numbers(25);

    return 0;
}