/*
Length of the longest alternating even odd subarray:

Given an array a[] of N integers, the task is 
to find the length of the longest Alternating Even Odd subarray present in the array.

Input 1:
6
5 10 20 6 3 8

Output:
3 ->[6,3,8]

Input 2:
6
0 2 4 6 8 10

Output:
1 
Explanation:
even though it is complete odd series or even series 
it has atleast one element of eithe even or odd
*/

#include<bits/stdc++.h>
using namespace std;
int BruteForce_Solution(vector<int> v, int size)
{
    //Time Complexity = O(Size^2)
    //Auxiliary Space = O(1)
    int res=1,curr=1;
    for(int i=0;i<size;i++)
    {
        curr=1;
        for(int j=i+1;j<size;j++)
        {
            if((v[j]%2==0 && v[j-1]%2==1) ||(v[j]%2==1 && v[j-1]%2==0))
            {
                curr++;
            }
            else break;
        }
        res = max(curr,res);
    }
    return res;
}

int Better_Solution(vector<int> v, int size)
{
    //Variation of Kadanes Algorithm
    //Time Complexity = O(Size)
    //Auxiliary Space = O(1)
    int res=1, curr=1;
    for(int i=1; i<size;i++)
    {
        if((v[j]%2==0 && v[j-1]%2==1) ||(v[j]%2==1 && v[j-1]%2==0))
        {
            curr++;
            res = max(curr, res);
        }
        else curr=1;
    }
    return res;
}

int main()
{
    int size;
    cin>>size;
    vector<int> v;
    for(int i=0;i<size;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
}