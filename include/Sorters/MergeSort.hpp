#ifndef SORTER_MERGESORTER_HPP
#define SORTER_MERGESORTER_HPP

#include <vector>

#include "CourseManagement/Course.hpp"

namespace sorter {
    /**
     * @brief Sorts the given vector of Course objects by courseId using the merge sort algorithm.
     * @param courses; sorts the vector of course objects by their courseIDs inplace
     * @return A sorted vector of CourseSystem::Course objects in ascending courseId order.
     * @pre courses contains valid Course objects with initial courseId values.
     * @post Sorts the inputted vector in place
     */
    
    static void merge(
        std::vector<CourseData::Course>& t_vector,
        int t_left, 
        int t_mid, 
        int t_right
    );

    static void mergeSortRecursive(std::vector<CourseData::Course>& t_vector, int t_left, int t_right);

    void mergeSort(std::vector<CourseData::Course>& t_courses);

}

#endif // SORTER_MERGESORTER_HPP
