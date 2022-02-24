# True False is used for when returning one answer and it is not about counting

outList = []
def subSecSum(arr, sum1, idx = 0, cList = [], cSum = 0):
    if idx == len(arr): 
        if cSum == sum1:
            outList.append(cList)
            return True
        return False 
    
    # if cSum == sum1:
    #     print(cList)
    #     return True

    
    out1 = list(cList)
    out2 = list(cList)
    out2.append(arr[idx])
    sum2 = cSum + arr[idx]
    
    # print('CALL: ', out1, cSum)
    # print('CALL2: ', out2, sum2)
    
    if(subSecSum(arr, sum1, idx + 1, out1, cSum) == True): return True
    if(subSecSum(arr, sum1, idx + 1, out2, sum2)): return True
    
    return False
    
print(subSecSum([1,2,1], 2))
print(outList)