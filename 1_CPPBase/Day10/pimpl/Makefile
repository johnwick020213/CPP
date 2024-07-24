Srcs := $(wildcard *.c *.cc *.cpp)
Objs := $(patsubst %.c, %.o, $(patsubst %.cc, %.o, $(patsubst %.cpp, %.o, $(Srcs))))
Deps := $(Objs:.o=.d)

CC := gcc
CXX := g++
CFLAGS = -Wall -g
CXXFLAGS = -Wall -g
DEPFLAGS = -MMD -MP

# 通过grep查找包含main函数的文件，并去掉文件扩展名
MAIN_SRC := $(shell grep -l 'int main' $(Srcs))
Exe := $(basename $(MAIN_SRC))

ALL: $(Exe) clean_objs

# 最终可执行文件的规则
$(Exe): $(Objs)
	$(CXX) $(Objs) -o $@

# 生成 .o 文件规则，并处理 .d 依赖文件
%.o: %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

# 包含 .d 文件，以处理头文件依赖
-include $(Deps)

.PHONY: clean rebuild ALL clean_objs

clean:
	$(RM) $(Exe) $(Objs) $(Deps)

rebuild: clean ALL

clean_objs:
	$(RM) $(Objs) $(Deps)

