def missingNumber(nums: list[int]) -> int:
    if len(nums) == 0:
        return 0
    nums_set = set()
    for i in nums:
        nums_set.add(i)

    for i in range(0, len(nums) + 1):
        if i not in nums_set:
            return i

    return -1


nums = [9,6,4,2,3,5,7,0,1]
print(missingNumber(nums))
