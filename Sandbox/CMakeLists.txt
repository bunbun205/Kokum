project(KokumSandbox)

add_executable(Sandbox main.cpp)
target_link_libraries(Sandbox PRIVATE Kokum)
target_include_directories(Sandbox PRIVATE ${PROJECT_SOURCE_DIR}/../Kokum/include)
