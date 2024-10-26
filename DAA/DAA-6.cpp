#include <iostream>
#include <vector>
#include <cstdlib>  // for rand() function
using namespace std;

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

    // Deterministic method to find pivot (pivot as the first element)
    int partition(int low, int high) {
        int pivot = array[low];  // Pivot as the first element
        int i = low + 1;  // Start from the element after the pivot

        for (int j = low + 1; j <= high; j++) {
            if (array[j] < pivot) {
                swap(array[i], array[j]);
                i++;
            }
        }
        swap(array[low], array[i - 1]);  // Place the pivot in its correct position
        return i - 1;  // Return the pivot index
    }

    // Randomized partition method
    int partition_random(int low, int high) {
        int pivot_index = low + rand() % (high - low + 1);  // Random pivot
        cout << "Random pivot selected: " << array[pivot_index] << endl;  // Print random pivot
        swap(array[low], array[pivot_index]);  // Move random pivot to start
        return partition(low, high);  // Proceed with partitioning
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
