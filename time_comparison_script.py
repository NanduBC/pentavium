import sys

import src_py.pentavium as pentavium
import src_py.cavium as cavium
import src_py.trivium as trivium

MAX_ITERATIONS = int(sys.argv[1])

trivium_keystream = trivium.run_trivium(MAX_ITERATIONS)[:100]
print(''.join(list(map(str, trivium_keystream))))
cavium_keystream = cavium.run_cavium(MAX_ITERATIONS)[:100]
print(''.join(list(map(str, cavium_keystream))))
pentavium_keystream = pentavium.run_pentavium(MAX_ITERATIONS)[:100]
print(''.join(list(map(str, pentavium_keystream))))
