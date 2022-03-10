/*
Sort an array of 0s, 1s and 2s:
Reference Link: https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/
Given an array consisting of only 0s, 1s and 2s. 
Write a program to in-place sort the array without using inbuilt sort functions.

Input:
10
0 1 0 1 2 1 0 0 2 1

Output:
0 0 0 0 1 1 1 1 2 2
*/
#include<bits/stdc++.h>
using namespace std;

/*
Brute Force Solution: Use any Sorting Algorithm 
(Time Complexity = O(NLogN))

Better Solution: Use counting Sort (Count no of occurances of 0, 1, 2 and overwrite the original array)
Time Complexity = O(N) (To count) + O(N) (To overwrite)

*/

//Dutch National Flag Algorithm
void Best_Solution(vector<int> &v, int size)
{
    //Time Complexity = O(N)
    //Auxiliary Space = O(1)
    int low =0, mid=0;
    int high =size-1;

    while(mid <= high)
    {
        if(v[mid] == 0)
        {
            swap(v[mid],v[low]);
            mid++;
            low++;
        }
        else if(v[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(v[mid], v[high]);
            high--;
        }
    }
}

int main()
{
    int size;
    cin>>size;
    vector<int> v;
    int x;
    for(int i=0;i<size;i++)
    {
        cin>>x;
        v.push_back(x);
    }

    Best_Solution(v, size);
    cout<<"Sort 0's, 1's, 2's : "<<endl;
    for(int x: v)
    {
        cout<<x<<" ";
    }

    return 0;
}