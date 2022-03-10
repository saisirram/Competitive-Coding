/*
Rotate Image by 90 degree:
Given a matrix, your task is to rotate the matrix by 90 degrees.

Input:
3
1 2 3
4 5 6
7 8 9

Output:
7 4 1
8 5 2
9 6 3
*/
#include<bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<int> > v, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector< vector<int> > BruteForce_Solution(vector<vector<int> > v, int n)
{
    //Time Complexity = O(N * N) + O(N * N)
    //Auxiliary Space = O(N*N)
    vector<vector<int> > result(n, vector<int> (n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            result[j][n - i - 1] = v[i][j];
        }
    }

    return result;
}

vector< vector<int> > Better_Solution(vector<vector<int> > v, int n)
{
    //Time Complexity = O(N * N)
    //Auxiliary Space = O(1)

    //Transpose the Matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(v[i][j] , v[j][i]);
        }
    }

    //reverse each row
    for(int i=0;i<n;i++)
    {
        reverse(v[i].begin(), v[i].end());
    }
    return v;
}


int main()
{
    int n;
    cin>>n;
    vector<vector<int> > v(n, vector<int> (n));
    cout<<v.size()<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    vector<vector<int> > result(n, vector<int> (n));

    result = BruteForce_Solution(v,n);
    cout<<"Set Matrix Zeros(Brute Force Solution): "<<endl;
    print_matrix(result,n);

    result = Better_Solution(v,n);
    cout<<"Set Matrix Zeros(Better Solution): "<<endl;
    print_matrix(result,n);
}