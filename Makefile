# The targets in this file are used in .gitlab-ci.yml and 
# the files created are found in the .gitignore
# Changing any names below can change the target names which 
# will require that you update .gitlab_ci.yml and .gitignore
PROJECT = slidingTiles


# Compilation command and flags
CXX=g++
CXXVERSION= -std=c++11
CXXFLAGS= ${CXXVERSION} -g -fprofile-arcs -ftest-coverage
LINKFLAGS= -lgtest

# Directories
SRC_DIR = src
PROJECT_SRC_DIR = src/project
SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

# Tool variables
GCOV = gcov
LCOV = lcov

# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := compileProject

# default rule for compiling .cc to .o
%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

# clean up all files that should NOT be submitted
.PHONY: clean
clean:
	rm -rf *~ ${SRC}/*.o ${GTEST_DIR}/output/*.dat \
	*.gcov *.gcda *.gcno \
	${PROJECT} ${COVERAGE_RESULTS} \
	${GTEST} ${MEMCHECK_RESULTS} ${COVERAGE_DIR}  \
	${PROJECT}.exe ${GTEST}.exe

# compilation using the files in include, src, and test, but not src/project
${GTEST}: ${GTEST_DIR} ${SRC_DIR}
	${CXX} ${CXXFLAGS} -o ./${GTEST} ${INCLUDE} \
	${GTEST_DIR}/*.cpp ${SRC_DIR}/*.cpp ${LINKFLAGS}

# compilation using the files in include, src, and src/project, but not test
compileProject: ${SRC_DIR} ${PROJECT_SRC_DIR}
	${CXX} ${CXXVERSION} -o ${PROJECT} ${INCLUDE} \
	${SRC_DIR}/*.cpp ${PROJECT_SRC_DIR}/*.cpp
