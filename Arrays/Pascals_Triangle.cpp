/*
Program to generate Pascal’s Triangle:
Case 1: Generate Whole Pascal Triangle wit given N.

Input:
 5

Output:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

Case 2: print only that particular row (say Nth row of Pascals Triangle)

Input:
5

Output:
1 4 6 4 1

Explanation:
a series of nCr => (5-1)C0 , (5-1)C1, (5-1)C2, (5-1)C03, (5-1)C4

Case 3: Give N, R print element at that particular position in Pascals Triangle.

Input:
5 3 -> 5th row & 3rd Col

Output:
6  -> (n-1)C(r-1) -> 4C2

*/
#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > Best_Solution(int n)
{
    //Time Complexity = O(N^2)
    //Auxiliary Space = O(N^2)
    vector< vector<int> > result(n);
    for(int i=0;i<n;i++)
    {
        result[i].resize(i+1);
        result[i][0] = result[i][i] =1;

        for(int j=1;j<i;j++)
        {
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
    }
    return result;
}

int main()
{
    int n;
    cin>>n;

    vector< vector<int> > result(n);

    result = Best_Solution(n);
    cout<<"Pascals Triangle (Best Solution): "<<endl;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}