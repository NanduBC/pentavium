'''
This is a naive Python implementation of Trivium
'''
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


# Implementation as per Trivium pseudo code


def run_trivium(max_iterations, log_interval_list):
    print('TRIVIUM PYTHON IMPLEMENTATION')
    start_time = time.time_ns()
    keystream = []
    for i in range(1, max_iterations+1):
        t1 = reg_A[65] ^ reg_A[92]
        t2 = reg_B[68] ^ reg_B[83]
        t3 = reg_C[65] ^ reg_C[110]

        keystream.append(t1 ^ t2 ^ t3)

        t1 = t1 ^ (reg_A[90] & reg_A[91]) ^ reg_B[76]
        t2 = t2 ^ (reg_B[81] & reg_B[82]) ^ reg_C[87]
        t3 = t3 ^ (reg_C[109] & reg_C[110]) ^ reg_A[68]

        reg_A[1:] = reg_A[:-1]
        reg_A[0] = t3
        reg_B[1:] = reg_B[:-1]
        reg_B[0] = t1
        reg_C[1:] = reg_C[:-1]
        reg_C[0] = t2

        if i in log_interval_list:
            time_taken = (time.time_ns() - start_time)/10**9
            print('Time taken {}s for iteration {}'.format(
                time_taken, i))
    return keystream
