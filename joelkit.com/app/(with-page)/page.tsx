import Yt from "@/components/Yt";
import videos from "../videos";
import Toggle from "./Toggle";
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter';
import { oneDark } from 'react-syntax-highlighter/dist/esm/styles/prism';


const insertionSortPython = `def insertion_sort(arr): #in place
    for i in range(1, len(arr)): #first item already sorted
        to_move = arr[i]
        curr_i = i
        while curr_i > 0 and arr[curr_i - 1] > to_move:
            arr[curr_i] = arr[curr_i - 1] #nudge item to the right
            curr_i -= 1
        arr[curr_i] = to_move`;

const insertionSortCpp = `template <typename T>
void insertion_sort(std::vector<T>& v) {
    for (int i = 1; i < v.size(); i++) {
        T el = v[i]; //element to insert
        int curr_i = i;
        while (curr_i > 0 && v[curr_i - 1] > el) {
            v[curr_i] = v[curr_i - 1];
            curr_i--;
        }
        v[curr_i] = el;
    }
}`;

export default function Home() {
    return <div className="max-w-[800px] mx-auto mt-8">
        <h2>Algorithms</h2>
        <h3>Sorting</h3>
        <ul className="styled">
            <Toggle title="Insertion Sort">
                <Yt>{videos.insertionSort}</Yt>
                <div className="sm:grid sm:grid-cols-2 gap-4">
                    <div>
                        <h4>Python</h4>
                        <SyntaxHighlighter language="python" style={oneDark}>
                            {insertionSortPython}
                        </SyntaxHighlighter>
                    </div>
                    <div>
                        <h4>C++</h4>
                        <SyntaxHighlighter language="cpp" style={oneDark}>
                            {insertionSortCpp}
                        </SyntaxHighlighter>
                    </div>
                </div>
            </Toggle>
            <li>
                Quick Sort
            </li>
        </ul>
        
    </div>;
}

