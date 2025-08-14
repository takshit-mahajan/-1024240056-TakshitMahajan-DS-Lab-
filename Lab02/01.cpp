#include <iostream>
using namespace std;
#include<vector>

int search(vector<int> &nums, int target)
{
    int st = 0;
    int end = nums.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (target < nums[mid])
        {
            end = mid - 1;
        }
        else if (target > nums[mid])
        {
            st = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    // Your code here
    vector<int> a={1,3,5,6};
    int target=5;
    int x=search(a,target);
    cout<<x;
    return 0;
}
