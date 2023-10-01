// this is the knapsack problem
#include <iostream>
#include <vector>
#include <algorithm>

int knapsack(const std::vector<int> &values, const std::vector<int> &weights, int capacity)
{
    int n = values.size();

    // Create a table to store the maximum value of knapsack for a given weight
    // dp[i][j] represents the maximum value achievable using the first i items with total weight j
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= capacity; ++j)
        {
            if (weights[i - 1] <= j)
            {
                dp[i][j] = std::max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    std::vector<int> values = {60, 100, 120};
    std::vector<int> weights = {10, 20, 30};
    int capacity = 50;

    int maxValue = knapsack(values, weights, capacity);
    std::cout << "Maximum value in knapsack = " << maxValue << std::endl;

    return 0;
}
