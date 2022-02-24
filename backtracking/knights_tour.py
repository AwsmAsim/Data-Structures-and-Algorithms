global path_x, path_y, size, board

path_x = [-1, -2, 2, -1, +1, +2, +2, +1]
path_y = [-2, -1, +1, +2, +2, +1, -1, -2]

board = [[-1 for i in range(8)] for j in range(8)]
size = 8 # here

def is_valid_move(board, x, y):
    
    # print(x, y)
    if 0 <= x < size and 0 <= y < size and board[x][y] == -1:
        return True
    return False

def knights_tour(board, row=0, col=0, step=1):
    # print(step)
    
    if (step == size**2):
        return True
    
    for i in range(size):
        
        row_new = row + path_x[i]
        col_new = col + path_y[i]
        
        if is_valid_move(board, row_new, col_new):
            board[row_new][col_new] = step
            
            if knights_tour(board, row_new, col_new, step + 1):
                return True
            
            board[row_new][col_new] = -1
    return False


print(knights_tour(board))        
board[0][0] == -1
print(board)

