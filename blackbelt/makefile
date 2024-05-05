test: main.o checking.o saving.o user.o admin.o information.txt
	g++ main.o checking.o saving.o user.o admin.o -o test

main.o: main.cpp checking.h
	g++ -c main.cpp

checking.o: checking.cpp
	g++ -c checking.cpp

saving.o: saving.cpp
	g++ -c saving.cpp

user.o: user.cpp
	g++ -c user.cpp

admin.o: admin.cpp
	g++ -c admin.cpp

clean:
	rm *.o
	rm test

run: test
	./test

