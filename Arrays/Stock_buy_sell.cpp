/*
Stock Buy and Sell:
Case 1:
If we can buy or sell any number of times to maximize the profit. 

Input`1:
5
1 5 3 8 12
Output:
max profit  = 13

Explanation:
buy the stock at idx 0 and sell it at idx 1 now the profit is 5-1 = 4
now again buy the stock at idx 2 and sell it at idx 4 now the profit is 3-12 = 9
now total profit is 4 +9 = 13

Input 2:
5
5 4 3 2 1
Output:
0

Explanation:
 incase of decreasing array at any point of time we may not get any profit so max_profit=0

 Case 2:
 If we are allowed to buy or sell the stock only once we use Max_difference solution in this case.
*/

#include<bits/stdc++.h>
using namespace std;

int Better_Solution(vector<int> prices, int size)
{
    int max_profit = 0;
    //find the immediate next greatest element and substaract it with the lowest and add to profit.
    //Time Complexity = O(Size)
    //Auxiliary Space = O(1)
    for(int i=1;i<size;i++)
    {
        if(prices[i]>prices[i-1])
        {
            max_profit+= prices[i] - prices[i-1];
        }
    }
    return max_profit;
}

int main()
{
    int size;
    cin>>size;
    vector<int> prices;
    int x;
    for(int i=0;i<size;i++)
    {
        cin>>x;
        prices.push_back(x);
    }

    int max_profit = Better_Solution(prices,size);

    cout<<"Max Profit is: "<<max_profit;

    return 0;
}