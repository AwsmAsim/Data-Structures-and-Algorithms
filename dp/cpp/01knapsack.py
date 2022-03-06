import time

def knapsack01(wtMatrix, pMatrix, idx, val, weight, dp):
    
    if dp[weight][idx] != -1:
        return dp[weight][idx]
    
    if(idx == len(wtMatrix)  or weight <= 0):
        dp[weight][idx] = val
        return dp[weight][idx]
    
    if wtMatrix[idx] < weight:
        dp[weight][idx] = max(knapsack01(wtMatrix, pMatrix, idx + 1, val + pMatrix[idx], weight - wtMatrix[idx], dp),
                    knapsack01(wtMatrix, pMatrix, idx + 1, val, weight, dp))
    else:
        dp[weight][idx] = knapsack01(wtMatrix, pMatrix, idx + 1, val, weight, dp)
    return dp[weight][idx]
    
wtMatrix = [1, 3, 4, 5]
pMatrix = [3, 4, 5, 7]
maxW = 7
            


# Initialising our dp matrix for memoization: 
dp = []
for i in range(maxW+1):
    lst = []
    for j in range(len(wtMatrix)+1):
        lst.append(-1)
    dp.append(lst)
print('intial Dp: ')
# for i in dp:
#     print(i)
start_time = time.time()
val = knapsack01(wtMatrix, pMatrix, 0, 0, maxW, dp)
print("--- %s seconds ---" % (time.time() - start_time)) # approx time: 0.0 seconds
print(val)
print(dp)