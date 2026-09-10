cmake_minimum_required(VERSION 3.16)
project(ctdl_gt C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(ctdl_gt
    src/algorithm/search.c
    src/algorithm/sort.c
    src/algorithm/graph.c
    src/algorithm/tree_balance.c
    src/data_structure/array.c
    src/data_structure/heap.c
    src/data_structure/list.c
    src/data_structure/queue.c
    src/data_structure/stack.c
    src/data_structure/tree.c
)

target_include_directories(ctdl_gt PUBLIC include)
target_compile_options(ctdl_gt PRIVATE -Wall -Wextra -Wpedantic)

enable_testing()
add_executable(ctdl_gt_tests tests/test_main.c)
target_link_libraries(ctdl_gt_tests PRIVATE ctdl_gt)
target_compile_options(ctdl_gt_tests PRIVATE -Wall -Wextra -Wpedantic)
add_test(NAME ctdl_gt_tests COMMAND ctdl_gt_tests)
