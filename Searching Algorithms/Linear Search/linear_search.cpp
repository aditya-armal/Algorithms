#include <iostream>
#include <vector>

int linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;  // Element found, return its index
        }
    }
    return -1;  // Element not found
}

int main() {
    std::vector<int> arr = {12, 45, 23, 6, 78, 54, 32};
    int target = 78;

    int result = linearSearch(arr, target);

    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}