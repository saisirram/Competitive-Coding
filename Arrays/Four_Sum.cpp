/*
4 Sum | Find Quads that add up to a target value:
Reference Link: https://takeuforward.org/data-structure/4-sum-find-quads-that-add-up-to-a-target-value/
Given an array of N integers, your task is to find UNIQUE QUARDS that add up to give a target value. 
In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

Note:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
arr[a] + arr[b] + arr[c] + arr[d] == target

Input 1:
6
1 0 -1 0 -2 2
0 -> target

Output:
[ -2 -1 1 2 ]
[ -2 0 0 2 ]
[ -1 0 0 1 ]

Input 2:
10
4 3 3 4 4 2 1 2 1 1
9

Output:
[ 1 1 3 4 ]
[ 1 2 2 4 ]
[ 1 2 3 3 ]

*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > BruteForce_Solution(vector<int> v, int n, int target)
{
    //Time Complexity = O(NLogN) + O(N^3 LogN)
    //Auxiliary Space = O(M *4) where M is no of quads
    set<vector<int> > res_set;
    sort(v.begin(),v.end()); //O(NLogN)
    for(int i=0;i<n;i++) //O(N)
    {
        for(int j=i+1;j<n;j++) //O(N)
        {
            for(int k = j+1;k<n;k++) //O(N)
            {
                int x =target - (v[i] + v[j] + v[k]);

                if(binary_search(v.begin()+k+1, v.end(),x))//Binary Search O(LogN)
                {
                    vector<int> t;
                    t.push_back(v[i]);
                    t.push_back(v[j]);
                    t.push_back(v[k]);
                    t.push_back(x);

                    sort(t.begin(),t.end());
                    res_set.insert(t);
                }
            }
        }
    }
    vector<vector<int> > result(res_set.begin(), res_set.end());
    return result;
}

vector<vector<int> > Better_Solution(vector<int> v, int n, int target)
{
    //Time Complexity = O(NLogN) + O(N^3)
    //Auxiliary Space = O(M * 4) //for the result Quards
    sort(v.begin(),v.end()); //O(NLogN)
    vector<vector<int> > result;

    for(int i=0;i<n;i++) //O(N)
    {
        for(int j=i+1;j<n;j++) //O(N)
        {
            int red_target = target -(v[i] + v[j]);
            int front = j+1;
            int back = n-1;
            while(front<back) //O(N)
            {
                int x = v[front] + v[back];
                if(x < red_target) front++;
                else if(x > red_target) back--;
                else{
                    vector<int> t(4,0);
                    t[0] = v[i];
                    t[1] = v[j];
                    t[2] = v[front];
                    t[3] = v[back];
                    result.push_back(t);

                    while(front<back && t[2] == v[front]) ++front;

                    while(front<back && t[3] == v[back]) --back;

                }
            }
            while(j+1<n && v[j] == v[j+1]) ++j;
        }
        while(i+1<n && v[i] == v[i+1]) ++i;
    }
    return result;
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
    int target;
    cin>>target;

    vector<vector<int> > result;

    result = BruteForce_Solution(v,n,target);
    cout<<"Quards results to the Target are(BruteForce Solution): "<<endl;
    if(result.empty())
    {
        cout<<"no value which add up to the target"<<endl;
    }
    else
    {
        for(int i=0;i<result.size();i++)
        {
            cout<<"[ ";
            for(int j=0; j<result[i].size();j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"]"<<endl;
        }
    }

    result = Better_Solution(v,n,target);
    cout<<"Quards results to the Target are(Better Solution): "<<endl;
    if(result.empty())
    {
        cout<<"no value which add up to the target"<<endl;
    }
    else
    {
        for(int i=0;i<result.size();i++)
        {
            cout<<"[ ";
            for(int j=0; j<result[i].size();j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"]"<<endl;
        }
    }
    
    return 0;
}