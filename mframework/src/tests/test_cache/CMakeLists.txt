
set(SOURCES_TEST_CACHE
    main.cpp
    )



set(LIBS_TEST_CACHE
    cache
    dl
    )



add_executable(test_cache ${SOURCES_TEST_CACHE} ${HEADERS})
target_link_libraries(test_cache
    ${LIBS_TEST_CACHE})

# 全局变量：库文件的输出路径
# 全局变量：CMAKE_SOURCE_DIR CMake的起始目录，即源码的根目录
# 全局变量：PROJECT_NAME 工程的名称
# 全局变量：PROJECT_SOURCE_DIR 工程的源码根目录的完整路径

