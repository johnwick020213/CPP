# 定义编译器
CC = g++

# 定义编译选项
CFLAGS = -Wall -g -pthread

# 获取当前文件夹中的所有 .cpp 文件
SOURCES = $(wildcard *.cpp)

# 获取当前文件夹中的所有 .h 文件
HEADERS = $(wildcard *.h)

# 生成的目标文件
OBJS = $(SOURCES:.cpp=.o)

# 包含 main 函数的文件 (请根据实际情况修改)
MAIN_FILE = PCtest

# 联合编译生成的可执行文件
EXEC = $(MAIN_FILE)

# 定义默认目标
.PHONY: all
all: $(EXEC)

# 规则：联合编译生成一个可执行文件
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 规则：生成每个 .o 文件
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# 规则：单文件编译，每个源文件生成一个可执行文件
.PHONY: single
single: $(SOURCES)
	for src in $(SOURCES); do \
		exec=$$(basename $$src .cpp); \
		$(CC) $(CFLAGS) -o $$exec $$src; \
	done

# 规则：清理生成的文件
.PHONY: clean
clean:
	rm -f $(OBJS) $(EXEC) $(patsubst %.cpp,%,$(SOURCES))

