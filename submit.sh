#!/bin/zsh

home=/Users/ryushi/CLionProjects/factory/

cd ${home}A || exit
oj t
if [ $? = 0 ]; then
  oj s -w 0 main.cpp --no-open
else
  echo "skip"
fi

cd ${home}B || exit
oj t
if [ $? = 0 ]; then
  oj s -w 0 main.cpp --no-open
else
  echo "skip"
fi
cd ${home}C || exit
oj t
if [ $? = 0 ]; then
  oj s -w 0 main.cpp --no-open
else
  echo "skip"
fi

cd ${home}D || exit
oj t
if [ $? = 0 ]; then
  oj s -w 0 main.cpp --no-open
else
  echo "skip"
fi

cd ${home}E || exit
oj t
if [ $? = 0 ]; then
  oj s -w 0 main.cpp --no-open
else
  echo "skip"
fi

cd ${home}F || exit
oj t
if [ $? = 0 ]; then
  oj s -w 0 main.cpp --no-open
else
  echo "skip"
fi

cd ${home} || exit
