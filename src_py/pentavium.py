'''
This is a naive Python implementation of Pentavium
'''
import time
from functools import lru_cache

PENTAVIUM_INIT_LEN = 32
# Rules:
# 1 --> 1721342310
# 2 --> 2523490710
# 3 --> 1452976485
# 4 --> 1520018790
# The rules are ordered in N, L, L, N, L, N, N, L
ca_rule_order = [3, 1, 2, 4, 1, 3, 4, 2]
treg_X = [0] * 110


@lru_cache(maxsize=128)
def five_neighborhood_cellular_automata(
        s_minus_two,
        s_minus_one,
        s,
        s_plus_one,
        s_plus_two,
        rule_mappings):
    '''
    Find the next state of cell s based on the values of s_minus_two,
    s_minus_one, s, s_plus_one and s_plus_two and the rule.

    Parameters:
    ----------
    s_minus_two: State of left-left cell at i th clock cycle
    s_minus_one: State of left cell at i th clock cycle
    s: State of the cell at i th clock cycle
    s_plus_one: State of right cell at i th clock cycle
    s_plus_two: State of right-right cell at i th clock cycle
    rule_mappings: Shorthand for rule numbers that would be used to
        determine the rule to be used at each cell

    Returns:
    -------
    State of s in the i+1 th clock cycle
    '''
    if rule_mappings == 1:
        return s_minus_two ^ s_minus_one ^ s_plus_one ^ s_plus_two
    elif rule_mappings == 2:
        return s_minus_two ^ s_minus_one ^ s ^ s_plus_one ^ s_plus_two
    elif rule_mappings == 3:
        return s_plus_two ^ (s_plus_one & s) ^ (s_plus_one & s_minus_one) ^ s ^ s_minus_two ^ 1
    elif rule_mappings == 4:
        return s_plus_two ^ (s_plus_one & s_minus_one) ^ (s & s_minus_one) ^ s_minus_one ^ s_minus_two


def apply_CA_to_blocks(reg_X):
    '''
    Apply approapriate CA rule to each cell of the block registers
    except the last register

    Parameters:
    ----------
    reg_X: reg_A, reg_B, reg_C

    Returns:
    -------
    A temporary register with CA values of each cell calculated

    Notes:
    -----
    Since CA is null boundary first, second, second last and
    last elements might have some neighbors as 0
    '''
    for i in range(len(reg_X)-1):
        rule_mappings = ca_rule_order[i % 8]
        if i == 0:
            treg_X[i] = five_neighborhood_cellular_automata(0, 0, reg_X[i], reg_X[i+1], reg_X[i+2], rule_mappings)
        elif i == 1:
            treg_X[i] = five_neighborhood_cellular_automata(0, reg_X[i-1], reg_X[i], reg_X[i+1], reg_X[i+2], rule_mappings)
        elif i == (len(reg_X) - 2):
            treg_X[i] = five_neighborhood_cellular_automata(reg_X[i-2], reg_X[i-1], reg_X[i], reg_X[i+1], 0, rule_mappings)
        else:
            treg_X[i] = five_neighborhood_cellular_automata(reg_X[i-2], reg_X[i-1], reg_X[i], reg_X[i+1], reg_X[i+2], rule_mappings)
    return treg_X[:len(reg_X)-1]


reg_A = [0] * 93
reg_B = [0] * 84
reg_C = [0] * 111

reg_C[108] = reg_C[109] = reg_C[110] = 1

key = '00101110110000000110010101111101000011011100110100101111011001010101110010011001'
init_vector = '01001111010101010111110111010110101011110010110100001100010000010111101100100000'

# Initialising key and init vector
reg_A[:80] = list(map(int, list(key)))
reg_B[:80] = list(map(int, list(init_vector)))


# Implementation as per Pentavium pseudo code


def run_pentavium(max_iterations):
    print('PENTAVIUM PYTHON IMPLEMENTATION')
    start_time = time.time_ns()
    for i in range(PENTAVIUM_INIT_LEN):
        t1 = reg_A[65] ^ reg_A[92]
        t2 = reg_B[68] ^ reg_B[83]
        t3 = reg_C[65] ^ reg_C[110]

        t1 = t1 ^ (reg_A[90] & reg_A[91]) ^ reg_B[76]
        t2 = t2 ^ (reg_B[81] & reg_B[82]) ^ reg_C[87]
        t3 = t3 ^ (reg_C[109] & reg_C[110]) ^ reg_A[68]

        reg_A[1:] = apply_CA_to_blocks(reg_A)
        reg_A[0] = t3
        reg_B[1:] = apply_CA_to_blocks(reg_B)
        reg_B[0] = t1
        reg_C[1:] = apply_CA_to_blocks(reg_C)
        reg_C[0] = t2

    init_phase_time = (time.time_ns() - start_time)/10**9
    print('Initialization phase time: {}seconds  Iterations: {}'.format(
        init_phase_time, PENTAVIUM_INIT_LEN))

    keystream = []
    start_time = time.time_ns()
    for i in range(1, max_iterations+1):
        t1 = reg_A[65] ^ reg_A[92]
        t2 = reg_B[68] ^ reg_B[83]
        t3 = reg_C[65] ^ reg_C[110]

        keystream.append(t1 ^ t2 ^ t3)

        t1 = t1 ^ (reg_A[90] & reg_A[91]) ^ reg_B[76]
        t2 = t2 ^ (reg_B[81] & reg_B[82]) ^ reg_C[87]
        t3 = t3 ^ (reg_C[109] & reg_C[110]) ^ reg_A[68]

        reg_A[1:] = apply_CA_to_blocks(reg_A)
        reg_A[0] = t3
        reg_B[1:] = apply_CA_to_blocks(reg_B)
        reg_B[0] = t1
        reg_C[1:] = apply_CA_to_blocks(reg_C)
        reg_C[0] = t2

    keygen_phase_time = (time.time_ns() - start_time)/10**9
    print('Keystream phase time: {}seconds  Iterations: {}'.format(
        keygen_phase_time, max_iterations))
    return keystream
