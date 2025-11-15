#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <limits>

#include "CourseManagement/Course.hpp"
#include "ValidationTools/Err.hpp"


namespace VarLoader {

    ErrLog err; // Wake up the error logger

    // Parses a single CSV line into components
    bool parseLine(
        const std::string& t_line,
        std::string& t_id,
        std::string& t_title,
        std::vector<std::string>& t_rawPrereqs)
    {
        std::istringstream stream(t_line);
        t_rawPrereqs.clear();

        if (!std::getline(stream, t_id, ',')) {
            return false; // ID failed to load
        }
        if (!std::getline(stream, t_title, ',')) {
            return false; // Title failed to load
        }

        std::string prereqBlock;
        // Read remainder of the line
        if (!std::getline(stream, prereqBlock)) {
            // If no preReqBlock is found, accept it.
            prereqBlock.clear();
        }

        if (!prereqBlock.empty()) {
            std::istringstream prereqStream(prereqBlock);
            std::string prereqId;

            while (std::getline(prereqStream, prereqId, ',')) {
                // Trim whitespace from prereqId for cleaner acquistion
                size_t start = prereqId.find_first_not_of(" \t\r\n");
                size_t end   = prereqId.find_last_not_of (" \t\r\n");

                // If previous search failed,
                if (start == std::string::npos) {
                    continue;
                }

                std::string trimmed = prereqId.substr(start, end - start + 1);

                t_rawPrereqs.push_back(trimmed); // Add this to the 
            }
        }
        return true; // Line was successfully loaded.
    }

    // Master Function
    std::vector<CourseData::Course> mountCSV(const std::string& t_csvPath)
    {
        std::vector<CourseData::Course> allCourses;
        std::unordered_map<std::string, std::vector<std::string>> rawPrereqMap;

        std::ifstream file(t_csvPath);
        if (!file) {
            err.genLogFile("Error: Cannot open CSV file '" + t_csvPath);
            std::cerr << "Error: Cannot open CSV file '" << t_csvPath << "'\n";
            return allCourses;
        }

        std::string line;
        while (std::getline(file, line)) {
            // Remove any trailing '\r' (carriage return) especially for CRLF Windows files
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }

            if (line.empty()) {
                continue;
            }

            std::string id;
            std::string title;
            std::vector<std::string> prereqs;

            if (!parseLine(line, id, title, prereqs)) {
                std::cerr << "Warning: Malformed line ignored: " << line << '\n';
                err.genLogFile("Warning: Malformed line ignored: " + line);
                continue;
            }

            if (id.empty()) {
                std::cerr << "Warning: Course missing ID. Line ignored.\n";
                err.genLogFile("Warning: Course missing ID. Line ignored.");
                continue;
            }
            if (title.empty()) {
                std::cerr << "Warning: Course '" << id << "' missing title.\n";
                err.genLogFile("Warning: Course" + id + "missing title");
            }

            // Construct Course object with correct constructor
            allCourses.emplace_back(id, title, prereqs);
        }

        return allCourses;
    }

    // Safely read an integer from std::cin
    int getIntFromCin()
    {
        std::string userInput;
        long long tempNumber = 0;
        int intOutput = 0;

        while (true) {
            if (!std::getline(std::cin, userInput)) {
                std::cerr << "Invalid Input. Enter a valid number:\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            try {
                tempNumber = std::stoll(userInput);
                // Is the temp number even in range?
                if (tempNumber > std::numeric_limits<int>::max()
                 || tempNumber < std::numeric_limits<int>::min()) {
                    throw std::out_of_range("Value out of int range");
                }
                intOutput = static_cast<int>(tempNumber);
                break;
            }
            // Will not report these too the logs.
            catch (const std::out_of_range&) {
                std::cerr << "Invalid Number! Please Try Again\n";
            }
            catch (const std::invalid_argument&) {
                std::cerr << "Invalid Number! Please Try Again\n";
            }
        }
        return intOutput;
    }

} // ns: Loader
