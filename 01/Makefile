#============================
# QuickFind class Makefile
#
# Author: Brendon Roberto
#
# ===========================


CXX					= g++
INCLUDE_OPT = -iquote .
DOP 				= -a

CXX_FLAGS   = -g -O -Wall -W -Wunused -Wuninitialized -Wshadow

ECHO				= /bin/echo

UNION_H			= union.h
UNION_O			= union.o

#DEF = -DSTD_STRING

#=============================
# Tests
#=============================

TEST_PROG_1 	= test_quickfind_constructors
TEST_PROG_2   = test_quickfind_find
TEST_PROG_3		= test_quickfind_unite

TEST_PROG_DIR = ./tests/

#=============================

msg:
	@echo 'Targets for compiling test programs:'
	@echo '			t1 or ${TEST_PROG_1}'
	@echo '			t2 or ${TEST_PROG_2}'
	@echo '			t3 or ${TEST_PROG_3}'

union.o:	union.h	union.cpp
	${CXX} ${CXX_FLAGS} ${INCLUDE_OPT} -c union.cpp ${COMPILER_OUT_2}

err: COMPILER_OUTFILE = compiler_output.txt
err: COMPILER_OUT_1 = >& ${COMPILER_OUTFILE}
err: COMPILER_OUT_2 = >> ${COMPILER_OUTFILE} 2>&1

test_%: ${UNION_O} test_%.o
	${CXX} ${UNION_O} test_$*.o -o test_$* ${COMPILER_OUT_2}

test_%.o: ${UNION_H} ${TEST_PROG_DIR}test_%.cpp
	${CXX} ${CXX_FLAGS} ${DEF} ${INCLUDE_OPT} -c ${TEST_PROG_DIR}test_$*.cpp ${COMPILER_OUT_2}

p1:  ${TEST_PROG_1}
p2:  ${TEST_PROG_2} p1
p3:	 ${TEST_PROG_3} p2

t1: p1 ${TEST_PROG_1}
	${Q}./${TEST_PROG_1}
t2: p2 t1
	${Q}./${TEST_PROG_2}
t3: p3 t2
	${Q}./${TEST_PROG_3}

tests: t3

clean:
	@rm *.o
