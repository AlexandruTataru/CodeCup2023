#!/bin/bash

cat ../include/lib.hpp ../src/bot.cpp > processed.cpp
mv processed.cpp raw.cpp 
sed 's/#include <lib.hpp>/\n/g' raw.cpp > processed.cpp
mv processed.cpp raw.cpp
sed 's/#pragma once//g' raw.cpp > processed.cpp

rm raw.cpp
mv processed.cpp bot.cpp