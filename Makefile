#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: Sterowanie
	./Sterowanie

Sterowanie: main.o ObiektGraficzny.o Robot.o Scena.o Sciezka.o ZbiorWierzcholkow.o Macierz2x2.o Wektor2D.o lacze_do_gnuplota.o Modul.o Przeszkoda.o
	g++ -Wall -pedantic -std=c++0x -o Sterowanie main.o Wektor2D.o Macierz2x2.o ObiektGraficzny.o Robot.o Scena.o Sciezka.o ZbiorWierzcholkow.o lacze_do_gnuplota.o Modul.o Przeszkoda.o

lacze_do_gnuplota.o: lacze_do_gnuplota.hpp lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o lacze_do_gnuplota.o lacze_do_gnuplota.cpp

main.o: main.cpp ObiektGraficzny.hpp Robot.hpp Scena.hpp Sciezka.hpp ZbiorWierzcholkow.hpp Macierz2x2.hpp Wektor2D.hpp Modul.hpp Przeszkoda.hpp
	g++ -c ${CXXFLAGS} -o main.o main.cpp

ObiektGraficzny.o: ObiektGraficzny.cpp ObiektGraficzny.hpp
	g++ -c ${CXXFLAGS} -o ObiektGraficzny.o ObiektGraficzny.cpp

Macierz2x2.o: Macierz2x2.cpp Macierz2x2.hpp 
	g++ -c ${CXXFLAGS} -o Macierz2x2.o Macierz2x2.cpp

Wektor2D.o: Wektor2D.cpp Wektor2D.hpp
	g++ -c ${CXXFLAGS} -o Wektor2D.o Wektor2D.cpp

Modul.o: Modul.cpp Modul.hpp
	g++ -c ${CXXFLAGS} -o Modul.o Modul.cpp

Robot.o: Robot.cpp Robot.hpp
	g++ -c ${CXXFLAGS} -o Robot.o Robot.cpp

Scena.o: Scena.cpp Scena.hpp
	g++ -c ${CXXFLAGS} -o Scena.o Scena.cpp

Sciezka.o: Sciezka.cpp Sciezka.hpp
	g++ -c ${CXXFLAGS} -o Sciezka.o Sciezka.cpp

ZbiorWierzcholkow.o: ZbiorWierzcholkow.cpp ZbiorWierzcholkow.hpp
	g++ -c ${CXXFLAGS} -o ZbiorWierzcholkow.o ZbiorWierzcholkow.cpp

Przeszkoda.o: Przeszkoda.cpp Przeszkoda.hpp
	g++ -c ${CXXFLAGS} -o Przeszkoda.o Przeszkoda.cpp

clean:
	rm -f *.o *.dat Sterowanie

