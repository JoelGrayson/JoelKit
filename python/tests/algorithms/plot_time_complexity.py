import matplotlib.pyplot as plt
import time
import numpy as np

UPPER_BOUND = 10_000

def plot_time_complexity(sorting_fn):
    xs = np.arange(0, UPPER_BOUND + 1, 100) #length of list
    ys = [None for _ in range(len(xs))] #ms it takes to sort a list of size x
    lists = list(map(lambda x : np.random.random(x), xs)) #create a list of random numbers of length x

    # Time test
    for i, l in enumerate(lists):
        start = time.perf_counter()
        sorting_fn(l)
        end = time.perf_counter()
        ys[i] = end - start

    plt.title(f'Time Complexity of {sorting_fn.__name__}')
    plt.plot(xs, ys)
    plt.show()

