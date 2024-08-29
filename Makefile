main: main.o StdSort.o QuickSelect1.o QuickSelect2.o InsertionSort.o CountingSort.o
	g++ -o main main.o StdSort.o QuickSelect1.o QuickSelect2.o InsertionSort.o CountingSort.o

main.o: main.cpp StdSort.cpp QuickSelect1.cpp QuickSelect2.cpp InsertionSort.cpp CountingSort.cpp

StdSort.o: StdSort.cpp StdSort.hpp

InsertionSort.o: InsertionSort.cpp InsertionSort.hpp

QuickSelect1.o: QuickSelect1.cpp QuickSelect1.hpp InsertionSort.hpp

QuickSelect2.o: QuickSelect2.cpp QuickSelect2.hpp InsertionSort.hpp

CountingSort.o: CountingSort.cpp CountingSort.hpp

clean:
	rm -f *.o
