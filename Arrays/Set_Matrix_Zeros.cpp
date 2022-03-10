/*
Set Matrix Zero:
Reference Link: https://takeuforward.org/data-structure/set-matrix-zero/
Given a matrix if an element in the matrix is 0 then you will have to set its entire col and row to 0
and then return the matrix.

Input 1:
3 3
1 1 1
1 0 1
1 1 1

Output:
1 0 1
0 0 0 
1 0 1
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

vector< vector<int> > BruteForce_Solution(vector<vector<int> > v, int row, int col)
{
    //Time Complexity = O((row * col) + (row + col)) + O(row * col)
    //Auxiliary Space = O(1)
    vector< vector<int> > res(row, vector<int>(col));
    res = v;

    for(int i=0;i<row;i++) //O(row)
    {
        for(int j=0;j<col;j++) //O(row * col)
        {
            if(res[i][j] == 0)
            {
                for(int c =0;c<col;c++) //O(row)
                {
                    if(res[i][c] != 0)
                    res[i][c] = INT_MIN;
                }
                
                for(int r=0;r<row;r++) //O(col)
                {
                    if(res[r][j] != 0)
                    res[r][j] = INT_MIN;
                }
            }
        }
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(res[i][j] == INT_MIN)
            {
                res[i][j] = 0;
            }
        }
    }

    return res;
}

vector< vector<int> > Better_Solution(vector<vector<int> > v, int row, int col)
{
    //Time Complexity = O(row * col) + O(row * col) => O(row * col)
    //Auxiliary Space = O(row) + O(col)
    vector<int> r(row,-1);
    vector<int> c(col,-1);
    vector< vector<int> > res(row, vector<int>(col));
    res = v;
   // print_matrix(res,row,col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(res[i][j] == 0)
            {
                r[i] =0;
                c[j] =0;
            }
        }
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(r[i] == 0 || c[j] == 0)
            {
               res[i][j] = 0;
            }
        }
    }
    return res;
}

vector< vector<int> > Best_Solution(vector<vector<int> > v, int row, int col)
{
    //Time Complexity = O((row * col)) + O(row * col)
    //Auxiliary Space = O(1)
    vector< vector<int> > res(row, vector<int>(col));
    res = v;
    int col0 = true;

    for(int i=0;i<row;i++)
    {
        if(res[i][0] == 0) col0 = false;
        for(int j=1;j<col;j++)
        {
            if(res[i][j] == 0)
            {
                res[i][0] =0;
                res[0][j] = 0;
            }
        }
    }

    for(int i=row -1; i>=0;i--)
    {
        for(int j = col-1; j>=1; j--)
        {
            if(res[i][0] ==0 || res[0][j] ==0)
            {
                res[i][j] =0;
            }
        }
        if(col0 == false)
        {
            res[i][0] =0;
        }
    }
    
    return res;
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
    vector<vector<int> > result(row, vector<int> (col));

    result = BruteForce_Solution(v,row,col);
    cout<<"Set Matrix Zeros(Brute Force Solution): "<<endl;
    print_matrix(result,row,col);

    result = Better_Solution(v,row,col);
    cout<<"Set Matrix Zeros(Better Solution): "<<endl;
    print_matrix(result,row,col);

    result = Best_Solution(v,row,col);
    cout<<"Set Matrix Zeros(Best Solution): "<<endl;
    print_matrix(result,row,col);
}