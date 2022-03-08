/*
Count Maximum Consecutive One’s in the array
Given an array that contains only 1 and 0.
return the count of maximum consecutive ones in the array.

Input:
6
1 1 0 1 1 1

Output:
3
*/

#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int> arr, int size)
{
    for( auto x : arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

int BruteForce_Solution(vector<int> arr, int size)
{
    //Time Complexity = O(Size^2)
    //Auxiliary Space = O(1)
    int max_count =0;
    int count =0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==1)
        {
            count =1;
            for(int j = i+1; j<size;j++)
            {
                if(arr[j] ==1)
                {
                    count++;
                }
                else{
                    break;
                }
            }
            max_count = max(max_count,count);
        }
    }
    return max_count;
}

int Better_Solution(vector<int> v, int size)
{
    //Time Complexity = O(Size)
    //Auxiliary Space = O(1)
    int count =0;
    int max_count=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i] ==1)
        {
            count++;
        }
        else{
            count = 0;
        }
        max_count = max(count,max_count);
    }
    return max_count;
}

int main()
{
    int size;
    cin>>size;
    vector<int> arr;
    int x;
    for(int i=0;i<size;i++)
    {
        cin>>x;
        arr.push_back(x);
    }
    int max_ones;

    max_ones = BruteForce_Solution(arr,size);
    cout<<"Max consceutive ones(Bruteforce Solution): "<<max_ones<<endl;

    max_ones = Better_Solution(arr,size)
    cout<<"Max consceutive ones(Better Solution): "<<max_ones<<endl;

    return 0;
}