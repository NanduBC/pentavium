import time

reg_A = [0] * 93
reg_B = [0] * 84
reg_C = [0] * 111

reg_C[108] = reg_C[109] = reg_C[110] = 1

key = '00101110110000000110010101111101000011011100110100101111011001010101110010011001'
init_vector = '01001111010101010111110111010110101011110010110100001100010000010111101100100000'

# Initialising key and init vector
reg_A[:80] = list(map(int, list(key)))
reg_B[:80] = list(map(int, list(init_vector)))

start_time = time.time_ns()
# Implementation as per Trivium source code
for i in range(1, 100001):
    t1 = reg_A[65] ^ reg_A[92]
    t2 = reg_B[68] ^ reg_B[83]
    t3 = reg_C[65] ^ reg_C[110]

    T1 = t1 ^ (reg_A[90] & reg_A[91]) ^ reg_B[76]
    T2 = t2 ^ (reg_B[81] & reg_B[82]) ^ reg_C[87]
    T3 = t3 ^ (reg_C[109] & reg_C[110]) ^ reg_A[68]

    reg_A.pop()
    reg_A.insert(0, T1)
    reg_B.pop()
    reg_B.insert(0, T2)
    reg_C.pop()
    reg_C.index(0, T3)

    output_bit = t1 ^ t2 ^ t3
    if i in [32, 144, 1152, 100000]:
        time_taken = (time.time_ns() - start_time)/10**9
        print('Time taken {} for iteration {}'.format(
            time_taken, i))
