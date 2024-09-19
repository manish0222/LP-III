#include <iostream>
#include <vector>
#include <cstdlib>  // for rand()
using namespace std;
// Write a program for analysis of quick sort by using deterministic and randomized variant.
// TC   O(n log n) time complexity. worst O(n²)
// SC   O(log n), Worst O(n)

class QuickSort {
    vector<int> array;

public:
    QuickSort(vector<int> arr) {
        array = arr;
    }

    // Function to display the current array
    void displayArray() {
        for (int i : array)
            cout << i << " ";
        cout << endl;
    }

    // Deterministic method to find pivot
    int partition(int low, int high) {
        int pivot = array[high];  // Pivot as the last element
        int i = low - 1;  // Pointer for greater element

        for (int j = low; j < high; j++) {
            if (array[j] <= pivot) {
                i++;
                swap(array[i], array[j]);
            }
        }
        swap(array[i + 1], array[high]);
        return i + 1;
    }

    // Randomized partition method
    int partition_random(int low, int high) {
        int pivot = low + rand() % (high - low + 1);  // Random pivot
        cout << "Random pivot selected: " << array[pivot] << endl;  // Print random pivot
        swap(array[pivot], array[high]);  // Swap with the high element
        return partition(low, high);  // Proceed with the normal partition
    }

    // Deterministic QuickSort
    void sort_d(int low, int high) {
        if (low < high) {
            int pivot = partition(low, high);
            cout << "Array after deterministic partition (pivot: " << array[pivot] << "): ";
            displayArray();

            sort_d(low, pivot - 1);  // Sort elements before partition
            sort_d(pivot + 1, high);  // Sort elements after partition
        }
    }

    // Randomized QuickSort
    void sort_r(int low, int high) {
        if (low < high) {
            int pivot = partition_random(low, high);
            cout << "Array after randomized partition (pivot: " << array[pivot] << "): ";
            displayArray();

            sort_r(low, pivot - 1);  // Sort elements before partition
            sort_r(pivot + 1, high);  // Sort elements after partition
        }
    }

    void display() {
        cout << "Final sorted array: ";
        displayArray();
    }
};

int main() {
    int n;  // Size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> array(n);  // Vector to store the elements
    cout << "Enter the elements of the array: ";

    for (int i = 0; i < n; i++) {
        cin >> array[i];  // Input each element
    }

    cout << "Deterministic variant of sort:" << endl;
    QuickSort sort1(array);
    sort1.sort_d(0, n - 1);
    sort1.display();

    cout << "\nRandomized variant of sort:" << endl;
    QuickSort sort2(array);
    sort2.sort_r(0, n - 1);
    sort2.display();

    return 0;
}
