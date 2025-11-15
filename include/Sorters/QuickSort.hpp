#ifndef SORTER_QUICKSORT_HPP
#define SORTER_QUICKSORT_HPP

#include <vector>
#include "Sorters/Sorter.hpp"

namespace sorter {

/**
 * @brief Partition the sub-array of arr between indices low and high, inclusive.
 *        Uses the last element as pivot, and moves smaller elements to the left.
 * @param arr Reference to the vector of ints to be partitioned.
 * @param low  The starting index of the sub-array.
 * @param high The ending index of the sub-array.
 * @return The final pivot index after partitioning.
 */
int partition(std::vector<int>& arr, int low, int high);

/**
 * @brief Sorts the vector of ints between indices low and high (inclusive)
 *        using the QuickSort algorithm.
 * @param arr  Reference to the vector of ints to be sorted.
 * @param low  The starting index of the segment to sort.
 * @param high The ending index of the segment to sort.
 */
void performQuickSort(std::vector<int>& arr, int low, int high);

} // ns: sorter

#endif // SORTER_QUICKSORT_HPP
