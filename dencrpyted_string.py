string = input()
k = int(input())
dencrpyt = ""

freq = 0
j = 0
while(j < len(string)):
    t = "" 
    freq = 0 

    while (j < len(string) and
        ord(string[j]) >= ord('a') and
        ord(string[j]) <= ord('z')):
                
        
        t += string[j]
        j += 1

    while (j < len(string) and
        ord(string[j]) >= ord('1') and
        ord(string[j]) <= ord('9')):
                
        
        freq = freq * 10 + ord(string[j]) - ord('0')
        j += 1

for j in range(1, freq + 1, 1):
    dencrpyt += t

if (freq == 0):
    dencrpyt += t

print(dencrpyt[k - 1])
print(dencrpyt)

