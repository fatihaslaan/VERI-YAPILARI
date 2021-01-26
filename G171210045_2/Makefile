derlecalistir:program calistir
program: main Dairesellist Stack Yonetim
	g++ ./lib/main.o ./lib/Dairesellist.o ./lib/Stack.o ./lib/Yonetim.o -o ./bin/program
main:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
Dairesellist:
	g++ -c -I "./include" ./src/Dairesellist.cpp -o ./lib/Dairesellist.o
Stack:
	g++ -c -I "./include" ./src/Stack.cpp -o ./lib/Stack.o
Yonetim:
	g++ -c -I "./include" ./src/Yonetim.cpp -o ./lib/Yonetim.o
calistir:
	./bin/program.exe

