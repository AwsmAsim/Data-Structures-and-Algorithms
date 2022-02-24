import copy
maze = [[1, 1, 0, 0],
        [1, 1, 1, 1],
        [0, 1, 0, 0],
        [0, 1, 1, 1]]

solution_matrix = [[0, 0, 0, 0],
                   [0, 0, 0, 0],
                   [0, 0, 0, 0],
                   [0, 0, 0, 0]]
def solve(x=0, y=0):
    
    if x==len(maze[0])-1 and y == len(maze)-1:
        solution_matrix[x][y] = 1
        return True
    
    if(isSafe(x,y)):
        solution_matrix[x][y] = 1
        
        if solve(x+1, y): 
            return True
        if solve(x, y+1):
            return True
        
        solution_matrix[x][y] = 0
        return False


def isSafe(x, y):
    if(x < len(maze[0]) and y < len(maze) and maze[x][y] == 1):
        return True    
    
solve()
for i in solution_matrix:
    print(i)