
set(SOURCES_TESTNODE
    CAdd.cpp
    CAddClassFactory.cpp
    )



set(LIBS_TESTNODE
    base
    )


add_library(testnode SHARED ${SOURCES_TESTNODE} ${HEADERS})
target_link_libraries(testnode
    ${LIBS_TESTNODE})

# 全局变量：CMAKE_SOURCE_DIR CMake的起始目录，即源码的根目录
# 全局变量：PROJECT_NAME 工程的名称
# 全局变量：PROJECT_SOURCE_DIR 工程的源码根目录的完整路径

