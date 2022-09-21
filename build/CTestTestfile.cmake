# CMake generated Testfile for 
# Source directory: /Users/mikhailpankin/Work/C++/alice_in_wonderland
# Build directory: /Users/mikhailpankin/Work/C++/alice_in_wonderland/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[Rational_number_constructor_test]=] "/Users/mikhailpankin/Work/C++/alice_in_wonderland/bin/Rational_number_constructor_test")
set_tests_properties([=[Rational_number_constructor_test]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/mikhailpankin/Work/C++/alice_in_wonderland/CMakeLists.txt;25;add_test;/Users/mikhailpankin/Work/C++/alice_in_wonderland/CMakeLists.txt;0;")
add_test([=[Rational_number_operators_test]=] "/Users/mikhailpankin/Work/C++/alice_in_wonderland/bin/Rational_number_operators_test")
set_tests_properties([=[Rational_number_operators_test]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/mikhailpankin/Work/C++/alice_in_wonderland/CMakeLists.txt;29;add_test;/Users/mikhailpankin/Work/C++/alice_in_wonderland/CMakeLists.txt;0;")
add_test([=[StringInt_constructor_test]=] "/Users/mikhailpankin/Work/C++/alice_in_wonderland/bin/StringInt_constructor_test")
set_tests_properties([=[StringInt_constructor_test]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/mikhailpankin/Work/C++/alice_in_wonderland/CMakeLists.txt;34;add_test;/Users/mikhailpankin/Work/C++/alice_in_wonderland/CMakeLists.txt;0;")
add_test([=[StringInt_operators_test]=] "/Users/mikhailpankin/Work/C++/alice_in_wonderland/bin/StringInt_operators_test")
set_tests_properties([=[StringInt_operators_test]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/mikhailpankin/Work/C++/alice_in_wonderland/CMakeLists.txt;38;add_test;/Users/mikhailpankin/Work/C++/alice_in_wonderland/CMakeLists.txt;0;")
add_test([=[StringInt_cast_test]=] "/Users/mikhailpankin/Work/C++/alice_in_wonderland/bin/StringInt_cast_test")
set_tests_properties([=[StringInt_cast_test]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/mikhailpankin/Work/C++/alice_in_wonderland/CMakeLists.txt;42;add_test;/Users/mikhailpankin/Work/C++/alice_in_wonderland/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
