all: displayNumber

displayNumber: main.o ComplexNum.o
	g++ main.o ComplexNum.o -o displayNumber

main.o: main.cc
	g++ -c main.cc

ComplexNum.o: ComplexNum.cc ComplexNum.h
	g++ -c ComplexNum.cc

