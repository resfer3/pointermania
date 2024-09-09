#!/bin/bash

gcc -c -o exercises.o exercises.c

gcc -c -o basic.o lib/basic.c

gcc -o code exercises.o basic.o
