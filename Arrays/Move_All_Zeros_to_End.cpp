/*
  move 0's to end without effecting the order of all non zero elements
  Input: 
  7
  10 20 0 34 0 5 0
  Output:
  10 20 34 5 0 0 0
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

vector<int> BruteForceSolution(vector<int> arr, int size)
{
    //Time Complexity = O(Size^2)
    //Auxilary Space  = O(1)

    //Traverse throug the array and find the first zero
    for(int i=0;i<size;i++)
    {
        if(arr[i]==0)
        {
            //then check for first non zero element after zero
            for(int j=i+1; j<size;j++)
            {
                if(arr[j]!=0)
                {
                    //swap those two
                    swap(arr[i],arr[j]);
                    break;
                }
            }
        }
    }
    return arr;
}

vector<int> Better_Solution(vector<int> arr, int size)
{
    //Time Complexity = O(Size)
    //Auxilary Space = O(1)

    int count =0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[count]);
            count++;
        }
    }
    return arr;
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

    vector<int> brut_result = BruteForceSolution(arr,size);
    cout<<"BruteFore Result Array: "<<" ";
    print_vector(brut_result,size);

    cout<<"Original Array: "<<" ";
    print_vector(arr,size);

    vector<int> better_result = Better_Solution(arr,size);
    cout<<"Better solution Result Array: "<<" ";
    print_vector(better_result,size);

    return 0;
}