CC = gcc
SRC = ./src
OBJS = ./objs
TARGET = trab_2
LIMPAR = rm

all: objetos
	$(CC) $(OBJS)/cadastros.o $(OBJS)/consultas.o $(OBJS)/arquivo.o $(OBJS)/menus.o $(OBJS)/listagens_aeronaves.o $(OBJS)/listagens_rotas.o $(OBJS)/relatorios.o $(OBJS)/utils.o $(OBJS)/main.o -o $(TARGET)
	

objetos:
	$(CC) -c $(SRC)/menus.c -o $(OBJS)/menus.o
	$(CC) -c $(SRC)/cadastros.c -o $(OBJS)/cadastros.o
	$(CC) -c $(SRC)/consultas.c -o $(OBJS)/consultas.o
	$(CC) -c $(SRC)/relatorios.c -o $(OBJS)/relatorios.o
	$(CC) -c $(SRC)/listagens_rotas.c -o $(OBJS)/listagens_rotas.o
	$(CC) -c $(SRC)/listagens_aeronaves.c -o $(OBJS)/listagens_aeronaves.o
	$(CC) -c $(SRC)/utils.c -o $(OBJS)/utils.o
	$(CC) -c main.c -o $(OBJS)/main.o
	$(CC) -c $(SRC)/arquivo.c -o $(OBJS)/arquivo.o


clear:
	$(LIMPAR) $(OBJS)/*.o
	$(LIMPAR) $(TARGET)