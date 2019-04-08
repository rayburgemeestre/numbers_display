#!/bin/bash

 g++ -std=c++14 -DDIGIT="\"$1.c\"" get.cpp -o get && ./get
