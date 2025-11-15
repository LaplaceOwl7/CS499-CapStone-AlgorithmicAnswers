#include <vector>
#include "CourseManagement/Course.hpp"

namespace sorter 
{
    // Merges two sorted halves of the vector
    static void merge(
        std::vector<CourseData::Course>& t_vector,
        int t_left, 
        int t_mid, 
        int t_right
        )
    {
        // 
        const int leftSize = t_mid - t_left + 1;
        const int rightSize = t_right - t_mid;

        std::vector<CourseData::Course> leftVec(leftSize);
        std::vector<CourseData::Course> rightVec(rightSize);

        for (int i = 0; i < leftSize; ++i) {
            leftVec[i] = t_vector[t_left + i];
        }
        for (int j = 0; j < rightSize; ++j) {
            rightVec[j] = t_vector[t_mid + 1 + j];
        }

        int i = 0;
        int j = 0;
        int k = t_left;

        while (i < leftSize && j < rightSize) {

            if (leftVec[i].getCourseID() <= rightVec[j].getCourseID()) {
                t_vector[k] = leftVec[i];
                ++i;
            }
            else {
                t_vector[k] = rightVec[j];
                ++j;
            }
            ++k;
        }

        while (i < leftSize) {
            t_vector[k] = leftVec[i];
            ++i;
            ++k;
        }

        while (j < rightSize) {
            t_vector[k] = rightVec[j];
            ++j;
            ++k;
        }
    }

    // Recursively sort the provided vectors by splitting them in half
    static void mergeSortRecursive(std::vector<CourseData::Course>& t_vector, int t_left, int t_right)
    {
        if (t_left >= t_right) {
            return;
        }

        const int mid = t_left + (t_right - t_left) / 2;

        mergeSortRecursive(t_vector, t_left, mid);
        mergeSortRecursive(t_vector, mid + 1, t_right);

        merge(t_vector, t_left, mid, t_right);
    }

    void mergeSort(std::vector<CourseData::Course>& t_courses)
    {
        if (t_courses.empty()) { // Verify the vector isn't empty
            return;
        }

        mergeSortRecursive(t_courses, 0, static_cast<int>(t_courses.size()) - 1);
    }

}