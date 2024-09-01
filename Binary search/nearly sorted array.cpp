/*

Given a nearly sorted numsay such that each of its elements may be misplaced by no more than one position from the correct sorted order, efficiently search a given element in it and return its index.

An element at index `i` in a correctly sorted order can be misplaced by the ±1 position, i.e., it can be present at index `i-1` or `i` or `i+1` in the input numsay.

Input: nums[] = [2, 1, 3, 5, 4, 7, 6, 8, 9], target = 5
Output: 3
Explanation: Target 5 found at index 3

• If there are duplicate elements in the numsay, the procedure may return any index whose element is equal to the target.

Input: nums[] = [2, 1, 3, 5, 4, 5, 6, 8, 9], target = 5
Output: 3 (or 5)
Explanation: Target 5 found at index 3 and 5

• If the target is not located, the procedure should return -1.

Input: nums[] = [2, 1, 3, 5, 4, 7, 6, 8, 9], target = 10
Output: -1

*/

class Solution
{
public:
	int findIndex(vector<int> const &nums, int target)
	{
		int n = nums.size();
		int start = 0;
		int end = n-1;
		
		while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (target == nums[mid]) return mid;
            if (mid - 1 >= 0 && target == nums[mid - 1]) return mid - 1;
            if (mid + 1 < n && target == nums[mid + 1]) return mid + 1;

            if (target < nums[mid])
            {
                end = mid - 2;
            }
            else
            {
                start = mid + 2;
            }
        }
		return -1;
	}
};
