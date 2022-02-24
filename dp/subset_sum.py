given_array = [2, 3, 7, 8, 10]

subsets = []


def subsetPresent(given_array, sum1, idx = 0):
    
    if idx == len(given_array):
        if sum1 == 0:
            return True
        return False   
    
    subsetPresent(given_array, sum1 - given_array[idx], idx + 1)
    subsetPresent(given_array, sum1, idx + 1)

































# def subsetSum(given_array, sum1, idx = 0, cList = []):
    
#     # print(given_array[idx])
#     if idx == len(given_array) or sum1 == 0:
#         if sum1 == 0:
#             subsets.append(cList)
#         return
    
#     lst1 = list(cList)
#     lst1.append(given_array[idx])
#     print('lst1:', lst1)
#     print(sum1)
#     lst2 = list(cList)
    
#     if given_array[idx] <= sum1:
#         subsetSum(given_array, sum1 - given_array[idx], idx + 1, lst1)
#         subsetSum(given_array, sum1, idx + 1, lst2)
#     else:
#         subsetSum(given_array, sum1, idx + 1, lst2)
    
# sum_obtained = subsetSum(given_array, 10)


# # print(sum_obtained)
# print(subsets)