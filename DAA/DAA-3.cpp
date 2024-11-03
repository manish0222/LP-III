//FOR 0 1 knapsack not fractional using dp and memoization
// int solve(int ind,int w,vector<int>& wt, vector<int>& val,vector<vector<int>>&dp){
//     if(ind==0){
//         if(wt[ind]<=w) return val[ind];
//         return 0;
//     }
//     if(dp[ind][w]!=-1) return dp[ind][w];
//     int notpick=solve(ind-1,w,wt,val,dp);
//     int pick=INT_MIN;
//     if(wt[ind]<=w){
//         pick=val[ind]+solve(ind-1,w-wt[ind],wt,val,dp);
//     }
//     return dp[ind][w]=max(pick,notpick);
// }
// vector<vector<int>> dp(n+1,vector<int> (W+1,-1));
// return solve(n-1,W,wt,val,dp);



//      FOR KNAPSACK USING DP AND NO ITERATIVE USE BELOW FUNCTION
//     // Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, vector<int>& wt, vector<int>& val) {
//         // Your code here
//         int n=wt.size();
//         vector<vector<int>> dp(n+1,vector<int> (W+1,0));
//         for(int i=wt[0];i<=W;i++){
//             dp[0][i]=val[0];
//         }
//         for(int ind=1;ind<n;ind++){
//             for(int w=0;w<=W;w++){
//                 int notpick=dp[ind-1][w];
//                 int pick=INT_MIN;
//                 if(wt[ind]<=w){
//                     pick=val[ind]+dp[ind-1][w-wt[ind]];
//                 }
//                 dp[ind][w]=max(pick,notpick);
//             }
//         }
//         return dp[n-1][W];
//     }
// };

            //   CODE FOR FRACTIONAL KNAPSACK
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
