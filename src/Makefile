CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11
TEST_FLAGS:= -g $(FLAGS)
GCOV_FLAGS=--coverage

TARGET=viewer.a

ALL_SRC_HDRS = $(wildcard 3DViewer/ui/viewFieldGL/*.cpp \
													3DViewer/ui/viewFieldGL/*.h \
													3DViewer/viewerlib/*.c \
													3DViewer/viewerlib/*.h \
													3DViewer/*.cpp 3DViewer/*.h \
													tests/*.c tests/*.h)

SRC=$(wildcard ./3DViewer/viewerlib/*.c)
OBJ_PATH=$(patsubst %.c,%.o, ${SRC})
OBJ := $(subst ./3DViewer/viewerlib/,,$(OBJ_PATH))

TEST_SRC=$(wildcard tests/*.c)
TEST_BUILD_DIR=test_build

OS := $(shell uname -s)
USERNAME=$(shell whoami)


OS := $(shell uname)
ifeq ($(OS),Linux)
  LIBS = -lcheck -lsubunit -lm -lpthread 
  OPEN_CMD = xdg-open
else
  LIBS = -lcheck
  OPEN_CMD = open
endif

all: install viewer.a test gcov_report

install:
ifeq ($(OS),Linux)
	sudo apt-get install libgl-dev mesa-common-dev libgl1-mesa-dev libglu1-mesa-dev
endif
ifeq ($(OS),Darwin)
	brew install qt xcodegen libglu
endif
	make clean
	mkdir build
	sudo bash -c "cd build && sudo qmake ../3DViewer && sudo make release-all"

uninstall:
	sudo rm -rf build*

dvi:
	open dvi.html

dist:
	rm -rf Archive_3DViewer_v1.0/
	mkdir Archive_3DViewer_v1.0/
	mkdir Archive_3DViewer_v1.0/src
	cp -R tests objFiles 3DViewer Archive_3DViewer_v1.0/src/
	cp Makefile Archive_3DViewer_v1.0/src/
	tar cvzf Archive_3DViewer_v1.0.tgz Archive_3DViewer_v1.0/
	mv Archive_3DViewer_v1.0.tgz $(HOME)/Desktop/
	rm -rf Archive_3DViewer_v1.0/

viewer.a: ${SRC}
	$(CC) -c ${FLAGS} ${SRC}
	ar rc viewer.a ${OBJ}
	ranlib viewer.a
	make clean_obj

test: viewer.a
	make clean_test
	mkdir $(TEST_BUILD_DIR)
ifeq ($(OS), Darwin)
	$(CC) ${FLAGS} ${TEST_SRC} $< -o $(TEST_BUILD_DIR)/test ${LIBS}
else
	$(CC) ${FLAGS} ${TEST_SRC} $< -o $(TEST_BUILD_DIR)/test ${LIBS}
endif
	./$(TEST_BUILD_DIR)/test
	cd ..

gcov_report: clean_test
	mkdir $(TEST_BUILD_DIR)
ifeq ($(OS), Darwin)
	$(CC) ${FLAGS} ${GCOV_FLAGS} ${TEST_SRC} ${SRC} -o $(TEST_BUILD_DIR)/gcov_report ${LIBS}
else
	$(CC) ${FLAGS} ${GCOV_FLAGS} ${TEST_SRC} ${SRC} -o $(TEST_BUILD_DIR)/gcov_report ${LIBS}
endif
	./$(TEST_BUILD_DIR)/gcov_report
	lcov -t "./$(TEST_BUILD_DIR)/gcov_report" -o $(TEST_BUILD_DIR)/gcov_report.info --no-external -c -d .
	genhtml -o $(TEST_BUILD_DIR)/report $(TEST_BUILD_DIR)/gcov_report.info
	$(OPEN_CMD) $(TEST_BUILD_DIR)/report/index.html

check_linters:
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c $(ALL_SRC_HDRS)
	cppcheck $(ALL_SRC_HDRS)
	sudo rm -rf CPPLINT.cfg

cppcheck:
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem $(ALL_SRC_HDRS)

valgrind: test
	valgrind --leak-check=yes --tool=memcheck -s ./$(TEST_BUILD_DIR)/test 

leaks: test
	leaks --atExit -- ./$(TEST_BUILD_DIR)/test

clang:
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -i -n $(ALL_SRC_HDRS)
	sudo rm .clang-format

style :
	clang-format -i --style=Google $(ALL_SRC_HDRS)
	clang-format -n --style=Google $(ALL_SRC_HDRS)

brew:
	eval /opt/goinfre/$(USERNAME)/homebrew/bin/brew shellenv; \
	brew update --force --quiet; \
	chmod -R go-w "$(brew --prefix)/share/zsh"

install_brew:
	cd /opt/goinfre/$(USERNAME); \
	mkdir homebrew; \
	git clone https://github.com/Homebrew/brew homebrew; \
	make brsw

lcov:
	brew install lcov

clean_obj:
	sudo rm -rf *.o

clean_lib:
	sudo rm -rf *.a

clean_test:
	sudo rm -rf *.gcda *.gcno gcov_report *.info report $(TEST_BUILD_DIR)

clean: clean_lib clean_lib clean_test clean_obj
	sudo rm -rf test build
