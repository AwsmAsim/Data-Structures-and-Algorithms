# paramatarised recursion for printing 

outList = []
# paramiterised
def subSecSum(arr, sum1, idx = 0, cList = [], cSum = 0):
    if idx == len(arr): 
        if cSum == sum1:
            outList.append(cList)
        return None 
    
    

    
    out1 = list(cList)
    out2 = list(cList)
    out2.append(arr[idx])
    sum2 = cSum + arr[idx]
    
    print('CALL: ', out1, cSum)
    print('CALL2: ', out2, sum2)
    
    subSecSum(arr, sum1, idx + 1, out1, cSum)
    subSecSum(arr, sum1, idx + 1, out2, sum2)