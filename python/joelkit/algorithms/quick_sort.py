def quick_sorted(lst): #-> sorted list
    # Base case: if list is empty or size 1, nothing to be done
    if len(lst) <= 1:
        return lst
    
    # Recursive case: find a partition (efficiently), then partition the list so the items to the left of the partition are less than the partition and the items to the right of the partition are greater than the partition
    partition_index = find_partition_index(lst)
    partition_value = lst[partition_index]

    left = []
    right = []
    for current_index, current_value in enumerate(lst):
        if current_index == partition_index:
            continue
        if current_value <= partition_value:
            left.append(current_value)
        else:
            right.append(current_value)
    
    sorted_left = quick_sorted(left)
    sorted_right = quick_sorted(right)

    return [*sorted_left, partition_value, *sorted_right]



def quick_sort(lst): #sorts the list in place
    # Base case: if list is empty or size 1, nothing to be done
    if len(lst) <= 1:
        return
    
    # Recursive case: find a partition (efficiently), then partition the list so the items to the left of the partition are less than the partition and the items to the right of the partition are greater than the partition
    partition_index = find_partition_index(lst)
    partition_value = lst[partition_index]
    for current_index in range(len(lst)):
        if current_index == partition_index:
            continue
        current_value = lst[current_index]
        if current_index < partition_index:
            if current_value <= partition_value:
                continue
            else:
                # Swap partition with current
                lst[partition_index] = current_value
                lst[current_index] = partition_value
                partition_index = current_index

    quick_sort(lst[0:partition_index]) #quick sort the left side
    quick_sort(lst[partition_index+1:]) #quick sort the right side
    lst[2] = 3


def find_partition_index(lst):
    return 0

