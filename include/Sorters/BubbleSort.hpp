#ifndef BUBBLE_SORTER_HPP
#define BUBBLE_SORTER_HPP

#include <vector>
#include "CourseManagement/Course.hpp"   

namespace sorter {
/*
    * @brief Sorts the given vector of Course objects by courseId using the bubble sort algorithm.
    * @param courses; CourseSystem::Course objects to be sorted.
    * @return A sorted vector of CourseSystem::Course objects in ascending courseId order.
    * @pre courses contains valid Course objects with initial courseId values.
    * @post Sorts the inputted vector in place
*/
void performBubbleSort(std::vector<CourseData::Course>& courses);

} // ns: Sorter

#endif // BUBBLE_SORTER_HPP
