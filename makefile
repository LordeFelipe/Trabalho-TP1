########## MAKEFILE ##########

all: main

main: main.cpp dominios_usuario.cpp dominios_hotel.cpp entidades.cpp testes_dominios_usuario.cpp testes_dominios_hotel.cpp testes_entidades.cpp
	g++ -o main main.cpp dominios_usuario.cpp dominios_hotel.cpp entidades.cpp testes_dominios_usuario.cpp testes_dominios_hotel.cpp testes_entidades.cpp
