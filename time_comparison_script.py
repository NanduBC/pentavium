import src_py.pentavium as pentavium
import src_py.cavium as cavium
import src_py.trivium as trivium

MAX_ITERATIONS = 100000
LOG_ITERATIONS_LIST = [32, 144, 1152, MAX_ITERATIONS]

trivium.run_trivium(MAX_ITERATIONS, LOG_ITERATIONS_LIST)
cavium.run_cavium(MAX_ITERATIONS, LOG_ITERATIONS_LIST)
pentavium.run_pentavium(MAX_ITERATIONS, LOG_ITERATIONS_LIST)
