#!/bin/sh

read -p "Enter 1 for Release and 2 for Debug build: " build_mode
if [ "$build_mode" -eq "1" ]
then
    cd Release
    cmake --build /home/skull/data/builds/ThreeBodySim/Release --config Release --target ThreeBodySim -j 6 --
fi
if [ "$build_mode" -eq "2" ]
then
    cd Debug
    cmake --build /home/skull/data/builds/ThreeBodySim/Debug --config Debug --target ThreeBodySim -j 6 --
fi
