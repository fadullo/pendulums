\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{report}[]

\LoadClass[12pt]{article}

\RequirePackage{graphicx}
\RequirePackage[figurename=Figure]{caption}
\RequirePackage{float}
\RequirePackage{verbatim}
\RequirePackage{amsmath}
\RequirePackage{amssymb}
\RequirePackage{fullpage}
\RequirePackage{setspace}
\RequirePackage{paralist}
\RequirePackage{listings}
\RequirePackage{subfig}
\RequirePackage{enumitem}
\RequirePackage{siunitx}
\RequirePackage{booktabs}
\RequirePackage{pgfplotstable}
\RequirePackage{filecontents}
\RequirePackage{pgfplots}
\RequirePackage{tikz,bm}
\RequirePackage{circuitikz}
\RequirePackage{xcolor} % Required before defining colors
\RequirePackage{hyperref}
\RequirePackage{scalerel}
\RequirePackage{pict2e}
\RequirePackage{tkz-euclide}

\usetikzlibrary{patterns, arrows.meta}
\usetikzlibrary{shadows}
\usetikzlibrary{external}


\nonstopmode
\pgfplotsset{compat=1.9}
\onehalfspacing

\lstset{
    basicstyle=\ttfamily\small\singlespacing,
    columns=flexible,
    breaklines=true,
    breakatwhitespace=false,
    keepspaces=true,
    showstringspaces=false,
    aboveskip=0.5em,
    belowskip=0.5em,
    xleftmargin=4em,
    xrightmargin=4em,
    numbers=left,
}

\lstdefinestyle{terminal}{
    basicstyle=\ttfamily\small\singlespacing,
    columns=flexible,
    breaklines=true,
    breakatwhitespace=false,
    keepspaces=true,
    showstringspaces=false,
    aboveskip=0.5em,
    belowskip=0.5em,
    xleftmargin=4em,
    xrightmargin=4em,
    numbers=none,
}

\definecolor{mycolor}{rgb}{1,0.2,0.3}
\definecolor{brightgreen}{rgb}{0.4, 1.0, 0.0}
\definecolor{britishracinggreen}{rgb}{0.0, 0.26, 0.15}
\definecolor{cadmiumgreen}{rgb}{0.0, 0.42, 0.24}
\definecolor{ceruleanblue}{rgb}{0.16, 0.32, 0.75}
\definecolor{darkelectricblue}{rgb}{0.33, 0.41, 0.47}
\definecolor{darkpowderblue}{rgb}{0.0, 0.2, 0.6}
\definecolor{darktangerine}{rgb}{1.0, 0.66, 0.07}
\definecolor{emerald}{rgb}{0.31, 0.78, 0.47}
\definecolor{palatinatepurple}{rgb}{0.41, 0.16, 0.38}
\definecolor{pastelviolet}{rgb}{0.8, 0.6, 0.79}

\newcommand{\@studentnumber}{}
\newcommand{\studentnumber}[1]{\renewcommand{\@studentnumber}{#1}}

\newcommand{\@duedate}{}
\newcommand{\duedate}[1]{\renewcommand{\@duedate}{#1}}

\newcommand{\@course}{}
\newcommand{\course}[1]{\renewcommand{\@course}{#1}}

\newcommand{\@semester}{}
\newcommand{\semester}[1]{\renewcommand{\@semester}{#1}}

\renewcommand{\maketitle}{
    \begin{center}
        {\large\bfseries \@title\par}
        \vspace{0.6em}
        {\small\scshape Dalhousie University, \@semester}
        \vspace{0.6em} \\
        {\small\scshape \@author}
    \end{center}
    \vspace{0.5em}
    \vspace{1cm}
}

