import time

n = 100
while(n <= 51200):
    print(n)
    A = [[1 for _ in range(n)] for _ in range(n)]
    B = [[1 for _ in range(n)] for _ in range(n)]
    C = [[0 for _ in range(n)] for _ in range(n)]
    #print(n)
    # Iterating through the rows of the matrices
    start = time.time()
    #print(start)
    for i in range(n):
        for j in range(n):
            C[i][j] = A[i][j] + B[i][j]
    end = time.time()
    #print(end)
    elapsed_seconds = end - start
    print("Row order took", elapsed_seconds, "seconds")

    # Iterating through the columns of the matrices
    start = time.time()
    #print(start)
    for j in range(n):
        for i in range(n):
            C[i][j] = A[i][j] + B[i][j]
    end = time.time()
    #print(end)
    elapsed_seconds = end - start
    print("Column order took", elapsed_seconds, "seconds")
    n = n*2
    print()