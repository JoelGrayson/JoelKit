import Yt from "@/components/Yt";
import videos from "../../videos";
import Toggle from "../Toggle";
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter';
import { oneDark } from 'react-syntax-highlighter/dist/esm/styles/prism';

export default function Partition() {
    return <>
        <Toggle title="Partition">
            {/* <Yt>{videos.kSelect}</Yt> */}

            <p>partition(list, pivot) - partitions the list such that all the elements to the left of the pivot are less than the pivot and all the elements to the right of the pivot are greater than the pivot. In our implementation, pivot has the start index, end index, and pivot index passed in of the list so that it can do in-place partitioning just for the sublist from the start to end index. It also returns the new index of the pivot (since the pivot moves around during the partition function&apos;s work).</p>

            <div>
                <h4>Python</h4>
                <SyntaxHighlighter language="python" style={oneDark}>
                    {partitionPy}
                </SyntaxHighlighter>
            </div>
            <div>
                <h4>C++</h4>
                <SyntaxHighlighter language="cpp" style={oneDark}>
                    {partitionCpp}
                </SyntaxHighlighter>
            </div>
        </Toggle>
    </>;
}

const partitionPy = `# from joelkit.algorithms import partition

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
    return l_i - 1 #l_i - 1 is where the pivot is now`

const partitionCpp = `#include "partition.h"

template <typename T>
int partition(std::vector<T>& lst, int start_i, int end_i, int pivot_i) {
    T p = lst[pivot_i];

    // 1. Put pivot at beginning
    lst[pivot_i] = lst[start_i];
    lst[start_i] = p;

    // 2.
    int l_i = start_i + 1;
    for (int r_i = start_i + 1; r_i < end_i; r_i++) {
        T v = lst[r_i];
        if (v > p) {
            continue;
        }
        if (v <= p) {
            T rhat = lst[l_i];
            lst[l_i] = lst[r_i];
            lst[r_i] = rhat;
            l_i++;
        }
    }
    // 3. Move pivot to end of the left
    lst[start_i] = lst[l_i - 1];
    lst[l_i - 1] = p;
    return l_i - 1;
}`;

