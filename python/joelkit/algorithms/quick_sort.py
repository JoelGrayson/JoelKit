import random
from .partition import partition

def quick_sorted(lst): #-> sorted list
    # Base case: if list is empty or size 1, nothing to be done
    if len(lst) <= 1:
        return lst
    
    # Recursive case: find a pivot (efficiently), then partition the list so the items to the left of the partition are less than the partition and the items to the right of the partition are greater than the partition
    pivot_i = find_pivot_index(0, len(lst))
    pivot = lst[pivot_i]

    left = []
    right = []
    for current_index, current_value in enumerate(lst):
        if current_index == pivot_i:
            continue
        if current_value <= pivot:
            left.append(current_value)
        else:
            right.append(current_value)
    
    sorted_left = quick_sorted(left)
    sorted_right = quick_sorted(right)

    return [*sorted_left, pivot, *sorted_right]



def quick_sort(lst): #sorts the list in place
    quick_sort_helper(lst, 0, len(lst))


def quick_sort_helper(lst, start_i, end_i): #quick sorts the lists inclusive of start_i and exclusive of end_i: [start_i, end_i)
    # Base case: if list is empty or size 1, nothing to be done
    the_range = end_i - start_i
    if the_range == 0 or the_range == 1:
        return
    
    # Recursive case: find a partition (efficiently), then partition the list so the items to the left of the partition are less than the partition and the items to the right of the partition are greater than the partition
    og_pivot_i = find_pivot_index(start_i, end_i)
    new_pivot_i = partition(lst, start_i, end_i, og_pivot_i)

    quick_sort_helper(lst, start_i, new_pivot_i) #quick sort the left side
    quick_sort_helper(lst, new_pivot_i + 1, end_i) #quick sort the right side


def find_pivot_index(start_i, end_i):
    # Naive deterministic implementation would be
    # return start_i

    if start_i == end_i:
        return start_i
    
    return random.randint(start_i, end_i - 1) #exclude end_i as a possibility

