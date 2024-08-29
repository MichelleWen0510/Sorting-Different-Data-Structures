#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>
#include "QuickSelect1.hpp"
#include "InsertionSort.hpp"
//Get median
const int & median31(std::vector<int> & a, int left, int right)
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
//Insertion sort
void insertionSort1(std::vector<int>& a, int left, int right) {
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
//Quick select with pivot k
void quickSelect(std::vector<int> & a, int left, int right, int k )
{
	//Within range of 20
	if( left + 20 <= right )
	{
		const int & pivot = median31( a, left, right );

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
	if( k <= i )
		quickSelect( a, left, i - 1, k );
	else if( k>i+1)
		quickSelect( a, i + 1, right, k );
	} else
		insertionSort1( a, left, right );
}

void quickSelect1 (const std::string & header, std::vector<int> data)
{
	//Start Timer
	const auto t1_start = std::chrono::steady_clock::now();
	//Quick select from start to end with 50th as pivot
	quickSelect(data,0,data.size()-1,data.size()/2);
	int p50 = data.at(data.size()/2);
	//Quick select from start to middle with 25th as pivot
	quickSelect(data,0,data.size()/2,data.size()/4);
	int p25 = data.at((data.size()-1)/4);	
	//Quick select from middle to end with 75th pivot
	quickSelect(data,data.size()/2,data.size()-1,3*((data.size())/4));
	int p75 = data.at(3*(data.size()-1)/4);
	//Get min and max separately
	int min = * std::min_element(data.begin(),data.end());
	int max = * std::max_element(data.begin(),data.end());
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
	//std::cout << "Time for QuickSelect1: " << t1 << " microseconds." << std::endl;
}


