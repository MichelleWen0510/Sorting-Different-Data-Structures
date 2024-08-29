#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "StdSort.hpp"
#include "InsertionSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"

int main() {
    std::ifstream inputFile("test_input.txt");
    std::string firstLine;
    std::string header;
    std::vector<int> numbers;

    if (inputFile.is_open()) {
        // Read the first line into a string
        if (std::getline(inputFile, firstLine)) {
            header = firstLine;
        }

        // Read the rest of the lines as integers into a vector
        std::string line;
        while (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            int num;
            while (ss >> num) {
                numbers.push_back(num);
            }
        }

        inputFile.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
    std::cout << "Std Sort: " << std::endl;
    stdSort(header,numbers);
    std::cout << std::endl;
    std::cout << "QuickSelect1: " << std::endl;
    quickSelect1(header,numbers);
    std::cout << std::endl;
    std::cout << "QuickSelect2: " << std::endl;
    quickSelect2(header,numbers);
    std::cout << std::endl;
    std::cout << "Counting Sort: " << std::endl;
    countingSort(header,numbers);
    std::cout << std::endl;
}
