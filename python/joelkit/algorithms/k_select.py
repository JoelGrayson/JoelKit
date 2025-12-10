def find_pivot(lst):
    medians = []
    for i in range(0, len(lst), 5):
        five = []
        for j in range(i, i + 5):
            if j >= len(lst):
                break
            five.append((j, lst[j]))
        five.sort(key=lambda x : x[1])
        median = five[len(five) // 2]
        medians.append(median)
    return medians[len(medians) // 2]


def k_select(lst, k):
    if len(lst) < 10:
        return sorted(lst)[k]
    
    pivot_index, pivot_value = find_pivot(lst)
    if k == pivot_index:
        return pivot_value
    
    # Partition
    left = []
    right = []
    for i, item in enumerate(lst):
        if i == pivot_index:
            continue
        if item <= pivot_value:
            left.append(item)
        else:
            right.append(item)
    
    # Recursion
    if k < len(left):
        return k_select(left, k)
    else:
        return k_select(right, k - len(left) - 1)


