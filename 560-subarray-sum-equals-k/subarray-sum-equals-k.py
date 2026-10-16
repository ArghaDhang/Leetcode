class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix = 0
        count = 0
        mp = {0:1}

        for i in nums:
            prefix += i
            if prefix - k in mp:
                count += mp[prefix - k]
            mp[prefix] = mp.get(prefix, 0) + 1
        return count