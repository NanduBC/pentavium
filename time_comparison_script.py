import sys

import src_py.pentavium as pentavium
import src_py.cavium as cavium
import src_py.trivium as trivium

MAX_ITERATIONS = int(sys.argv[1])
LOG_ITERATIONS_LIST = [32, 144, 1152, MAX_ITERATIONS]

trivium_keystream = trivium.run_trivium(MAX_ITERATIONS, LOG_ITERATIONS_LIST)[:100]
print(''.join(list(map(str, trivium_keystream))))
cavium_keystream = cavium.run_cavium(MAX_ITERATIONS, LOG_ITERATIONS_LIST)[:100]
print(''.join(list(map(str, cavium_keystream))))
pentavium_keystream = pentavium.run_pentavium(MAX_ITERATIONS, LOG_ITERATIONS_LIST)[:100]
print(''.join(list(map(str, pentavium_keystream))))
