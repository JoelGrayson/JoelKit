'use client';

import Yt from "@/components/Yt";
import videos from "../../videos";
import Toggle from "../Toggle";
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter';
import { oneDark } from 'react-syntax-highlighter/dist/esm/styles/prism';

export default function BubbleSort() {
    return <>
        <Toggle title="Bubble Sort">
            <Yt>{videos.bubbleSort}</Yt>

            <div>
                <h4>Python</h4>
                <SyntaxHighlighter language="python" style={oneDark}>
                    {bubbleSortPy}
                </SyntaxHighlighter>
            </div>
            <div>
                <h4>C++</h4>
                <SyntaxHighlighter language="cpp" style={oneDark}>
                    {bubbleSortCpp}
                </SyntaxHighlighter>
            </div>
            
            <h3>Runtime</h3>
            <p>O(n<sup>2</sup>)</p>
        </Toggle>
    </>;
}

const bubbleSortPy = `# from joelkit.algorithms import bubble_sort

d# Elements bubble their way to the right
# Topmost element bubbles to the last element
# Second-largest element bubbles to the second to last element
# ...
def bubble_sort(arr):
    for i in range(len(arr) - 1): #need -1 because j+1
        for j in range(0, len(arr) - 1 - i): #don't need to consider last i items because they are sorted (i largest items bubbled up)
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]`;

const bubbleSortCpp = `template <typename T>
void bubble_sort(std::vector<T>& l) {
    for (int i = 0; i < l.size() - 1; i++) {
        for (int j = 0; j < l.size() - 1 - i; j++) {
            if (l[j] > l[j + 1]) {
                T temp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = temp;
            }
        }
    }
}`;

