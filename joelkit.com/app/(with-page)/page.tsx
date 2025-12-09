import Yt from "@/components/Yt";
import videos from "../videos";

export default function Home() {
    return <div className="max-w-[800px] mx-auto mt-8">
        <h2>Algorithms</h2>
        <h3>Sorting</h3>
        <ul className="styled">
            <li>
                Insertion Sort
            </li>
            <li>
                Quick Sort
            </li>
        </ul>
        <Yt>{videos.bubbleSort}</Yt>
    </div>;
}

