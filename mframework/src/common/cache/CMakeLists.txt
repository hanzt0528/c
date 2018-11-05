
set(SOURCES_CACHE
    CxMemory.cpp
    CCacheClassFactory.cpp
    )

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(LIBS_CACHE
    base
    )


add_library(cache SHARED ${SOURCES_CACHE} ${HEADERS})
target_link_libraries(cache
    ${LIBS_CACHE})

# 全局变量：CMAKE_SOURCE_DIR CMake的起始目录，即源码的根目录
# 全局变量：PROJECT_NAME 工程的名称
# 全局变量：PROJECT_SOURCE_DIR 工程的源码根目录的完整路径

