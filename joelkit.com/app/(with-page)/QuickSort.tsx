'use client';

import Yt from "@/components/Yt";
import videos from "../videos";
import Toggle from "./Toggle";
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter';
import { oneDark } from 'react-syntax-highlighter/dist/esm/styles/prism';
import { Switch } from "@/components/ui/switch";
import { useState } from "react";

export default function QuickSort() {
    const [inPlace, setInPlace] = useState(false);

    return <>
        <Toggle title="Quick Sort">
            <Yt>{videos.quickSort}</Yt>

            <div className="flex items-center space-x-2 my-2">
                <Switch
                    id="in-place-toggle"
                    checked={inPlace}
                    onCheckedChange={setInPlace}
                />
                <label htmlFor="in-place-toggle">In Place</label>
            </div>

            <div>
                <h4>Python</h4>
                <SyntaxHighlighter language="python" style={oneDark}>
                    {inPlace ? quickSortPythonInPlace : quickSortPython}
                </SyntaxHighlighter>
            </div>
            <div>
                <h4>C++</h4>
                <SyntaxHighlighter language="cpp" style={oneDark}>
                    {inPlace ? quickSortCppInPlace : quickSortCpp}
                </SyntaxHighlighter>
            </div>

            <h3>Runtime</h3>
            <p>Expected: O(nlogn)</p>
            <p>Worst case: O(n<sup>2</sup>)</p>
        </Toggle>
    </>;
}


const quickSortPython = `# from joelkit.algorithms import quick_sort

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


def find_pivot_index(start_i, end_i):
    # Naive deterministic implementation would be
    # return start_i

    if start_i == end_i:
        return start_i
    
    return random.randint(start_i, end_i - 1) #exclude end_i as a possibility
`;

const quickSortPythonInPlace = `def quick_sort(lst): #sorts the list in place
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
`;

const quickSortCpp = `
template <typename T>
std::vector<T> quick_sorted(const std::vector<T>& lst) {
    // Base case
    if (lst.size() <= 1)
        return lst;

    // Recursive case
    int pivot_i = find_pivot_index(0, lst.size());
    T pivot = lst[pivot_i];

    std::vector<T> left;
    std::vector<T> right;
    for (int curr_i = 0; curr_i < lst.size(); curr_i++) {
        if (curr_i == pivot_i) {
            continue;
        }
        T curr_val = lst[curr_i];
        if (curr_val <= pivot) {
            left.push_back(curr_val);
        } else {
            right.push_back(curr_val);
        }
    }

    std::vector<T> sorted_left = quick_sorted(left);
    std::vector<T> sorted_right = quick_sorted(right);
    
    std::vector<T> out = sorted_left;
    out.push_back(pivot);
    out.insert(out.end(), sorted_right.begin(), sorted_right.end());
    return out;
}

int find_pivot_index(int start_i, int end_i) {
    if (start_i == end_i)
        return start_i;

    return start_i + rand() % (end_i - start_i);
}`;

const quickSortCppInPlace = `
template <typename T>
void quick_sort_helper(std::vector<T>& lst, int start_i, int end_i) {
    int the_range = end_i - start_i;
    if (the_range == 0 || the_range == 1)
        return;
    
    int og_pivot_i = find_pivot_index(start_i, end_i);
    int new_pivot_i = partition(lst, start_i, end_i, og_pivot_i);

    quick_sort_helper(lst, start_i, new_pivot_i);
    quick_sort_helper(lst, new_pivot_i + 1, end_i);
}

template <typename T>
void quick_sort(std::vector<T>& lst) {
    quick_sort_helper(lst, 0, lst.size());
}

int find_pivot_index(int start_i, int end_i) {
    if (start_i == end_i)
        return start_i;

    return start_i + rand() % (end_i - start_i);
}`;
