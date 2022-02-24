str1 = 'ABCUDKEOF'
str2 = 'A1C2D3333E4F'
'ACDEF'
def lcs_recursion(lcs = '', idx1 = 0, idx2 = 0):
    
    
    if idx1 == len(str1) and idx2 == len(str2):
        return lcs
    
    # print(idx1 + 1, idx2 + 1)
    if(idx1 < len(str1) and idx2 < len(str2) and str1[idx1] == str2[idx2]):
        return (lcs + str1[idx1] + lcs_recursion(lcs, idx1+1, idx2+1))
    else:
        lcs1 = ''
        lcs2 = ''
        if(idx1 < len(str1)-1):
            lcs1 = lcs + lcs_recursion(lcs, idx1+1, idx2)
        if(idx2 < len(str2)-1):
            lcs1 = lcs + lcs_recursion(lcs, idx1, idx2+1)
        if(len(lcs1) > len(lcs2)):
            return lcs1
        else:
            return lcs2
        
    return lcs

        
print(lcs_recursion())