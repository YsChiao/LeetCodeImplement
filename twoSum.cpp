/*
 * Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<std::pair<int,int>> data;
        for (size_t i = 0; i < nums.size(); i++)
        {
            std::pair<int,int> temp(nums.at(i),i);
            data.push_back(temp);
        }
        std::sort(data.begin(), data.end(), [](const std::pair<int,int> &left,
                  const std::pair<int,int> &right){return left.first < right.first; });

        vector<std::pair<int,int>>::iterator it;

        for (size_t i = 0; i < data.size(); i++)
        {
            int value = target - data.at(i).first;
            it  = std::find_if(data.begin(), data.end(), [&value](const std::pair<int,int> &element)
            {return element.first == value;});

            size_t dis = it - data.begin();
            if (it != data.end() && (dis != i))
            {
                result.push_back(data.at(i).second);
                result.push_back((*it).second);
                return result;
            }
        }
        return result;
    }

private:
    vector<int> result;
};


