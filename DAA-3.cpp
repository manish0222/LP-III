#include <bits/stdc++.h>
using namespace std;
// Class for an item which stores weight and
// corresponding value of Item
// refer link --> https://www.geeksforgeeks.org/fractional-knapsack-problem/
class Item {
public:
    int profit, weight;
    // Constructor
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
    // Comparison function to sort Item 
    // according to profit/weight ratio
    static bool cmp(const Item& a, const Item& b)
    {
        double r1 = (double)a.profit / (double)a.weight;
        double r2 = (double)b.profit / (double)b.weight;
        return r1 > r2;
    }
};

// Main greedy function to solve problem
double fractionalKnapsack(int W, Item arr[], int N)
{
    // Sorting Item on basis of ratio
    sort(arr, arr + N, Item::cmp);

    double finalValue = 0.0;

    // Looping through all items
    for (int i = 0; i < N; i++) {
        // If adding the current Item won't overflow, 
        // add it completely
        if (arr[i].weight <= W) {
            cout << "Taking item with profit: " << arr[i].profit 
                 << " and weight: " << arr[i].weight << endl;
            W -= arr[i].weight;
            finalValue += arr[i].profit;
            cout << "Remaining weight capacity: " << W << endl;
        }
        // If we can't add current Item, add fractional part of it
        else {
            cout << "Taking fraction of item with profit: " << arr[i].profit 
                 << " and weight: " << arr[i].weight << endl;
            finalValue += arr[i].profit * ((double)W / (double)arr[i].weight);
            cout << "Remaining weight capacity is zero now." << endl;
            break;
        }
    }

    // Returning final value
    return finalValue;
}
int main()
{
    int W = 50;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 50 } };
    int N = sizeof(arr) / sizeof(arr[0]);
    // Function call
    double maxProfit = fractionalKnapsack(W, arr, N);
    cout << "Maximum profit: " << maxProfit << endl;
    return 0;
}
