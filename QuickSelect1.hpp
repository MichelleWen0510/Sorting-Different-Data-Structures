#ifndef QUICKSELECT1_HPP
#define QUICKSELECT1_HPP
#include <string>
#include <vector>
#include "QuickSelect1.hpp"
#include "InsertionSort.hpp"

const int & median31(std::vector<int> & a, int left, int right);
void insertionSort1(std::vector<int>& a, int left, int right);
void quickSelect(std::vector<int> & a, int left, int right, int k);
void quickSelect1 (const std::string & header, std::vector<int> data);

#endif
