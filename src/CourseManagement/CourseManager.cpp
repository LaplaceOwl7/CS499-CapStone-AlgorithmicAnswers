#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <sstream>
#include <map>

#include "CourseManagement/Course.hpp"
#include "CourseManagement/CourseManager.hpp"
#include "Sorters/Sorter.hpp"
#include "ValidationTools/Validator.hpp"
#include "ValidationTools/Err.hpp"

std::vector<CourseData::Course> 
CourseManager::loadCourses(const std::string& t_file_path) 
{
    std::vector<CourseData::Course> allCourses;

    std::ifstream fin(t_file_path);
    if (!fin) {
        std::cout << "CSV file not found.\n";
        return allCourses; // Return Empty Vector
    }

    try {
        allCourses = VarLoader::mountCSV(t_file_path);
    }
    catch (const std::ios_base::failure&) {
        std::cout << "Failed to load CSV Database\n";
        return allCourses;
    }

    return allCourses;
}

void CourseManager::searchCourse(
    const std::vector<CourseData::Course>& t_courses,
    const std::string& t_courseId)
{
    for (const auto& course : t_courses) {
        if (course.getCourseID() == t_courseId) {
            std::cout << course.getCourseID() << ", "
                      << course.getCourseTitle() << '\n';

            const auto& prereqs = course.getCoursePrerequisites();
            std::cout << "Prerequisites: ";

            if (prereqs.empty()) {
                std::cout << "None\n";
                return;
            }

            for (size_t i = 0; i < prereqs.size(); ++i) {
                std::cout << prereqs[i];
                if (i < prereqs.size() - 1) std::cout << ", ";
            }
            std::cout << '\n';
            return;
        }
    }

    std::cout << "Course not found: " << t_courseId << '\n';
}

void CourseManager::printAllCourses(
    const std::vector<CourseData::Course>& t_allCourses)
{
    for (const auto& course : t_allCourses) {
        std::cout << course.getCourseID()
                  << ",  " << course.getCourseTitle() << '\n';

        const auto& prereqs = course.getCoursePrerequisites();
        std::cout << "Prerequisites: ";

        if (prereqs.empty()) {
            std::cout << "None\n";
        } else {
            for (size_t i = 0; i < prereqs.size(); ++i) {
                std::cout << prereqs[i];
                if (i < prereqs.size() - 1) std::cout << ", ";
            }
            std::cout << '\n';
        }
    }
}

void CourseManager::displayMenu()
{
    std::map<size_t, std::string> menuChoices = {
        {1, "Print All Courses"},
        {2, "Search for Course"},
        {3, "Sort via Algorithm"},
        {4, "Print Dynamics / Algorithmic Efficiency"},
        {5, "Print Markdown of Algorithm Stats / Database Comparison"},
        {6, "Use Optimized Algorithm"},
        {7, "Quit"}
    };

    for (const auto& mC : menuChoices) {
        std::cout << mC.first << ":\t" << mC.second << "\n";
    }
}

