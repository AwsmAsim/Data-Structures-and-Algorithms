# Given 5 arrays of 50 elements each, find out the elements that are in atleast two arrays
import random

# GIVEN: 
arrays = [list(), list(), list(), list(), list()]
for i in range(len(arrays)):
    arrays[i] = [random.randrange(1, 100) for i in range(50)]

# ANSWER:    
outL = [] # stores the answer
hashMap = dict() # stores no of the arrays the no is present in 
i=0
for array in arrays: 
    set1 = set() # Checks for duplicates in that array
    for j in array:
        if j not in set1:
            hashMap[j] = hashMap.get(j, 0) + 1
            set1.add(j)

print('Given Arrays: ')
print(arrays[0])
print(arrays[1])
print(arrays[2])
print(arrays[3])
print(arrays[4])

for i in hashMap:
    if hashMap[i] > 1:
        outL.append(i)
        
print('\nAnswer:')
print(sorted(outL)) # Print answer
# Time Complexity: k x O(n), where k is no of arrays and n is no of elements in each array. Extra n*log(n) if sorting, not essentially required though.

# In case of required of element present in atleast one, we can print all the elements in the hashmap
