#ifndef QUICKSELECT2_HPP
#define QUICKSELECT2_HPP
#include <vector>
#include <string>
#include "QuickSelect2.hpp"
#include "InsertionSort.hpp"

const int & median31(std::vector<int> & a, int left, int right);
void insertionSort1(std::vector<int>& a, int left, int right);
void quickSelect(std::vector<int> & a, int left, int right,std::vector<int> keys);
void quickSelect2(const std::string & header, std::vector<int> data);

#endif
