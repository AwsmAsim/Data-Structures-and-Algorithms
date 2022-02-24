# return 1/0 for counting

def countSubSec(arr, sum1, idx=0, cList=[], cSum=0):
    
    
    if(idx == len(arr)):
        if cSum == sum1:
            return 1
        return 0
        
    lst1 = list(cList)
    lst1.append(arr[idx])
    
    lst2 = list(cList)
    
    left = countSubSec(arr, sum1, idx + 1, lst1, cSum + arr[idx])
    right = countSubSec(arr, sum1 ,idx + 1 , lst2, cSum)
    
    return left + right
    
print(countSubSec([3, 2, 1], 5))