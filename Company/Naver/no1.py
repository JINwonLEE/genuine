def solution(A):
    N = len(A[0])   # row
    M = len(A)      # column
    
    count = 0
    for i in range(1,M-1) :
        for j in range(1, N-1):
            # local maximum in row and local minimum in column
            if A[i][j-1] < A[i][j] and A[i][j+1] < A[i][j] and A[i-1][j] > A[i][j] and A[i+1][j] > A[i][j]:
                count += 1
            # local minimum in row and local maximum in column
            elif A[i][j-1] > A[i][j] and A[i][j+1] > A[i][j] and A[i-1][j] < A[i][j] and A[i+1][j] < A[i][j]:
                count += 1
    
    return count
