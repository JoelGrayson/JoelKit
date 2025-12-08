def partition(lst, start_i, end_i, pivot_i): # returns new position of the pivot
    p = lst[pivot_i] #pivot value

    # 1. Put the pivot at the beginning
    lst[start_i], lst[pivot_i] = lst[pivot_i], lst[start_i]

    # 2. Incorporate every vertex v into the left or right
    # Everything before l_i (left index) belongs to the left (<p)
    # Everything after l_i but before r_i belongs to the right (>p)
    # l_i points to the first element in the right, called r^
    # r_i points to v, the current value under consideration
    l_i = start_i + 1
    for r_i in range(start_i + 1, end_i): 
        v = lst[r_i] #decide if v should be in left or right
        if v > p: #v should be in the right
            continue
        if v <= p: #v should be in the left
            lst[l_i], lst[r_i] = lst[r_i], lst[l_i] #l_i points to r^
            l_i += 1

    # 3. Move pivot to end of the left
    lst[start_i], lst[l_i - 1] = lst[l_i - 1], lst[start_i]
    return l_i - 1 #l_i - 1 is where the pivot is now

