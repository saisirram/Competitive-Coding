/*
Array Rotation Clockwise (or Right Rotation)
Example:
    6 -> size og array
    1 2 3 4 5 6 -> array before rotation
    2 -> Number of Rotation Counter Clockwise
    5 6 1 2 3 4 -> Final array after number of rotations

Explanation:
    Initial array : 1 2 3 4 5 6 
    array after 1st rotation : 6 1 2 3 4 5
    array after 2nd rotation : 5 6 1 2 3 4
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

    //Store the array elements in temporary array and append them at begining of array
    for(int i= size - rotations;i<size;i++)
    {
        temp[counter]=arr[i];
        counter++;
    }
    
    //Move all the remaining elements in an array by  postions (no.of rotation) to right 
    for(int i= size-rotations-1 ;i>=0 ;i--)
    {
        arr[i+rotations] = arr[i];
    }
    
    //append that temp array to original array at the beginning
    for(int i= 0;i<rotations;i++)
    {
        arr[i]=temp[i];
    }
}

void Array_Rotation_Better(int arr[], int size, int rotations)
{
    //Time Complexity : O(Size * Rotations)
    //Auxilary Space  : O(1)
    int temp;
    for(int i=1;i<=rotations;i++)
    {
        temp = arr[size-1];
        for(int j=size-2;j>=0;j--)
        {
            arr[j+1]= arr[j];
        }
        arr[0]=temp;
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
    //Time Complexity : O(Size)
    //Auxilary Space  : O(1)
    Reverse_Array(arr,size-rotations,size-1);
    print_array(arr,size);
    Reverse_Array(arr,0, size-rotations-1);
    print_array(arr,size);
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

  /*  Array_Rotation_Brute(arr,size,rotations);
    cout<<"rotated array using brute-force solution: ";
    print_array(arr,size);

   Array_Rotation_Better(arr,size,rotations);
    cout<<"rotated array using better solution: ";
    print_array(arr,size);*/

    Array_Rotation_Best(arr,size,rotations);
    cout<<"rotated array using best solution: ";
    print_array(arr,size);
    return 0;
}