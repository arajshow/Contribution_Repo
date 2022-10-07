//The famous algorithm to find a subarray with maximum sum.
//This algorithm is used to solve a certain part of a large question which helps in reducing the overall time complexity of the program
//Time complexity of this algorithm is O(n) ans space alforithm is O(1)

#include<bits/stdc++.h>
using namespace std;
int max_sum_subarray(int arr[],int size)
{
    int curr_sum=0;
    int max_sum=INT_MIN;// so that the code works even if all elements are -ve.
    for(int i=0;i<size;i++)
    {
        curr_sum+=arr[i];
        {
            if(curr_sum>max_sum){max_sum=curr_sum;}
            if(curr_sum<0){curr_sum=0;}// Fresh start to take elements because there is not point to take the previous elements in the new subset since the sum of those elements is -ve hence they would only decrease the sum of new elements.
        }
    }
    
    return max_sum;
}
int main()
{
    
    int a[6]={1,2,-5,3,4,-1};
    cout<<max_sum_subarray(a,6);
    return 0;
}