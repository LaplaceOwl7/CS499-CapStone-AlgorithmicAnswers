#include <iostream>
#include<string>
#include<vector>

#include <algorithm>
#include <fstream>
#include <cctype>  
#include <sstream>
#include <limits>

#include "CourseManagement/CourseManager.hpp"
#include "Sorters/Sorter.hpp"

int main(int argc, char* argv[]) {
    CourseManager manager; // Call a course manager to handle this.
    Sorter<CourseData::Course> sorter; // To sort objects
    std::vector<CourseData::Course> testCourses; // For CSV
    std::string userQuery; // For user search
    ErrLog error;
    
    /*
    - Load SQL database here.
    - Will be implemented in category 3
    - For now, use test CSV
    */

    try {
        testCourses = manager.loadCourses("seedInput.csv");
    } catch (std::ios_base::failure) { // Typically "file not found"
        std::cerr << "Failed to load CSV database; aborting\n";
        return 0;
    };

    int userChoice = 0;

    manager.displayMenu();

    do {
        std::cout << "What would you like to do?\n";

        userChoice = VarLoader::getIntFromCin();

        switch (userChoice)
        {
            case 1:
                std::cout << "Printing all courses...\n";
                manager.printAllCourses(testCourses);
                break;
            case 2:
                
                std::cout << "Course Search Selected\nCourse Query: ";

                std::getline(std::cin, userQuery);

                // Search for the course.
                manager.searchCourse(testCourses, userQuery);
            
                break;
            case 3:  
            // Sort Via Algorithms
            std::cout << "\nWhich Algorithm would you like to use?\n";

            sorter.printChoices(sorter.getChoices());

            userChoice = VarLoader::getIntFromCin();

            switch (userChoice)
                {
                    case 1:  // Use Quick Sort
                        std::cout << "Sorting with QuickSort...\n";
                        sorter.quickSort(testCourses);
                        manager.printAllCourses(testCourses);
                        break;

                    case 2:  // Use MergeSort
                        std::cout << "Sorting with MergeSort...\n";
                        sorter.mergeSort(testCourses);
                        manager.printAllCourses(testCourses);
                        break;

                    case 3:  // Use BubbleSort
                        std::cout << "Sorting with BubbleSort...\n";
                        sorter.bubbleSort(testCourses);
                        manager.printAllCourses(testCourses);
                        break;

                    case 0:
                        std::cout << "Cancelled.\n";
                        break;

                    default:
                        std::cout << "Invalid option. Try again.\n";
                        break;
                }
                break;

            case 4:
                //Print dynamics, algorithmic efficiency
                std::cout << "Check back in on After Category 2 is done!\n";
                break;
            case 5:
                // print markdown of the algorithm's stats, database, comparsion
                std::cout << "Check back in on After Category 2 is done!\n";
                break;
            case 6:
                // Use optimized algorithm
                std::cout << "Check back in on After Category 2 is done!\n";
                break;
            case 7:
                // Quit
                return 0;
                break;
            default:
                std::cout << "Invalid option\n";
        }

    } while (userChoice != 7);

    std::cout << "Goodbye!\n";

    return 0;
}
