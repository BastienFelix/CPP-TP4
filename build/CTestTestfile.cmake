# CMake generated Testfile for 
# Source directory: /workspaces/CPP-TP4
# Build directory: /workspaces/CPP-TP4/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyTests "/workspaces/CPP-TP4/build/runTests")
set_tests_properties(MyTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/CPP-TP4/CMakeLists.txt;45;add_test;/workspaces/CPP-TP4/CMakeLists.txt;0;")
subdirs("googletest")
