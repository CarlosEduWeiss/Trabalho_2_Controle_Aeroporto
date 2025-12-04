CC = gcc
SRC = ./src
OBJS = ./objs
TARGET = trab_2
LIMPAR = rm

all: objetos
	$(CC) $(OBJS)/cadastros.o $(OBJS)/consultas.o $(OBJS)/menus.o$(OBJS)/listagens_aeronaves.o $(OBJS)/listagens_rotas.o $(OBJS)/main.o -o $(TARGET)
	

objetos:
	$(Cc) -c $(SRC)/menus.c -o $(OBJS)/menus.o
	$(CC) -c $(SRC)/cadastros.c -o $(OBJS)/cadastros.o
	$(CC) -c $(SRC)/relatorios.c -o $(OBJS)/relatorios.o
	$(CC) -c $(SRC)/listagens_rotas.c -o $(OBJS)/listagens_rotas.o
	$(CC) -c $(SRC)/listagens_aeronaves.c -o $(OBJS)/listagens_aeronaves.o 
	$(CC) -c main.c -o $(OBJS)/main.o


clear:
	$(LIMPAR) $(OBJS)/*.o
	$(LIMPAR) $(TARGET)