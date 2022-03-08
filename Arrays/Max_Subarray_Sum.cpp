/*
Maximum Subarray Sum in an Array (Kadanes Algorithm):
reference link : https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
Given an integer array arr, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

Input 1:
9
-2 1 -3 4 -1 2 1 -5 4

Output:
6 -> sub array [4,-1,2,1]

Input 2:
4
10 20 30 40

Output:
100 -> subarray [10,20,30,40] if all positive nums the max subarray sum = array sum

Input 3:
3
-6 -1 -8

Output:
-1 -> subarray [-1] if all negative elements then max subarray sum = max element
*/

#include<bits/stdc++.h>
using namespace std;

int BruteForce_Solution(vector<int> v, int size)
{
    //Time Complexity = O(Size^2)
    //Auxiliary Space = O(1)    
    int max_sum = v[0];
    int curr_sum =0;

    for(int i=0;i<size;i++)
    {
        curr_sum = 0;
        for(int j=i;j<size;j++)
        {
            curr_sum += v[j];
            max_sum = max(curr_sum,max_sum);
        }
    }
    return max_sum;
}

//Referance Link: https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d
int Better_Solution(vector<int> v, int size, vector<int> &subarray)
{
    //Kadanes Algorithm
    //Time Complexity = O(Size)
    //Auxiliary Space = O(1)
    int meh =0;
    int msf = INT_MIN;
    int s=0;
    for(int i=0;i<size;i++)
    {
        meh = meh+v[i];
        if (meh > msf) 
        {
            subarray.clear();
            msf = meh;
           subarray.push_back(s);
           subarray.push_back(i);
        }
        if (meh < 0) 
        {
        meh = 0;
        s = i + 1;

        }
    }
    return msf;

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

    int max_sum =0;
    vector<int> subarray{2};

    max_sum = BruteForce_Solution(v,size);
    cout<<"Max sub array sum(BruteForce Solution): "<<max_sum<<endl;

    max_sum = Better_Solution(v,size,subarray);
    cout<<"Max sub array sum(Better Solution): "<<max_sum<<endl;

    cout<<"Sub array is: "<<endl;
    for(int i = subarray[0]; i<=subarray[1];i++)
    {
        cout<<v[i]<<" ";
    }
}