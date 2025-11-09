from quick_sort import quick_sort_not_in_place


def k_select(lst, k): #return the kth smallest value
    # Base case O(1)
    if len(lst) < 10:
        return quick_sort_not_in_place(lst)[k] #todo: replace with better sorting

    # General case
    find_partition(lst)

    if k == partition_index:
        return lst[k]
    



GROUP_SIZE = 5
def find_partition(lst):
    current_group = []
    medians = []
    for value in lst:
        if len(current_group) == GROUP_SIZE:
            medians.append(
                quick_sort_not_in_place(current_group)[GROUP_SIZE // 2]
            )
            current_group = []
        current_group.append(value)
    if len(current_group) > 0:
        medians.append(
            quick_sort_not_in_place(current_group)[GROUP_SIZE // 2]
        )
        current_group = []
    
    return k_select(medians, len(medians) // 2)


find_partition(range(13))

