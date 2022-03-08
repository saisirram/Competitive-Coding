/*
A number in an array is said to be a leader if all the elements
to its right are less than it.

Example:
Input: 
6 -> size
5 8 3 4 4 2

Output:
Leaders : 8 4 2

Explanation: in above array all elements to the right of 8 are less than 8
and at index 3 we have 4 and also at index 4 we have 4 so the element at index 3 is not a leader
because to its right tere is a element which is equal to it.
finally last element is always a Leader.
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

void BruteForceSolution(vector<int> arr, int size)
{
    //Time Complexity = O(Size^2)
    //Auxiliary Space = O(1)
    int leader = INT_MIN;
    for(int i=0;i<size-1;i++)
    {
        bool flag = false;
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]<=arr[j])
            {
                flag = true;
                break;
            }
            
        }
        if(flag == false)
        {
            cout<<"Leader: "<<arr[i]<<endl;
        }
    }
    cout<<"Leader: "<<arr[size-1]<<endl;
}

void BetterSolution(vector<int> arr, int size)
{
    //Time Complexity = O(N)
    //Auxiliary Space = O(1)

    /*
    The main idea of this solution is we traverse the array from back and make last ele as current leader
    if at all the second last element is greater than current leader then it becomes as leader
    which means if first ele on left to a leader is greater than leader it is automatically becomes as leader.
    The main drawback is it prints leaers from last (reverse order).
    */

    int curr_ldr = arr[size-1];
    cout<<"Leader: "<<curr_ldr<<endl;
    for(int i=size-2;i>=0;i--)
    {
        if(curr_ldr < arr[i])
        {
            curr_ldr = arr[i];
            cout<<"Leader: "<<curr_ldr<<endl;
        }
    }
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
    cout<<"Original Array: "<<" ";
    print_vector(arr,size);

    BruteForceSolution(arr,size);

    cout<<"Original Array: "<<" ";
    print_vector(arr,size);

    BetterSolution(arr,size);

    return 0;
}