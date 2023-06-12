file(GLOB src "*.c" "*.cpp")
add_executable(app ${src})
target_link_libraries(app PRIVATE fmt::fmt)