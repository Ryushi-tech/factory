#!/bin/zsh

home=/Users/ryushi/CLionProjects/factory/

cd ${home}A || exit
if oj t; then oj s -w 0 main.cpp --no-open; else echo "#test A failed and submission skipped"; fi

cd ${home}B || exit
if oj t; then oj s -w 0 main.cpp --no-open; else echo "#test B failed and submission skipped"; fi

cd ${home}C || exit
if oj t; then oj s -w 0 main.cpp --no-open; else echo "#test C failed and submission skipped"; fi

cd ${home}D || exit
if oj t; then oj s -w 0 main.cpp --no-open; else echo "#test D failed and submission skipped"; fi

cd ${home}E || exit
if oj t; then oj s -w 0 main.cpp --no-open; else echo "#test E failed and submission skipped"; fi

cd ${home}F || exit
if oj t; then oj s -w 0 main.cpp --no-open; else echo "#test F failed and submission skipped"; fi

cd ${home} || exit
