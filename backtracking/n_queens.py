
board = [[0, 0, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0]]


boards = []

def n_Queens(board, size, x = 0):
    
    if x == len(board):
        boards.append(board)
        return board
    
    for y in range(len(board[0])):
        if isSafe(x,y):
            board[x][y] = 1
            print(board)
            
            if(n_Queens(board, size, x+1)):
                return True
            
            board[x][y] = 0
    return False    
        
    
def isSafe(x, y):
    
    # print(x, y)
    x1, y1 = x, y
    for i in range(x1):
        if board[i][y1] == 1:
            return False
        # print('x1', x1, 'y1', y1)
        x1 -= 1

    x1, y1 = x, y
    while x1 >= 0 and y1 >= 0:
        if board[x1][y1] == 1:
            return False
        x1 -= 1
        y1 -= 1
    
    x1, y1 = x, y
    while x1 < len(board[0]) and y1 < len(board):
        if board[x1][y1] == 1:
            return False
        x1 += 1
        y1 -= 1
    
    return True
        
n_Queens(board, len(board), 0)

for i in board:
    print(i)
    
print(boards)
        
    