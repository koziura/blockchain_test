#!/bin/bash -i

rm -rf tmp
rm -rf debug
rm -rf release
rm -rf obj
rm -rf .vs
rm -rf ver

rm -f Makefile
rm -f *.sdf
rm -f Makefile.*
rm -f .qmake.stash

rm -f ./bin/*
rm -f ./build/*

find . -name "Makefile"-type f
find . -name "tmp" -print0 | xargs -0 rm -rf
find . -name "obj" -print0 | xargs -0 rm -rf
find . -name "Makefile" -print0 | xargs -0 rm -rf

find ./bin -name "logs" -print0 | xargs -0 rm -rf
find ./bin -name "Logs" -print0 | xargs -0 rm -rf
find ./bin -name "data" -print0 | xargs -0 rm -rf
find ./bin -name "Data" -print0 | xargs -0 rm -rf
find ./build/ -name "*" -print0 | xargs -0 rm -rf
