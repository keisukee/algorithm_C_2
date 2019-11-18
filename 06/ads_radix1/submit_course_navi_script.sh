#!/bin/bash
gcc -o STtestD STtestD.c ItemD.c ST_DST.c
./STtestD 20 1
./STtestD 20 2
gcc -o STtestD STtestD.c ItemD.c ST_Trie.c
./STtestD 20 1
./STtestD 20 2
