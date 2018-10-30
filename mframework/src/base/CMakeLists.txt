#AUX_SOURCE_DIRECTORY(. SOURCES)
set(SOURCES_BASE
CUnknown.cpp
util.cpp
)
add_library(base STATIC ${SOURCES_BASE} ${HEADERS})

# 全局变量：CMAKE_SOURCE_DIR CMake的起始目录，即源码的根目录
# 全局变量：PROJECT_NAME 工程的名称
# 全局变量：PROJECT_SOURCE_DIR 工程的源码根目录的完整路径

