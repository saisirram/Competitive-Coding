/*
Array Rotation Counter Clockwise (or Left Rotation)
Example:
    6 -> size og array
    1 2 3 4 5 6 -> array before rotation
    2 -> Number of Rotation Counter Clockwise
    3 4 5 6 1 2 -> Final array after number of rotations

Explanation:
    Initial array : 1 2 3 4 5 6 
    array after 1st rotation : 2 3 4 5 6 1
    array after 2nd rotation : 3 4 5 6 1 2
*/

#include<bits/stdc++.h>
using namespace std;

void print_array(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Array_Rotation_Brute(int arr[],int size,int rotations)
{
    //Time Complexity : O(Size)
    //Auxilary Space  : O(Rotations)
    int temp[rotations]; //extra space
    int counter =0;

    //Store the array elements in temporary array and append these elements at last
    for(int i=0;i<rotations;i++)
    {
        temp[i]=arr[i];
    }

    //Move all the remaining elements in an array by no.of rotation postions
    for(int i=rotations;i<size;i++)
    {
        arr[i-rotations]= arr[i];
    }

    //append that tem array to original array
    for(int i=size-rotations;i<size;i++)
    {
        arr[i]=temp[counter];
        counter++;
    }
    
}

void Array_Rotation_Better(int arr[], int size, int rotations)
{
    //Time Complexity : O(Size * Rotations)
    //Auxilary Space  : O(1)
    int temp;
    for(int i=1;i<=rotations;i++)
    {
        temp = arr[0];
        for(int j=1;j<size;j++)
        {
            arr[j-1]= arr[j];
        }
        arr[size-1]=temp;
        cout<<"after "<<i<<" rotations array is ";
        print_array(arr,size);
    }
}

void Reverse_Array(int arr[], int start, int end)
{
    int temp;
    while(start < end)
    {
        temp = arr[start];
        arr[start]=arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void Array_Rotation_Best(int arr[], int size, int rotations)
{
    //Time COmplexity : O(Size)
    //Auxilary Space  : O(1)
    Reverse_Array(arr,0,rotations-1);
    Reverse_Array(arr,rotations, size-1);
    Reverse_Array(arr,0,size-1);
    
}

int main()
{
    int size;
    cout<<"enter size of array:"<<endl;
    cin>>size;
    int arr[size];

    cout<<"enter array values:"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    int rotations;
    cout<<"enter No of Rotations"<<endl;
    cin>>rotations;
    if(rotations <= 0 || rotations == size)
    {
        print_array(arr,size);
        return 0;
    }
    else if(rotations >size)
    {
        rotations = rotations % size;
    }

    Array_Rotation_Brute(arr,size,rotations);
    cout<<"rotated array using brute-force solution: ";
    print_array(arr,size);

    Array_Rotation_Better(arr,size,rotations);
    cout<<"rotated array using better solution: ";
    print_array(arr,size);

    Array_Rotation_Best(arr,size,rotations);
    cout<<"rotated array using best solution: ";
    print_array(arr,size);
    return 0;
}