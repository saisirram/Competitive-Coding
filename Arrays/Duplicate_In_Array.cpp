/*
Find the duplicate in an array of N+1 integers:
Reference Link: https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers/
Given an array of N + 1 size, where each element is between 1 and N. 
Assuming there is only one duplicate number, your task is to find the duplicate number.

Input:
10
2 5 9 6 9 3 8 9 7 1

Output:
9
*/
#include<bits/stdc++.h>
using namespace std;
/*
Brute Force Solution:
Sort the array, then Traverse through the array, at any point if v[i] == v[i+1] then v[i] is duplicate element.
Time Complexity = O(NLogN) (Sorting) + O(N) (Traversing)
Auxiliary Space = O(1)

Better Solution:
Use Hash Map or Frequency array. Traverse the array and store their occurance in hash map of frequency array.
now check the Hash map or frequency array for the count if the count of an element is greater than 1 then it is duplicate element.
Time Complexity = O(N)
Auxiliary Space = O(N) (for Hash map or Frequency array)
*/

int Best_Solution(vector<int> v, int n)
{
    //Linked List Cycle Detection Method (Hare and Tortoise method)
    //Time Complexity = O(N)
    //Auxiliary Space = O(1)
    int slow = v[0];
    int fast = v[0];
    do{
        slow = v[slow];
        fast = v[v[fast]];
    }
    while(slow != fast);
    fast = v[0];

    while(slow != fast)
    {
        slow = v[slow];
        fast = v[fast];
    }
    return slow;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }

    int duplicate = Best_Solution(v,n);
    cout<<"Duplicate Element int the array is: "<<duplicate<<endl;
    return 0;
}