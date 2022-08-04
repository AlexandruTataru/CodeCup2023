#!/bin/bash

mkdir build
cd build
cmake ../..
make
cd ..
rm -rf ./entropy/refereelogs/*
rm -rf ./entropy/playerlogs/*
cd entropy/bin
cp ../../build/src/bot .
./caiaio
./competition.sh bot player1 player2 player3
cd ../..
rm -rf ./build