
set(SOURCES_TEST_TESTNODE
    main.cpp
    )



set(LIBS_TEST_TESTNODE
    testnode
    dl
    )



add_executable(test_testnode ${SOURCES_TEST_TESTNODE} ${HEADERS})
target_link_libraries(test_testnode
    ${LIBS_TEST_TESTNODE})

# 全局变量：库文件的输出路径
# 全局变量：CMAKE_SOURCE_DIR CMake的起始目录，即源码的根目录
# 全局变量：PROJECT_NAME 工程的名称
# 全局变量：PROJECT_SOURCE_DIR 工程的源码根目录的完整路径

