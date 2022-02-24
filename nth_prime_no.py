'''
inp = int(input())
range = 1000000
primes = []

def SieveOfEratosthenes():
    
    prime = [True for i in range(range + 1)]
    
    p = 2
    while (p * p <= range):
        
        if (prime[p] == True):
        
            for j in range(p * p, range + 1, p):
                prime[j] = False
                
        p += 1
    
    for p in range(2, range + 1):
        if prime[p]:
            primes.append(p)
            
SieveOfEratosthenes()
print(primes[inp])
'''
inp = input1
range1 = 1000000
final_p = []

prime = [True for i in range(range1 + 1)]

p = 2
while (p * p <= range1):
    
    if (prime[p] == True):
    
        for j in range(p * p, range1 + 1, p):
            prime[j] = False
            
    p += 1

for p in range(2, range1 + 1):
    if prime[p]:
        final_p.append(p)
            

return final_p[inp-1]