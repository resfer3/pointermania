#!/bin/bash

gcc -c -o practice3.o practice3.c

gcc -c -o basic.o lib/basic.c

gcc -o code practice3.o basic.o
