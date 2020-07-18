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

reg_A = [0] * 93
reg_B = [0] * 84
reg_C = [0] * 111

reg_C[108] = reg_C[109] = reg_C[110] = 1
    
t_reg_A = [0] * 93
t_reg_B = [0] * 84
t_reg_C = [0] * 111

def three_neighborhood_cellular_automata(
        s_minus_one,
        s,
        s_plus_one,
        rule_index):
    '''
    Find the next state of cell s based on the values of s_minus_one,
    s, s_plus_one and the rule_index which provides the rule to apply.
    Parameters:
    ----------
    s_minus_one:
    s:
    s_plus_one:
    rule_index
    Returns:
    -------
    State of s in the next clock cycle
    '''
    if rule_index == 1:
        return (1 ^ s_minus_one) & s_plus_one | (1 ^ s_plus_one) & (s_minus_one ^ s)
    elif rule_index == 2:
        return s_minus_one ^ s
    elif rule_index == 3:
        return s_minus_one ^ s_plus_one
    elif rule_index == 4:
        return s_plus_one & (s_minus_one ^ s) | s_minus_one & (1 ^ s_plus_one)
    elif rule_index == 5:
        return s_minus_one ^ s ^ s_plus_one
    elif rule_index == 6:
        return s_minus_one & s_plus_one | (1 ^ s_plus_one) & (s_minus_one ^ s)
    elif rule_index == 7:
        return (1 ^ s) & (s_minus_one ^ s_plus_one) | s_minus_one & s
    elif rule_index == 8:
        return s_minus_one

def parse_register(
    index,
    register_block):
    '''
    Parse register values to satisfy null boundary CA
    Parameters:
    ----------
    index:
    register_block:
    '''
    if register_block == 93:
        if index == 0:
            return [0, reg_A[index], reg_A[index+1]]
        else:
            return [reg_A[index-1], reg_A[index], reg_A[index+1]]
    if register_block == 84:
        if index==0:
            return [0, reg_B[index], reg_B[index+1]]
        else:
            return [reg_B[index-1], reg_B[index], reg_B[index+1]]
    if register_block == 111:
        if index == 0:
            return [0, reg_C[index], reg_C[index+1]]
        else:
            return [reg_C[index-1], reg_C[index], reg_C[index+1]]

def apply_CA_to_blocks():
    '''
    Apply approapriate CA rule to each cell of the block registers
    Parameters:
    ----------
    '''
    for x in range(0,92):
        s_minus_one, s, s_plus_one = parse_register(x,93)
        t_reg_A[x+1] = three_neighborhood_cellular_automata(s_minus_one, s, s_plus_one, ca_rule_order[(x%8)-1])
    for x in range(0,83):
        s_minus_one, s, s_plus_one = parse_register(x,84)
        t_reg_B[x+1] = three_neighborhood_cellular_automata(s_minus_one, s, s_plus_one, ca_rule_order[(x%8)-1])
    for x in range(0,110):
        s_minus_one, s, s_plus_one = parse_register(x,111)
        t_reg_C[x+1] = three_neighborhood_cellular_automata(s_minus_one, s, s_plus_one, ca_rule_order[(x%8)-1])

    return [t_reg_A, t_reg_B, t_reg_C]



key = '00101110110000000110010101111101000011011100110100101111011001010101110010011001'
init_vector = '01001111010101010111110111010110101011110010110100001100010000010111101100100000'

# Initialising key and init vector
reg_A[:80] = list(map(int, list(key)))
reg_B[:80] = list(map(int, list(init_vector)))

print('CAVIUM')
start_time = time.time_ns()
# Implementation as per Trivium source code
for i in range(1, 100001):
    t1 = reg_A[65] ^ reg_A[92]
    t2 = reg_B[68] ^ reg_B[83]
    t3 = reg_C[65] ^ reg_C[110]

    T1 = t1 ^ (reg_A[90] & reg_A[91]) ^ reg_B[76]
    T2 = t2 ^ (reg_B[81] & reg_B[82]) ^ reg_C[87]
    T3 = t3 ^ (reg_C[109] & reg_C[110]) ^ reg_A[68]

    [reg_A, reg_B, reg_C] = apply_CA_to_blocks()

    reg_A[0] = T3
    reg_B[0] = T1
    reg_C[0] = T2

    output_bit = t1 ^ t2 ^ t3
    if i in [32, 144, 1152, 100000]:
        time_taken = (time.time_ns() - start_time)/10**9
        print('Time taken {} for iteration {}'.format(
            time_taken, i))
















































