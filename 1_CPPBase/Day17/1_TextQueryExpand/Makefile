# 指定编译器
CXX = g++
# 编译选项
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# 生成的可执行文件
EXECUTABLES = and_orQueryTest andQueryTest

# 源文件
SOURCES = and_orQueryTest.cpp andQueryTest.cpp get_print.cpp Query.cpp TextQuery.cpp

# 头文件
HEADERS = make_plural.h Query.h QueryResult.h TextQuery.h

# 生成的目标文件
OBJECTS = $(SOURCES:.cpp=.o)

# 默认目标
all: $(EXECUTABLES)

# 生成可执行文件 and_orQueryTest
and_orQueryTest: and_orQueryTest.o get_print.o Query.o TextQuery.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# 生成可执行文件 andQueryTest
andQueryTest: andQueryTest.o get_print.o Query.o TextQuery.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# 通用规则，生成 .o 文件
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJECTS) $(EXECUTABLES)

# 伪目标，不会实际生成名为这些名字的文件
.PHONY: all clean

