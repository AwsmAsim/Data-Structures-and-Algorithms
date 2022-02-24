a = 'sYOCa'
b = 'YOCN'
answer = 'NO'

# a_pointer, b_pointer = len(a) - 1, len(b) - 1

# while(a_pointer >= 0): # a_pointer will be minimum at the zero index of a
    
#     if(b[b_pointer] == a[a_pointer]):
#         b_pointer -= 1
#         a_pointer -= 1
#     elif b[b_pointer] == a[a_pointer].upper():
#         a[a_pointer] = a[a_pointer].upper()
#         b_pointer -= 1
#         a_pointer -= 1
#     else:
#         if a[a_pointer] == a[a_pointer].lower():
#             a = a[:a_pointer] + a[:a_pointer+1:] 
#             print('after removing:', a)
#         else:
#             print(answer)

# NAIVE RECUSION APPROACH
subSecs = []
def subSec(idx = 0, cSubSec=[]):
    
    if(idx == len(a)):
        subSecs.append(''.join(cSubSec))
        return
    
    list1 = list(cSubSec)
    list2 = list(cSubSec)
    # print(idx)
    list1.append(a[idx].upper())
    
    subSec(idx + 1, list1)
    subSec(idx + 1, list2)
    
subSec()

if b in subSecs:
    print('YES')
else:
    print('NO')