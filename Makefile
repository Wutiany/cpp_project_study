# 默认生成模式
MODE ?= release

# 根据模式选择编译选项
ifeq ($(MODE), debug)
    BUILD_TYPE = Debug
else
    BUILD_TYPE = Release
endif

all:
	cd build && \
	cmake  .. -D CMAKE_BUILD_TYPE=$(BUILD_TYPE) && \
	make

clean:
	cd build && make clean

.PHONY: all clean


