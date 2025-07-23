# 默认生成模式
MODE ?= debug

BUILD_DIR := build

${BUILD_DIR}:
	@mkdir -p $@

# 根据模式选择编译选项
ifeq ($(MODE), debug)
    BUILD_TYPE = Debug
else
    BUILD_TYPE = Release
endif

all:
	cd $(BUILD_DIR) && \
	echo "Building in $$(pwd)" && \
	cmake  .. -D CMAKE_BUILD_TYPE=$(BUILD_TYPE) && \
	make

clean:
	cd $(BUILD_DIR) && make clean

.PHONY: all clean


