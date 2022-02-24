def sortArray(arr):
    
    if len(arr) < 2:
        return arr
    
    if(arr[-1]>arr[0]):
        first, last = arr[0], arr[-1]
    else:
        first, last = arr[-1], arr[0]
    
    return [first] + sortArray(arr[1:-1]) + [last]

def sortArray1(arr):
    # Base case to be implemented
    if(len(arr) < 1): return arr
    
    # hypothesis
    lastElement = arr[-1]
    arr = sortArray(arr[:-1])
    
    # induction
    return insert(arr, lastElement)
    
    

def insert(arr, element):
    if(len(arr) == 0 or element > arr[-1]):
        arr.append(element)
        return arr
    
    e1 = arr.pop()
    arr = insert(arr, element)
    arr.append(e1)
    return arr

arr = [9,8,7,6,5]
print(sortArray1(arr))
print(arr)
    