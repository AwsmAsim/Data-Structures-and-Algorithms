wtMatrix = [1, 3, 4, 5]
pMatrix = [3, 4, 5, 7]
maxW = 7

dp = []

for i in range(len(wtMatrix) + 1): # idx
    lst = []
    for j in range(maxW + 1): # W
        lst.append(0)
    dp.append(lst)
        
print('---intial dp---')
for i in dp:
    print(i)
print('\n')

for i in range(len(wtMatrix) + 1): # idx
    for j in range(maxW + 1): # W
        if(i == 0 or j == 0):
            dp[i][j] = 0
        else:
            if(wtMatrix[i-1] < j):
                # print('idx(i):', i, 'W(j):',j)
                # print(dp[i-1][j-wtMatrix[i-1]] + pMatrix[i-1] )
                dp[i][j] = max(pMatrix[i-1] + dp[i-1][j-wtMatrix[i-1]], dp[i-1][j])
            else:
                dp[i][j] = dp[i-1][j]
                
for i in dp:
    print(i)
print('\n')
