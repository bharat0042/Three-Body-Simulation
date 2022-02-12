#!/bin/sh

read -p "Enter 1 for Release and 2 for Debug build: " build_mode
if [ "$build_mode" -eq "1" ]
then
    mkdir Release
    cd Release
    cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Release -H/home/skull/data/builds/ThreeBodySim -B/home/skull/data/builds/ThreeBodySim/Release
fi
if [ "$build_mode" -eq "2" ]
then
    mkdir Debug
    cd Debug
    cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -H/home/skull/data/builds/ThreeBodySim -B/home/skull/data/builds/ThreeBodySim/Debug
fi
