/*
Majority Element (N/2):

A majority element in an array A of size n is an element that appears more than n/2 times
(and hence there is at most one such element -> means 0 or 1 Majority Element). 

Input 1:
5
8 3 4 8 8

Output:
8  -> count of 8 is 3 which is greter than floor(n/2).

Input 2:
6
2 2 4 4 2 4

Output:
-1

Explanation:
here count of both element 2 and 4 are 3,
in which either of the count is not greater than floor(n/2).

*/

#include<bits/stdc++.h>
using namespace std;

int BruteForce_Solution(vector<int> v,int size)
{
    //Time Complexity = O(Size^2)
    //Auxiliary Space = O(1)
    int result_idx =-1;
    int count =0;
    for(int i=0;i<size;i++)
    {
        count=0;
        for(int j=0;j<size;j++)
        {
            if(v[i]==v[j])
            {
                count++;
            }
        }
        if(count> size/2)
        {
            return v[i];
        }
    }
    return INT_MIN;
}

int Better_Solution(vector<int> v, int size)
{
    //Time Complexity = O(NLogN)
    //Auxiliary Space = O(N)
    unordered_map<int,int> count_map;

    for(int i=0;i<size;i++) // TC = O(N)
    {
        if(count_map.count(v[i])!=0) //.count() take O(LogN) time
        {
            count_map[v[i]] +=1;
        }
        else{
            count_map[v[i]] =1;
        }
    }

    for(auto x: count_map)
    {
        if(x.second > size/2)
        {
            return x.first;
        }
    }
    return INT_MIN;
}

int Best_Solution(vector<int> v, int size)
{
    //Moore's Voting Algorithm
    /*
    Approach: This is a two-step process. 
        1) The first step gives the element that maybe the majority element in the array.
        If there is a majority element in an array, 
        then this step will definitely return majority element, otherwise, 
        it will return candidate for majority element.
        
        2)Check if the element obtained from the above step is majority element. 
        This step is necessary as there might be no majority element.
    */
    //Reference: https://www.geeksforgeeks.org/majority-element/
    //Time Complexity = O(Size)
    //Auxiliary Space = O(1)
    int res =0;
    int count =1;
    for(int i=1;i<size;i++)
    {
        if(v[i] == v[res])
        {
            count++;
        }
        else{
            count--;
        }
        if(count==0)
        {
            res =i;
            count =1;
        }
    }

    count =0;
    for(int i=0;i<size;i++)
    {
        if(v[i] == v[res])
        {
            count++;
        }
    }
    if(count<=size/2)
    {
        return INT_MIN;
    }
    return v[res];
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

    int majority_element;
    majority_element = BruteForce_Solution(v,size);
    cout<<"Majority element N/2 (BruteForce Solution): "<<endl;
    if(majority_element == INT_MIN)
    {
        cout<<"No Majority Element: "<<-1<<endl;
    }
    else{
        cout<<"Majority element is: "<<majority_element<<endl;
    }

   majority_element= Better_Solution(v,size);
   cout<<"Majority element N/2 (Better Solution): "<<endl;
   if(majority_element == INT_MIN)
    {
        cout<<"No Majority Element: "<<-1<<endl;
    }
    else{
        cout<<"Majority element is: "<<majority_element<<endl;
    }

    majority_element= Best_Solution(v,size);
   cout<<"Majority element N/2 (Best Solution): "<<endl;
   if(majority_element == INT_MIN)
    {
        cout<<"No Majority Element: "<<-1<<endl;
    }
    else{
        cout<<"Majority element is: "<<majority_element<<endl;
    }
}