#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> r(2, 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    r[0] = i;
                    r[1] = j;
                    return r;
                }
            }
        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    vector<int> r = s.twoSum(nums, target);
    cout << r[0] << " " << r[1] << endl;
    return 0;
}