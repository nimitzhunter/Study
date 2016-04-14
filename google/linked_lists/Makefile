CC = gcc
CXX = clang
SRC = main.cpp


.PHONY: check-syntax

check-syntax:
	$(CXX) -std=c++11 -Wall -Wextra -pedantic -fsyntax-only $(SRC)
