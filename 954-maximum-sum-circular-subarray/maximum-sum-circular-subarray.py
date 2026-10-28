class Solution:
    def maxSubarraySumCircular(self, nums: list[int]) -> int:
        total = sum(nums)

        max_sum = nums[0]
        min_sum = nums[0]

        cur_max = 0
        cur_min = 0

        for num in nums:
            cur_max = max(num,cur_max + num)
            max_sum = max(max_sum,cur_max)

            cur_min = min(num,cur_min + num)
            min_sum = min(min_sum,cur_min)

        if max_sum < 0:
            return max_sum

        return max(max_sum, total - min_sum)

