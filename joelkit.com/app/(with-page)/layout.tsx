import Image from 'next/image';
import Link from "next/link";

export default function PageContainer({ children }: { children: React.ReactElement }) {
    return <>
        <header className="
            flex justify-center h-16
            border-b border-b-gray-300
            bg-linear-to-b from-gray-50 to-gray-100
            dark:from-gray-900 dark:to-gray-800
        ">
            <div className="j_max-w w-full flex items-center justify-between">
                <Link className="flex items-center gap-1.5 hover:bg-gray-500/25 px-3 py-2 rounded-xl unstyled" href='/'>
                    <Image src='/logo.png' width={40} height={40} alt="Logo" className='relative bottom-0.5' />
                    <span className="font-bold text-xl">JoelKit</span>
                </Link>
            </div>
        </header>
        {children}
    </>;
}

