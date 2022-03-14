#include<bits/stdc++.h>
using namespace std;
vector<int> BruteForce_Solution(vector<int> v, int n, int target)
{
    //Time Complexity = O(N * N)
    //Auxiliary Space = O(1)
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        for(int j =i+1;j<n;j++)
        {
            if(v[i] + v[j] == target)
            {
                res.push_back(i);
                res.push_back(j);
                break;
            }
        }
    }
    return res;
}

vector<int> Better_Solution(vector<int> v, int n, int target)
{
    //Two Pointer Approach
    //Time Complexity = O(NLogN) (For Sorting) + O(N) (Traversing)
    //Auxiliary Space = O(N) (Dup vector)
    vector<int> res;
    vector<int> dup(v);
    sort(dup.begin(),dup.end());
    int i =0;
    int j = n-1;
    int n1,n2;
    while(i<j)
    {
        if(dup[i] + dup[j] == target)
        {
            n1 = dup[i];
            n2 = dup[j];
            break;
        }
        else if(dup[i] + dup[j]> target)
        {
            j--;
        }
        else{
            i++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(v[i] == n1)
        {
            res.push_back(i);
        }
        if(v[i] == n2)
        {
            res.push_back(i);
        }
    }
    return res;
}

vector<int> Best_Solution(vector<int> v, int n, int target)
{
    unordered_map<int,int> map;
    vector<int> res;

    for(int i=0;i<n;i++)
    {
        if(map.find(target - v[i]) != map.end())
        {
            res.push_back(i);
            res.push_back(map[target-v[i]]);
            return res;
        }
        map[v[i]] = i;
    }
    return res;
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

    vector<int> res;

    res = BruteForce_Solution(v,n,target);
    cout<<"The To Numbers are(BruteForce Solution): "<<endl;
    if(res.empty())
    {
        cout<<"There are no exact two numbers: "<<endl;
    }
    else{
        cout<<res[0]<<" "<<res[1]<<endl;
    }

    res = Better_Solution(v,n,target);
    cout<<"The To Numbers are(Better Solution): "<<endl;
    if(res.empty())
    {
        cout<<"There are no exact two numbers: "<<endl;
    }
    else{
        cout<<res[0]<<" "<<res[1]<<endl;
    }

    res = Best_Solution(v,n,target);
    cout<<"The To Numbers are(Best Solution): "<<endl;
    if(res.empty())
    {
        cout<<"There are no exact two numbers: "<<endl;
    }
    else{
        cout<<res[0]<<" "<<res[1]<<endl;
    }


    return 0;
}