/* Sorting employees using Comparator
input has a pair of string name,int salary of employees.
now sort the employees in decreasing order of salaries.
if salaries of two employees are equal sort them in lexicographical order of their names.

Input:
5
sai 89
sri 78
ram 78
saisri 66
saisriram 78

Output:
sai 89
ram 78
saisriram 78
sri 78
saisri 66

*/

#include<bits/stdc++.h>
using namespace std;

bool myComparator(pair<string,int> p1, pair<string,int> p2)
{
    if(p1.second == p2.second)
    {
        return p1.first<p2.first;
    }
    return p1.second>p2.second;
}
int main()
{
    int size;
    cin>>size;
    vector<pair<string,int> > employees;

    for(int i=0;i<size;i++)//Taking Input
    {
        string name;
        int salary;
        cin>>name>>salary;
        employees.push_back(make_pair(name,salary));
    }
    cout<<endl;
    for(auto employee : employees) //Printing the vector before sorting
    {
        cout<<employee.first<< " " <<employee.second<<endl;
    }
    cout<<endl;

    sort(employees.begin(),employees.end(),myComparator); //Sorting

    for(auto employee : employees)// printing the vector after sorting
    {
        cout<<employee.first<< " " <<employee.second<<endl;
    }

    return 0;
}