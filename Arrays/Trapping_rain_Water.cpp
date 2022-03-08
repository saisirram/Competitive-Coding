/*
Trapping Rainwater: reference link: https://takeuforward.org/data-structure/trapping-rainwater/
Given an array of non-negative integers representation elevation of ground.
Your task is to find the water that can be trapped after raining.

Input:
12
0 1 0 2 1 0 1 3 2 1 2 1

Output:
6
*/

#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int> v, int size)
{
    for(int i =0;i<size;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

/*
Approach: 
The idea is to traverse every array element and find the highest bars on the left and right sides.
Take the smaller of two heights.
The diff b/w the smaller height and height of the current element is the amount of water that can be stored in this array element.
formula = result += min(leftmax,rightmax) - v[i]
*/
int BruteForce_Solution(vector<int> v, int size)
{
    //Time Complexity = O(Size^2)
    //Auxiliary Space = O(1)
    int res =0;
    for(int i=1; i<size-1;i++)
    {
        int left_max = v[i];
        for(int j=0;j<i;j++)
        {
            left_max = max(left_max, v[j]);
        }
        int right_max = v[i];
        for(int k = i+1; k<size;k++)
        {
            right_max = max(right_max,v[k]);
        }
        res += min(left_max,right_max) - v[i];
        //cout<<"i: "<<v[i]<<" Left Max "<<left_max<<" Right Max "<<right_max<<" Result: "<<res<<endl;
    }
    return res;
}

/*
Approach: 
In the previous solution, to find the highest bar on the left and right,
array traversal is needed which reduces the efficiency of the solution. 
To make this efficient one must pre-compute the highest bar on the left and right of every bar in linear time. 
Then use these pre-computed values to find the amount of water in every array element.
We use a varient prifix sum concept here 
*/
int Better_Solution(vector<int> v, int size)
{
    //Time Complexity = O(Size) + O(Size) + O(Size) = O(3Size) => O(Size)
    //Auxiliary Space = O(Size) + O(Size) = O(2Size) => O(Size)
    int result =0;
    vector<int> left_max(size,0);
    vector<int> right_max(size,0);
    left_max[0] = v[0];

    for(int i=1;i<size;i++)
    {
        
        left_max[i] = max(left_max[i-1], v[i]);
    }
    right_max[size-1]=v[size-1];
    for(int i=size-2;i>=0;i--)
    {
        
        right_max[i] = max(right_max[i+1],v[i]);
    }
    //print_vector(left_max,size);
    //print_vector(right_max,size);

    for(int i=0;i<size;i++)
    {
        result += min(left_max[i],right_max[i]) - v[i];
    }
    return result;
}

/*
Approach:
Take 2 pointer l(left pointer) and r(right pointer) pointing to 0th and (n-1)th index respectively.
Take two variables leftMax and rightMax and initialise it to 0.
If heigh[l] is less than or equal to height[r] then if leftMax is less then height[l] update leftMax to height[l] else add leftMax-height[l] to your final answer and move the l pointer to the right i.e l++.
If height[r] is less then height[l],then now we are dealing with the right block.
If height[r] is greater then rightMax,then update rightMax to height[r] else add rightMax-height[r] to the final answer.
Now move r to the left. Repeat theses steps till l and r crosses each other.

Intuition:
We need a minimum of leftMax and rightMax.
So if we take the case when height[l]<=height[r] we increase l++, 
so we can surely say that there is a block with height more than height[l] to the right of l.
And for the same reason when height[r]<=height[l] we can surely say that there is a block to the left of r which is at least of height height[r].
So by traversing with these cases and using two pointers approach the time complexity can be decreased without using extra space.
*/
int Best_Solution(vector<int> v, int size)
{
    //Time Copmlexity = O(size)
    //Auxiliary Space = O(1)
    int result =0;
    int left_max=0,right_max=0;
    int left_ptr = 0; 
    int right_ptr = size-1;

    while(left_ptr<=right_ptr)
    {
        if(v[left_ptr]<=v[right_ptr])
        {
            if(v[left_ptr]>left_max)
            {
                left_max = v[left_ptr];
            }
            else
            {
                result += left_max - v[left_ptr];
            }
            left_ptr++;
        }
        else
        {
            if(v[right_ptr]>right_max)
            {
                right_max = v[right_ptr];
            }
            else
            {
                result += right_max - v[right_ptr];
            }
            right_ptr--;
        }
    }

    return result;
}

int main()
{
    int size;
    cin>>size;
    vector<int> v;
    int x;
    for(int i=0;i<size;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    int max_water_trapped;

   max_water_trapped = BruteForce_Solution(v,size);
    cout<<"Max water Trapped(BruteForce Solution): "<<max_water_trapped<<endl;

    max_water_trapped = Better_Solution(v,size);
    cout<<"Max water trapped(Better Solution): "<<max_water_trapped<<endl;

    max_water_trapped = Best_Solution(v,size);
    cout<<"Max water trapped(Best Solution): "<<max_water_trapped<<endl;

    return 0;
}
 
