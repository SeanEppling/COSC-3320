import random
import time

n = [16, 64, 256, 1024, 4096, 16384]
iter = 0

with open('results.txt', 'w') as outfs:
    outfs.write("m = 13421772800\n")
    
    while iter < 6:
        a, b, x = 0, 0, 0
        m = [[2 for _ in range(n[iter])] for _ in range(n[iter])]

        m_size = 13421772800
        t_start = time.time()

        for i in range(m_size):
            x = random.randint(1, 100)
            a = random.randint(0, n[iter] - 1)
            b = random.randint(0, n[iter] - 1)
            m[a][b] = m[a][b] + x

        t_end = time.time() - t_start
        outfs.write(f"n = {n[iter]} takes {t_end} seconds\n")
        iter += 1
