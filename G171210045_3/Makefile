derlecalistir:program calistir
program: main Agaclar Agac Yonetim
	g++ ./lib/main.o ./lib/Agaclar.o ./lib/Agac.o ./lib/Yonetim.o -o ./bin/program
main:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
Agaclar:
	g++ -c -I "./include" ./src/Agaclar.cpp -o ./lib/Agaclar.o
Agac:
	g++ -c -I "./include" ./src/Agac.cpp -o ./lib/Agac.o
Yonetim:
	g++ -c -I "./include" ./src/Yonetim.cpp -o ./lib/Yonetim.o
calistir:
	./bin/program.exe