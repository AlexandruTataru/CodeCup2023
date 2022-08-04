#!/bin/bash

mkdir build
cd build
cmake ../..
make
make test
cd ..
rm -rf ./entropy/refereelogs/*
rm -rf ./entropy/playerlogs/*
cd entropy/bin
cp ../../build/src/bot .
./caiaio
./competition.sh bot player1 player2 player3 > competition.out
tail -4 competition.out
cd ../..
rm -rf ./build