cmake_minimum_required(VERSION 2.8.12...3.27)

################
## Search and Includes
#########################
include_directories(".")

################
## Sources
#########################
file(GLOB_RECURSE FUZZ_LEXBOR_CSS_SOURCES "*.c")

################
## Create
#########################
EXECUTABLE_LIST("fuzz_lexbor_css_" "${FUZZ_LEXBOR_CSS_SOURCES}" ${TEST_LEXBOR_LIB_NAME})

add_fuzz_test(cifuzz_css stylesheet.c)
target_link_libraries (cifuzz_css ${PROJECT_NAME})