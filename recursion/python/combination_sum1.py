def combinationSum( candidates: list[int], target: int) -> list[list[int]]:
    arr = candidates
    outList = []
    def findCombinations(idx = 0, sum2 = target, cList = []):
        
        if idx > len(arr)-1: 
            if sum2 == 0:
                outList.append(cList)
            return
        
        if sum2 < 0: # Considering that sum2 is not negative
            return
                
        lst1 = list(cList)
        lst1.append(arr[idx])
        lst2 = list(cList)
        
        findCombinations(idx, sum2 - arr[idx], lst1)
        findCombinations(idx + 1, sum2, lst2)
        
    findCombinations()
    return outList

arr = [10,1,2,7,6,1,5]
target = 8
outL = combinationSum(arr, target)
print(outL)