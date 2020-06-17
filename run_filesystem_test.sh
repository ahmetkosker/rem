#!/bin/bash

gcc test/filesystem_test.c -DREM_TEST_DIR="\"$1\"" -DREM_TEST_REGEX="\"$2\"" src/rem.c src/filesystem.c src/options.c &&
./a.out
