#!/bin/bash
set -e
time ./test_nocap $1 $2
echo
time ./test_cap $1 $2
echo
time ./test_cpp $1 $2
