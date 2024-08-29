#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include "CountingSort.hpp"

void countingSort(const std::string & header, std::vector<int> data)
{
	//Start Timer
	const auto t1_start = std::chrono::steady_clock::now();
	//Hash Map of unique data
	std::unordered_map<int, int> uMap;
	//Vector of key value pair
        std::vector<std::pair<int, int>> hashMap;
	//Place data into hash map counting the amount it appears
       	for(int i = 0; i < data.size() ; i++)
	{
		uMap[data.at(i)]++;
	}
	//Copies the hash map into vector
	std::copy(uMap.begin(), uMap.end(), std::back_inserter(hashMap));
	//Orders vector
	std::sort(hashMap.begin(),hashMap.end());
	//Using .first to get the value
	//Min and max are just first and last element
	int min = hashMap.at(0).first;
	int max = hashMap.at(hashMap.size()-1).first;
	//Count to see how many duplicates
	int count = 0;
	//Percentiles
	int per25 = data.size()/4;
	int per50 = data.size()/2;
	int per75 = 3*(data.size()/4);
	int p25, p50, p75;
	//Goes through the order vector to find each percentile
	for(const auto& pair: hashMap)
	{
		int num = pair.first;		//Unique values
		int amount = pair.second;	//Times it appears
		count += amount;		//Position
		//Check to see if 25th percentile is within the count
		if(count-amount<per25 && count+amount>per25)
		{
			p25 = num;
		}
		//Check to see if 50th percentile is within the count
		else if(count-amount<per50 && count+amount>per50)
                {
                        p50 = num;
                }
		//Check to see if 75th percentile is within the count
		else if(count-amount<per75 && count+amount>per75)
                {
                        p75 = num;
                }
	}
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
	std::cout << "Unique: " << std::to_string(hashMap.size()) << "\n";
        //std::cout << "Time for counting sort: " << t1 << " microseconds." << std::endl;
}
