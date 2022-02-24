top = -1

def sortStack(stack):
    
    if(len(stack)==0):
        return stack
    
    #hypothesis
    lastElement = stack.pop()
    stack = sortStack(stack)
    
    return insert(stack, lastElement)
    
def insert(stack, lastElement):
    
    if(len(stack) == 0 or stack[top] < lastElement):
        stack.append(lastElement)
        return stack
    
    lastElement1 = stack.pop()
    stack = insert(stack, lastElement)
    stack.append(lastElement1)
    
    return stack
    

stack = [6, 5, 4, 3, 2, 1]
sortStack(stack)
print(stack)
