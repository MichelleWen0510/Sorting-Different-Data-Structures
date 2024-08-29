#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "StdSort.hpp"

void stdSort (const std::string & header, std::vector<int> data)
{
	//Start Timer
	const auto t1_start = std::chrono::steady_clock::now();
	//Sort Through First to Last Element
	std::sort(data.begin(),data.end());
	int min = data.at(0);			//Get first element
	int p25 = data.at((data.size()-1)/4);	//Get 25th percentile
	int p50 = data.at(data.size()/2);	//Get 50th percentile
	int p75 = data.at(3*(data.size()-1)/4);	//Get 75th percentile
	int max = data.at(data.size()-1);	//Get last element
	//End Timer
	const auto t1_end = std::chrono::steady_clock::now();
        int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
	//Print
	std::cout << header << "\n";
	std::cout << "Min: " << std::to_string(min) << "\n";
	std::cout << "P25: " << std::to_string(p25) << "\n";
	std::cout << "P50: " << std::to_string(p50) << "\n";
	std::cout << "P75: " << std::to_string(p75) << "\n";
	std::cout << "Max: " << std::to_string(max) << "\n"; 
	//std::cout << "Time for std sort: " << t1 << " microseconds." << std::endl;
}

