import Image from 'next/image';
import Link from "next/link";
import { GithubIcon } from '../../components/Icons';

export default function PageContainer({ children }: { children: React.ReactNode }) {
    return <div className="min-h-screen flex flex-col">
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
        
        <div className="flex-1">
            {children}
        </div>

        <footer className="
            flex justify-center py-8
            border-t border-t-gray-300
            bg-gray-50
            dark:bg-gray-900 dark:border-t-gray-700
        ">
            <div className="j_max-w w-full flex items-center justify-center">
                <a
                    href="http://github.com/JoelGrayson/JoelKit"
                    target="_blank"
                    rel="noopener noreferrer"
                    className="flex items-center gap-2 hover:bg-gray-500/25 px-4 py-2 rounded-xl transition-colors"
                    aria-label="View on GitHub"
                >
                    <GithubIcon width={24} />
                    <span className="font-medium">View on GitHub</span>
                </a>
            </div>
        </footer>
    </div>;
}

