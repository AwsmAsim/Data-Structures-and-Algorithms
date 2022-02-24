def frog_jump_memo(arr, idx, dp):
    
    if dp[idx] != -1:
        print(dp)
        return dp[idx]
        
    
    if(idx <=0):
        if idx == 0:
            return 0
        return float('inf')
    
    if idx - 1 >= 0:
        left = frog_jump_memo(arr, idx-1, dp) + abs(arr[idx] - arr[idx-1])
    else:
        left = frog_jump_memo(arr, idx-1, dp)
    if idx - 2 >= 0:
        right = frog_jump_memo(arr, idx-2, dp) + abs(arr[idx] - arr[idx-2])
    else:
        right = frog_jump_memo(arr, idx-2, dp)
    
    dp[idx] = min(left,right)
    return dp[idx]

arr = list(map(int, input().strip().split(' ')))#[10, 20, 30, 10]
dp = len(arr)*[-1]
# print(dp)
ans = frog_jump_memo(arr, len(arr)-1, dp)
print(ans)


# Tabulation (top down)
dp = len(arr)*[-1]
dp[0] = 0
dp[1] = arr[1] + dp[0]

for i in range(2, len(dp)):
    left = abs(arr[i] - arr[i-1]) + dp[i-1]
    right = abs(arr[i] - arr[i-2]) + dp[i-2]
    dp[i] = min(left, right)
    
print(dp)
print(dp[-1])
prev1 = 0
prev2 = arr[1] + prev1
answer = 0

for i in range(2, len(dp)):
    left = abs(arr[i] - arr[i-1]) + prev2
    right = abs(arr[i] - arr[i-2]) + prev1
    answer = min(left, right)
    prev1 = prev2
    prev2 = answer 
print(answer)    