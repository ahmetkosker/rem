#!/bin/bash

gcc test/rem_test.c src/rem.c src/options.c src/int_list.c -DREM_TEST_FILE="\"$1\"" -DREM_TEST_REGEX="\"$2\"" &&
./a.out
