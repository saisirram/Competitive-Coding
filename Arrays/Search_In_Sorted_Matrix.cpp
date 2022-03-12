/*
Search in a sorted 2D matrix:
Reference Link: https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/, https://youtu.be/ZYpYur0znng?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2
Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.

Given matrix has the following properties:
1) Integers in each row are sorted from left to right.
2) The first integer of each row is greater than the last integer of the previous row

Input 1:
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
10 -> target

Output:
true

Input 1:
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
17 -> target

Output:
false
*/

#include<bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<int> > v, int row, int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool BruteForce_Solution(vector<vector<int> > v, int row, int col,int target)
{
   //Time Complexity = O(N*M)
   //Auxiliary Space = O(1)
   for(int i=0;i<row;i++)
   {
       for(int j=0;j<col;j++)
       {
           if(v[i][j] == target)
           {
               return true;
           }
       }
   }
   return false;
}

bool Better_Solution(vector<vector<int> > v, int row, int col, int target)
{
    //It is also Optimal Solution
    //Time Complexity = O(Log(N*M))
    //Auxiliary Space = O(1)
    int i = 0;
    int j = col -1;

    while(i<row && j>=0)
    {
        if(v[i][j] == target)
        {
            return true;
        }

        if( v[i][j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

bool Best_Solution(vector<vector<int> > v, int row, int col, int target)
{
    //Binary Search Method:
    //Time Complexity = O(Log(N*M))
    //Auxiliary Space = O(1)
    int low = 0; int high = (col * row) -1;
    int mid =0;

    while(low<=high)
    {
         mid = low +(high - low)/2;
        if(v[mid/col][mid%col] == target)
        {
            return true;
        }
        else if(v[mid/col][mid%col] > target)
        {
            high = mid -1;
        }
        else
        {
            low = mid+1;
        }
    }
    return false;
}

int main()
{
    int row,col;
    cin>>row>>col;
    vector<vector<int> > v(row, vector<int> (col));
    cout<<v.size()<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>v[i][j];
        }
    }
    int target;
    cin>>target;
    bool result;

    result = BruteForce_Solution(v,row,col,target);
    cout<<"BruteForce Solution: "<<endl;
    if(result)
    cout<<target<<" is present in the matrix"<<endl;
    else
    cout<<target<<" is not present in the matrix"<<endl;

    result = Better_Solution(v,row,col,target);
    cout<<"Better Solution: "<<endl;
    if(result)
    cout<<target<<" is present in the matrix"<<endl;
    else
    cout<<target<<" is not present in the matrix"<<endl;

    result = Best_Solution(v,row,col,target);
    cout<<"Best Solution: "<<endl;
    if(result)
    cout<<target<<" is present in the matrix"<<endl;
    else
    cout<<target<<" is not present in the matrix"<<endl;


    return 0;
}