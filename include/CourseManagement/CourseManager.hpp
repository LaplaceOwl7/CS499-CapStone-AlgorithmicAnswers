#ifndef COURSEMANAGER_COURSEMANAGER_HPP
#define COURSEMANAGER_COURSEMANAGER_HPP

#include <string>
#include <vector>

#include "CourseManagement/CourseManager.hpp"
#include "ValidationTools/Validator.hpp"
#include "ValidationTools/Err.hpp"


class CourseManager {

    public:
    /**
     * @brief Loads master vector of Course objects into memory from a CSV file.
     * @param t_filePath Path to the CSV file.
     * @return Vector of all loaded CourseSystem::Course objects.
     * @pre The CSV file must exist and be readable.
     * @post Returns the master list; suitable for testing or further operations.
     */
    std::vector<CourseData::Course> loadCourses(const std::string& t_filePath);

    /**
     * @brief Performs a linear search for a specific course by ID.
     * @param t_courses Vector of Course objects to search.
     * @param t_courseId Target course ID to find.
     * @post If found, prints the course ID, title and its prerequisites to std::cout.
     */
    void searchCourse(
        const std::vector<CourseData::Course>& t_courses,
        const std::string& t_courseId
    );

    /**
     * @brief Prints all courses in the provided vector to std::cout,
     *        including their ID, title, and prerequisites.
     * @param t_allCourses Vector of all Course objects to print.
     * @pre Each CourseSystem::Course must have valid data.
     * @post Outputs all courses and their prerequisites.
     */
    void printAllCourses(const std::vector<CourseData::Course>& t_allCourses);

    /**
     * @brief Displays the textual menu choices for the application.
     * @post Prints the menu options (e.g., “Print All Courses”, “Search for Course”, …) to std::cout.
     */
    void displayMenu();

};

#endif // COURSEMANAGER_COURSEMANAGER_HPP
