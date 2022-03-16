/*
Length of the longest subarray with zero Sum:
Reference Link: https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum/
Given an array containing both positive and negative integers, 
we have to find the length of the longest subarray with the sum of all elements equal to zero.

Input 1:
8
6 -2 2 -8 1 7 4 -10

Output:
8 

Explanation:
subarrays with 0 sum are [-2,2], [-2,2,-8,1,7], [-8,1,7] and [6,-2,2,-8,1,7,4,-10]
so from all longest one is of size 8.
*/

#include<bits/stdc++.h>
using namespace std;

int BruteForce_Solution(vector<int> nums, int n)
{
    //Time Complexity = O(N * N)
    //Auxiliary Space = o(1)
    int max_len =0;
    for(int i=0;i<n;i++)
    {
        //cout<<"i: "<<i<<endl;
        int curr_len =1;
        int sum = nums[i];
        for(int j= i+1;j<n;j++)
        {
            //cout<<"j: "<<j<<endl;
            sum +=nums[j];
            curr_len+=1;
            //cout<<"Sum "<<sum<<" curr len: "<<curr_len<<endl;
            if(sum == 0)
            {
                max_len = max(curr_len,max_len);
            }
            //cout<<"maxLen: "<<max_len<<endl;
        }
    }
    return max_len;
}

int Better_Solution(vector<int> nums, int n)
{
    //Time Complexity = O(N)
    //Auxiliary Space = O(N)
    unordered_map<int,int> map;
    int max_len =0;
    int sum =0;
    for(int i=0;i<n;i++)
    {
        sum +=nums[i];
        if(sum == 0)
        {
            max_len =i+1;
        }
        else
        {
            if(map.find(sum) != map.end())
            {
                max_len = max(max_len, i - map[sum]);
            }
            else{
                map[sum] = i;
            }
        }
    }
    return max_len;
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }

    int result;
    result = BruteForce_Solution(nums,n);
    cout<<"Length of Longest Subarray with sum = 0(BruteForce Solution): "<<result<<endl;

    result = Better_Solution(nums,n);
    cout<<"Length of Longest Subarray with sum = 0(Better Solution): "<<result<<endl;


    return 0;
}