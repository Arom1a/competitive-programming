with open("input") as f:
    content = f.read().strip()

ans = 0

for line in content.split("\n"):
    nums = [int(d) for d in line]
    max_num = max(nums)
    max_idx = nums.index(max_num)
    if max_idx != len(nums) - 1:
        next = max(nums[max_idx+1:])
        ans += max_num * 10 + next

    else:
        max_num = max(nums[:-1])
        max_idx = (nums[:-1]).index(max_num)
        if max_idx == len(nums) - 1:
            ans += max_num * 10 + nums[-1]
        else:
            next = max(nums[max_idx+1:])
            ans += max_num * 10 + next


def f(nums, i):
    if i == 1:
        max_num = max(nums)
        return [max_num]

    max_num = max(nums[:-(i - 1)])
    max_idx = nums.index(max_num)
    next = f(nums[max_idx + 1:], i - 1)
    return [max_num] + next


ans2 = 0

for line in content.split("\n"):
    nums = [int(d) for d in line]
    lst = f(nums, 12)
    print(lst)
    ans2 += int("".join(str(d) for d in lst))


print(ans)
print(ans2)
