#!/bin/zsh

home=/Users/ryushi/CLionProjects/factory/
acl=/Users/ryushi/opt/ac-library/

cd ${acl} || exit
python expander.py ${home}/main.cpp
mv combined.cpp ${home}/
cd ${home} || exit
