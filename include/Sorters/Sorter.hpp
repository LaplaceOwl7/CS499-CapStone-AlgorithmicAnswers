#ifndef SORTER_HPP
#define SORTER_HPP

#include <vector>
#include <map>

// Fetch all sorting algorithm headers
#include "Sorters/BubbleSort.hpp"
#include "Sorters/QuickSort.hpp"
#include "Sorters/MergeSort.hpp"

template<typename T>

class Sorter {
public:

    void bubbleSort(std::vector<T>& t_toSort) {
        sorter::performBubbleSort(t_toSort);
    }

    void quickSort(std::vector<T>& t_toSort) {
        std::cout << "Category 2 will fully implement this.\n";
        // sorter::performQuickSort(t_toSort);
    }

    void mergeSort(std::vector<T>& t_toSort) {
        std::cout << "Category 2 will fully implement this.\n";
        // sorter::mergeSort(t_toSort);
    }

    // View options of the choices:
    std::vector<std::string> getChoices() {
        return t_sortingChoices;
    }

    // Print Options: To keep main neat:
    void printChoices(const std::vector<std::string>& t_choices){
        for (int i = 0; i < t_choices.size(); i++) {
            std::cout << t_choices[i] << std::endl;
        }
    }

    private:
    // The actual choices:
        std::vector<std::string> t_sortingChoices = {
            "1. QuickSort",
            "2. MergeSort",
            "3. BubbleSort"
        };
};

#endif // SORTER_HPP
