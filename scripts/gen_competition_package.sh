#!/bin/bash

cat ../include/lib.hpp ../src/bot.cpp > bot_raw.cpp
sed 's/#include <lib.hpp>/\n/g' bot_raw.cpp > bot.cpp
rm -rf bot_raw.cpp