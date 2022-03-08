/*
Majority Element(s) (N/2):

A majority element in an array A of size n is an element that appears more than n/3 times
(and hence there is at most two such element -> means 0 or 1 or 2 Majority Element(s)).

Input 1:
6
2 3 2 3 2 3

Output:
2 3 -> count of both 2, 3 is 3 which is greater than floor(n/3) i.e 6/3 = 2

Input 2:
5
2 4 2 4 2

Output:
2 4 -> count of 2 is 3 and count of 4 is 2. bith are greater than floor(n/3) i.e 5/3 = 1

Input 3:
5 
2 7 6 2 1

Output:
2 -> count of 2 is 2 which is greater than floor(n/3) i.e 5/3 = 1
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> BruteForce_Solution(vector<int> v,int size)
{
    //Time Complexity = O(Size^2)
    //Auxiliary Space = O(1)
    vector<int> result;
    int count =0;
    for(int i=0;i<size;i++)
    {
        count=1;
        for(int j=i+1;j<size;j++)
        {
            if(v[i]==v[j])
            {
                count++;
            }
        }
        if(count> size/3)
        {
            result.push_back(v[i]);
        }
    }
    return result;
}

vector<int> Better_Solution(vector<int> v, int size)
{
    //Time Complexity = O(N)
    //Auxiliary Space = O(N)
    unordered_map<int,int> count_map;
    vector<int> result;

    for(int i=0;i<size;i++) // TC = O(N)
    {
        count_map[v[i]]++;
    }

    for(auto x: count_map)
    {
        if(x.second >(size/3))
        {
            result.push_back(x.first);
        }
    }
    return result;
}

vector<int> Best_Solution(vector<int> v, int size)
{
    //Extended Moore's Voting Algorithm
    /*
    Approach: This is a two-step process. 
        1) The first step gives the 2 element that maybe the majority element(s) in the array.
        If there is a majority element(s) in an array, 
        then this step will definitely return majority element(s), otherwise, 
        it will return candidate for majority element(s).
        
        2)Check if the element(s) obtained from the above step is majority element(s). 
        This step is necessary as there might be no majority element.
    */
    //Time Complexity = O(N)
    //Auxiliary Space = O(1)
    int num1 = INT_MIN;
    int num2 = INT_MIN;
    int c1=0;
    int c2=0;
    vector<int> result;

    //Step: 1 
    for( auto ele : v)
    {
        if(num1 == ele) c1++;
        else if(num2 == ele) c2++;
        else if(c1==0)
        {
            num1 = ele;
            c1++;
        }
        else if(c2 ==0)
        {
            num2 = ele;
            c2++;
        }
        else
        {
            c1--;
            c2--;
        }
    }

    //Step: 2
    c1=0;
    c2=0;
    for(auto x: v)
    {
        if(x == num1)
        {
            c1++;
        }
        else if(x == num2)
        {
            c2++;
        }
    }

    if(c1 > (size/3))
    {
        result.push_back(num1);
    }
    if(c2 > (size/3))
    {
        result.push_back(num2);
    }

    return result;
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

    vector<int> majority_elements;

    majority_elements = BruteForce_Solution(v,size);
    set<int> majority_set(majority_elements.begin(),majority_elements.end()); 
    cout<<"Majority element N/3 (BruteForce Solution): "<<endl;
    if(majority_elements.empty())
    {
        cout<<"No Majority Element: "<<-1<<endl;
    }
    else
    {
        cout<<"Majority elements are: ";
        for(auto x : majority_set)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }

    majority_elements= Better_Solution(v,size);
    cout<<"Majority element N/3 (Better Solution): "<<endl;
    if(majority_elements.empty())
    {
        cout<<"No Majority Element: "<<-1<<endl;
    }
    else
    {
        cout<<"Majority elements are: ";
        for(auto x : majority_elements)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }

    majority_elements = Best_Solution(v,size);
    cout<<"Majority element N/3 (Best Solution): "<<endl;
    if(majority_elements.empty())
    {
        cout<<"No Majority Element: "<<-1<<endl;
    }
    else
    {
        cout<<"Majority elements are: ";
        for(auto x : majority_elements)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }

}