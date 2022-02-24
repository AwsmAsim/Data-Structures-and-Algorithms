import time

def knapsack01(wtArray, profitArray, maxWt, wt=0, profit=0, idx=0):
    if(idx == len(wtArray)):
        if(wt<=maxWt):
            return profit
        return -1
    
    return max(knapsack01(wtArray, profitArray, maxWt, wt+wtArray[idx], profit + profitArray[idx], idx+1),
    knapsack01(wtArray, profitArray, maxWt, wt, profit, idx+1))
    
    
wtArray = [95, 4, 60, 32, 23, 72, 80, 62, 65, 46] # [1, 3, 4 ,5]# [95, 4, 60, 32, 23, 72, 80, 62, 65, 46] # [1, 3, 4 ,5]
profitArray = [55, 10, 47, 5, 4, 50, 8, 61, 85, 87]# [3, 4, 5 ,7]# [55, 10, 47, 5, 4, 50, 8, 61, 85, 87]# [3, 4, 5 ,7]
maxWT = 269 # 7
start_time = time.time()
print(knapsack01(wtArray, profitArray, maxWT))
print("--- %s seconds ---" % (time.time() - start_time))

dp = []
for i in range(11):
    dp.append([])
    for j in range(300):
        dp[i].append(-1)
        
def memoKnapsack01(wtArray, profitArray, maxWt, wt = 0, profit = 0, idx = 0):
    
    if dp[idx][wt] != -1:
        return dp[idx][wt]
    
    if(idx == len(wtArray)):
        if(wt<=maxWt):
            dp[idx][wt] = profit
            print(idx, wt)
            print("ans= ",profit)
            return dp[idx][wt]
        return -1
    
    if wt < 0:
        return -1
    
    # print('hello')
    print(idx, wt)
    dp[idx][wt] = max(knapsack01(wtArray, profitArray, maxWt, wt+wtArray[idx], profit + profitArray[idx], idx+1),
    knapsack01(wtArray, profitArray, maxWt, wt, profit, idx+1))
    return dp[idx][wt]

start_time = time.time()
print(memoKnapsack01(wtArray, profitArray, maxWT))
print("--- %s seconds ---" % (time.time() - start_time))
# print(dp)
# print(dp)