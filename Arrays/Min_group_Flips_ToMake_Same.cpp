#include<bits/stdc++.h>
using namespace std;

int BruteForce_Solution(vector<int> v, int size)
{
    int c0=0;
    int c1=0;
    int g0=0;
    int g1=0;
    int start=-1;
    int end=-1;
    if(v[0] == v[size-1])
    {
        if(v[0]==1)
        {
            c1 = 1;
        }
        else
        {
            c0=1;
        }
    }
    else
    {
        c1=1;
    }
    
}

int main()
{
    int size;
    cin>>size;
    vector<int> v;
    for(int i=0;i<size;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
}