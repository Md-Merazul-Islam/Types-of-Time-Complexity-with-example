
#include <bits/stdc++.h>
using namespace std;

// O(1) - Constant Time
void constantTimeExample(int x) {
    int result = x * 2; // O(1) - multiplication is constant time
    cout << "Result: " << result << endl;
}

// O(log n) - Logarithmic Time (Binary Search)
int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // O(1) - constant time operation
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// O(p^n) - Exponential Time (Square Root)
void squareRootAlgorithm(int n) {
    for (int i = 1; i * i <= n; i++) {
        // O(1) - constant time operation
        cout << i << " "; // Printing square root values
    }
}

// O(n) - Linear Time
void linearAlgorithm(const vector<int>& arr) {
    for (int num : arr) {
        // O(1) - constant time operation for each element
        cout << num << " "; // Printing each element
    }
}

// O(n log n) - Linearithmic Time (Merge Sort)
void merge(vector<int>& arr, int low, int mid, int high) {
    // Assume O(n) time complexity for merge operation
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high); // Assume the merge operation is O(n)
    }
}

// O(n^2) - Quadratic Time
void quadraticAlgorithm(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            // O(1) - constant time operation
            cout << arr[i] * arr[j] << " "; // Some operation on pairs of elements
        }
    }
}

// O(2^n) - Exponential Time (Subsets)
void processSubset(const vector<int>& subset) {
    // O(n) - processing each subset
    for (int num : subset) {
        cout << num << " ";
    }
    cout << endl;
}

void generateSubsets(const vector<int>& arr) {
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        // O(n) - each subset contains at most n elements
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subset.push_back(arr[i]);
            }
        }
        processSubset(subset);
    }
}

// O(n!) - Factorial Time (Permutations)
void processPermutation(const vector<int>& permutation) {
    // O(n) - processing each permutation
    for (int num : permutation) {
        cout << num << " ";
    }
    cout << endl;
}

void generatePermutations(vector<int>& arr) {
    // O(n!) - iterating through all permutations
    do {
        processPermutation(arr);
    } while (next_permutation(arr.begin(), arr.end()));
}

int main() {
    // Example usage of each function

    // O(1) - Constant Time
    constantTimeExample(5);

    // O(log n) - Logarithmic Time (Binary Search)
    vector<int> sortedArr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    int result = binarySearch(sortedArr, target);
    cout << "Binary Search Result: " << result << endl;

    // O(p^n) - Exponential Time (Square Root)
    int n = 16;
    squareRootAlgorithm(n);
    cout << endl;

    // O(n) - Linear Time
    vector<int> linearArr = {11, 22, 33, 44, 55};
    linearAlgorithm(linearArr);
    cout << endl;

    // O(n log n) - Linearithmic Time (Merge Sort)
    vector<int> mergeSortArr = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(mergeSortArr, 0, mergeSortArr.size() - 1);
    cout << "Merge Sorted Array: ";
    for (int num : mergeSortArr) {
        cout << num << " ";
    }
    cout << endl;

    // O(n^2) - Quadratic Time
    vector<int> quadraticArr = {1, 2, 3, 4};
    quadraticAlgorithm(quadraticArr);
    cout << endl;

    // O(2^n) - Exponential Time (Subsets)
    vector<int> subsetArr = {1, 2, 3};
    generateSubsets(subsetArr);
    cout << endl;

    // O(n!) - Factorial Time (Permutations)
    vector<int> permutationArr = {1, 2, 3};
    generatePermutations(permutationArr);

    return 0;
}
