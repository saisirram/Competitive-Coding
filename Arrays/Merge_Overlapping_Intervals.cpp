/*
Merge Overlapping Sub-intervals:
Reference Link: https://takeuforward.org/data-structure/merge-overlapping-sub-intervals/
Given an array of intervals, merge all the overlapping intervals 
and return an array of non-overlapping intervals.

Input:
8 -> size
1 3
2 6
8 10
15 18

Output:
1 6
8 10
15 18

Explanation:
Since 1 3 &  2 6 has overlapping values 2,3 so we can mergge it as 1 6
*/

#include<bits/stdc++.h>
using namespace std;
void print_vecor(vector< pair<int,int> > ans)
{
    for(auto x: ans)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<endl;
}

vector< pair<int,int> > BruteForce_Solution(vector< pair<int,int> > intervals)
{
    //Time Complexity = O(N*LogN)(Sorting) + O(N*N)(Travesring)
    //Auxiliary Space = O(N);
    int n = intervals.size();
    vector< pair<int,int> > ans;
    sort(intervals.begin(), intervals.end());
    int start, end;
    for(int i=0;i<n;i++)
    {
        start = intervals[i].first;
        end = intervals[i].second;
        if(!ans.empty())
        {
            if(ans.back().second >= start)
            {
                continue;
            }
        }
        for(int j = i+1; j<n;j++)
        {
            if(intervals[j].first <= end)
            {
                end = intervals[j].second;
            }
        }
        ans.push_back(make_pair(start,end));
    }

    return ans;
}

vector< pair<int,int> > Better_Solution(vector< pair<int,int> > intervals)
{
    //Time Complexity = O(N*LogN)(Sorting) + O(N) (Traversing)
    //Auxiliary Space = O(N)
    int n = intervals.size();
    vector< pair<int,int> > ans;
    sort(intervals.begin(), intervals.end());
    pair<int,int> init = intervals[0];
    for(int i=1;i<n;i++)
    {
        if(intervals[i].first <= init.second)
        {
            init.second = max(init.second, intervals[i].second);
        }
        else
        {
            ans.push_back(init);
            init = intervals[i];
        }
    }
    ans.push_back(init);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > intervals;
    for(int i=0;i<n;i++)
    {
        int f, s;
        cin>>f>>s;
        intervals.push_back(make_pair(f,s));
    }
    cout<<"Original"<<endl;
    print_vecor(intervals);

    vector<pair<int,int> > ans;

    ans = BruteForce_Solution(intervals);
    cout<<"Merge Overlapping Intervals(BruteForce Solution): "<<endl;
    print_vecor(ans);

    ans = Better_Solution(intervals);
    cout<<"Merge Overlapping Intervals(Better Solution): "<<endl;
    print_vecor(ans);

    return 0;
}