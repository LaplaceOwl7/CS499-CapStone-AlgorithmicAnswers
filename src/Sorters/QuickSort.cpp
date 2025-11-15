#include <iostream>
#include <vector>

// #include "Sorter/QuickSorter.hpp"

namespace sorter {

    int partition(std::vector<int>& arr, int low, int high) {
        // Step 1: select pivot
        int pivot = arr[high];
    
        // undex of smaller element and indicates 
        // the right position of pivot found so far
        int i = low - 1;
        // undex of smaller element and indicates 
        // the right position of pivot found so far
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        
        // move pivot after smaller elements and
        // return its position
        std::swap(arr[i + 1], arr[high]);  
        return i + 1;
    }

    void quickSort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            // pi is the partition return index of pivot
            int pi = partition(arr, low, high);
            // recursion calls for smaller elements
            // and greater or equals elements
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
}
