########## MAKEFILE ##########

all: main

main: main.cpp Dominios_Usuario.cpp Dominios_Hotel.cpp Entidades.cpp Testes_Dominios_Usuario.cpp Testes_Dominios_Hotel.cpp Testes_Entidades.cpp
	g++ -o main main.cpp Dominios_Usuario.cpp Dominios_Hotel.cpp Entidades.cpp Testes_Dominios_Usuario.cpp Testes_Dominios_Hotel.cpp Testes_Entidades.cpp
