derlecalistir: program calistir
program: main Okul Sinif Yonetim Ogrenci
	g++ ./lib/main.o ./lib/Okul.o ./lib/Sinif.o ./lib/Yonetim.o ./lib/Ogrenci.o -o ./bin/program
main:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
Okul:
	g++ -c -I "./include" ./src/Okul.cpp -o ./lib/Okul.o
Sinif:
	g++ -c -I "./include" ./src/Sinif.cpp -o ./lib/Sinif.o
Yonetim:
	g++ -c -I "./include" ./src/Yonetim.cpp -o ./lib/Yonetim.o
Ogrenci:
	g++ -c -I "./include" ./src/Ogrenci.cpp -o ./lib/Ogrenci.o
calistir:
	./bin/program.exe
