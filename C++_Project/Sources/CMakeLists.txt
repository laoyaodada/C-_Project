# 查找当前目录下所有源文件
# 并将结果保存在DIR_LIB_SRCS变量中
aux_source_directory(. DIR_SRCS)

include_directories(
    ../Headers
)
# 生成链接库
add_library(Sources ${DIR_SRCS})
