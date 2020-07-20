'''
This is a naive Python implementation of CAvium
'''
import time

# Rules:
# 1 --> 30
# 2 --> 60
# 3 --> 90
# 4 --> 120
# 5 --> 150
# 6 --> 180
# 7 --> 210
# 8 --> 240
ca_rule_order = [1, 2, 3, 4, 5, 6, 7, 8]
treg_X = [0] * 110


def three_neighborhood_cellular_automata(
        s_minus_one,
        s,
        s_plus_one,
        rule_mappings):
    '''
    Find the next state of cell s based on the values of s_minus_one,
    s, s_plus_one and the rule.
    Parameters:
    ----------
    s_minus_one: State of left cell at i th clock cycle
    s: State of the cell at i th clock cycle
    s_plus_one: State of right cell at i th clock cycle
    rule_mappings: Shorthand for rule numbers that would be used to
        determine the rule to be used at each cell
    
    Returns: 
    -------
    State of s in the i+1 th clock cycle
    '''
    if rule_mappings == 1:
        return s_minus_one ^ s ^ s_plus_one ^ (s & s_plus_one)
    elif rule_mappings == 2:
        return s_minus_one ^ s
    elif rule_mappings == 3:
        return s_minus_one ^ s_plus_one
    elif rule_mappings == 4:
        return s_minus_one ^ (s & s_plus_one)
    elif rule_mappings == 5:
        return s_minus_one ^ s ^ s_plus_one
    elif rule_mappings == 6:
        return s_minus_one ^ s ^ (s & s_plus_one)
    elif rule_mappings == 7:
        return s_minus_one ^ s_plus_one ^ (s & s_plus_one)
    elif rule_mappings == 8:
        return s_minus_one


def apply_CA_to_blocks(reg_X):
    '''
    Apply approapriate CA rule to each cell of the block registers
    except the last register
    Parameters:
    ----------
    reg_X: reg_A, reg_B, reg_C

    Returns:
    -------
    A temporary register with CA applied to the reg_X

    Notes:
    -----
    Since CA is null boundary first elements have one neighbor as 0
    '''
    for i in range(len(reg_X)-1):
        rule_mappings = ca_rule_order[i % 8]
        if i == 0:
            treg_X[i] = three_neighborhood_cellular_automata(0, reg_X[i], reg_X[i+1], rule_mappings)
        else:
            treg_X[i] = three_neighborhood_cellular_automata(reg_X[i-1], reg_X[i], reg_X[i+1], rule_mappings)
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

# Implementation as per CAvium pseudo code


def run_cavium(max_iterations, log_interval_list):
    print('CAVIUM')
    start_time = time.time_ns()
    for i in range(1, max_iterations+1):
        t1 = reg_A[65] ^ reg_A[92]
        t2 = reg_B[68] ^ reg_B[83]
        t3 = reg_C[65] ^ reg_C[110]

        output_bit = t1 ^ t2 ^ t3

        t1 = t1 ^ (reg_A[90] & reg_A[91]) ^ reg_B[76]
        t2 = t2 ^ (reg_B[81] & reg_B[82]) ^ reg_C[87]
        t3 = t3 ^ (reg_C[109] & reg_C[110]) ^ reg_A[68]

        reg_A[1:] = apply_CA_to_blocks(reg_A)
        reg_A[0] = t3
        reg_B[1:] = apply_CA_to_blocks(reg_B)
        reg_B[0] = t1
        reg_C[1:] = apply_CA_to_blocks(reg_C)
        reg_C[0] = t2

        if i in log_interval_list:
            time_taken = (time.time_ns() - start_time)/10**9
            print('Time taken {} for iteration {}'.format(
                time_taken, i))
