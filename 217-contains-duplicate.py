def containsDuplicate(nums: list[int]) -> bool:
    count = dict()

    for i in nums:
        count[i] = count.get(i,0) + 1
        if count[i] > 1:
            return True

    return False


nums = [1,2,3,1]

000
result = containsDuplicate(nums)

print(result)
