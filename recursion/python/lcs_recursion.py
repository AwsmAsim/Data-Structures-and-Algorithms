str1 = 'leet'
str2 = 'delete'

subSec1= []
subSec2 = []

def subSec(arr, idx = 0, cList = []):
    if idx > len(arr)-1:
        outList.append(cList)
        return None
    
    out1 = list(cList)
    out2 = list(cList)
    out2.append(arr[idx])
    
    subSec(arr, idx + 1, out1)
    
    subSec(arr, idx + 1, out2)