#!/usr/bin/bash

tests_project_name=Doengine_tests
project_name=DOENGINE

cmake -DDOENGINE_COVERAGE=TRUE -DCMAKE_BUILD_TYPE=Debug -S . -B build
cmake --build build/ --config Debug --target $tests_project_name
pushd build/test
ctest -j3
popd
cmake --build build/ --config Debug --target "${tests_project_name}_cov"