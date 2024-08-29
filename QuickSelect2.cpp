#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>
#include "QuickSelect2.hpp"
#include "InsertionSort.hpp"
//Median
const int & median32(std::vector<int> & a, int left, int right)
{
        int center = ( left + right ) / 2;

        if( a[ center ] < a[ left ] )
                std::swap( a[ left ], a[ center ] );
        if( a[ right ] < a[ left ] )
                std::swap( a[ left ], a[ right ] );
        if( a[ right ] < a[ center ] )
                std::swap( a[ center ], a[ right ] );

        std::swap( a[ center ], a[ right - 1 ] );
        return a[ right - 1 ];
}
//Insertion Sort
void insertionSort2(std::vector<int>& a, int left, int right) 
{
        for (int i = left + 1; i <= right; ++i) {
                int key = a[i];
                int j = i - 1;

                while (j >= left && a[j] > key) {
                        a[j + 1] = a[j];
                        --j;
                }
                a[j + 1] = key;
        }
}
//Quick select with vector of keys
void quickSelect(std::vector<int> & a, int left, int right, std::vector<int> keys)
{
	//Within range of 20
	if( left + 20 <= right )
	{
		const int & pivot = median32( a, left, right );

		int i = left, j = right - 1;
		for( ; ; )
		{
			while( a[ ++i ] < pivot ) { }
			while( pivot < a[ --j ] ) { }
			if( i < j )
				std::swap( a[ i ], a[ j ] );
			else
				break;
		}
	
		std::swap( a[ i ], a[ right - 1 ] );
		
		//Vector with pivot left and right
		std::vector<int> leftKeys, rightKeys;
		//Place keys into vectors
		for(int key : keys)
		{	
			if(key < pivot)
				leftKeys.push_back(key);
			else if (key > pivot)
				rightKeys.push_back(key);
		}
		//Recursive
		if (!leftKeys.empty())
            		quickSelect(a, left, i - 1, leftKeys); 
        	else
          	     insertionSort2(a, left, i - 1);

        	if (!rightKeys.empty())
            		quickSelect(a, i + 1, right, rightKeys); 
        	else
          	       insertionSort2(a, i + 1, right);

	} else 
		insertionSort2( a, left, right ); 
}

void quickSelect2 (const std::string & header, std::vector<int> data)
{
	//Start Timer
	const auto t1_start = std::chrono::steady_clock::now();
	//Vector with keys: 0, 25th, 50th, 75th, last
	std::vector<int> keys;
	keys.push_back(0);
	keys.push_back(data.size()/4);
	keys.push_back(data.size()/2);
	keys.push_back(3*(data.size()/4));
	keys.push_back(data.size()-1);
	//Quick select to sort data
	quickSelect(data,0,data.size()-1,keys);
	//Get percentiles
	int min = data.at(0);
	int p25 = data.at((data.size()-1)/4);
	int p50 = data.at(data.size()/2);
	int p75 = data.at(3*(data.size()-1)/4);
	int max = data.at(data.size()-1);
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
	//std::cout << "Time for QuickSelect2: " << t1 << " microseconds." << std::endl;
}


