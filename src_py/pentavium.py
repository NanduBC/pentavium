import time

# Rules:
# 1 --> 1721342310
# 2 --> 2523490710
# 3 --> 1452976485
# 4 --> 1520018790
ca_rule_order = [3, 1, 2, 4, 1, 3, 4, 2]


def five_neighborhood_cellular_automata(
        s_minus_two,
        s_minus_one,
        s,
        s_plus_one,
        s_plus_two,
        rule_index):
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
    rule_index: Rule mapping

    Returns:
    -------
    State of s in the i+1 th clock cycle
    '''
    if rule_index == 1:
        return s_minus_two ^ s_minus_one ^ s ^ s_plus_one ^ s_plus_two
    elif rule_index == 2:
        return s_minus_two ^ s_minus_two ^ s_plus_one ^ s_plus_two
    elif rule_index == 3:
        return s_plus_one & (1 ^ s_plus_two ^ s_minus_two ^ s_minus_one) | (1 ^ s_plus_one) & (1 ^ s_plus_two ^ s_minus_two ^ s)
    elif rule_index == 4:
        return (1 ^ s_minus_one) & (s_minus_two ^ s_plus_one ^ s_plus_two) | s_minus_one & (1 ^ s_minus_two ^ s ^ s_plus_two)


def apply_CA_to_blocks(reg_X):
    '''
    Apply approapriate CA rule to each cell of the block registers

    Parameters:
    ----------
    reg_X: reg_A, reg_B, reg_C

    Notes:
    -----
    Since CA is null boundary first, second, second last and
    last elements might have some neighbors as 0
    '''
    for i in range(len(reg_X)):
        rule_index = ca_rule_order[i%8]
        if i == 0:
            reg_X[i] == five_neighborhood_cellular_automata(0, 0, reg_X[i], reg_X[i+1], reg_X[i+2], rule_index)
        elif i == 1:
            reg_X[i] == five_neighborhood_cellular_automata(0, reg_X[i-1], reg_X[i], reg_X[i+1], reg_X[i+2], rule_index)
        elif i == (len(reg_X) - 2):
            reg_X[i] == five_neighborhood_cellular_automata(reg_X[i-2], reg_X[i-1], reg_X[i], reg_X[i+1], 0, rule_index)
        elif i == (len(reg_X) - 1):
            reg_X[i] == five_neighborhood_cellular_automata(reg_X[i-2], reg_X[i-1], reg_X[i], 0, 0, rule_index)
        else:
            reg_X[i] == five_neighborhood_cellular_automata(reg_X[i-2], reg_X[i-1], reg_X[i], reg_X[i+1], reg_X[i+2], rule_index)


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
    apply_CA_to_blocks(reg_A)
    reg_A.insert(0, T1)
    reg_B.pop()
    apply_CA_to_blocks(reg_B)
    reg_B.insert(0, T2)
    reg_C.pop()
    apply_CA_to_blocks(reg_C)
    reg_C.index(0, T3)

    output_bit = t1 ^ t2 ^ t3
    if i in [32, 144, 1152, 100000]:
        time_taken = (time.time_ns() - start_time)/10**9
        print('Time taken {} for clock cycle {}'.format(
            time_taken, i))
