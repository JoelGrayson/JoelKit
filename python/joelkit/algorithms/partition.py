def partition(lst, pivot_index):
    # Make the pivot at the start O(1)
    lst[0], lst[pivot_index] = lst[pivot_index], lst[0]

    p = lst[0] #pivot

    lIndex = 1 #everything before lIndex belongs to L (<p)

    # while rIndex < len(lst):
    for rIndex in range(1, len(lst)): #everything after lIndex but before rIndex belongs to R (>p)
        value = lst[rIndex] #current value to decide if in L or R
        if value > p: #value is part of R
            continue
        if value <= p: #value is part of L
            lst[lIndex], lst[rIndex] = lst[rIndex], lst[lIndex]
            lIndex += 1

    # Move pivot to end of L
    lst[0], lst[lIndex - 1] = lst[lIndex - 1], lst[0]

