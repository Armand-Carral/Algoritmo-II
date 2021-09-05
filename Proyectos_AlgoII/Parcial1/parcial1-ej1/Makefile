#Makefile sirve para cuando tenemos muchos proyectos para compilar y el cual vamos a tener muchas lineas de compilacion, en el que no todas vamos a recordar, y con tener creado esto no vamos a estar buscando cada linea de compilacion en la terminal.

#Creamos una variable para los flags:
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99
#Lo mismo para el compilador, creamos un variable
CC = gcc
#Creamos una variable para los archivos
SRC = array_helpers.c sort.c

#Cambia los .c de SRC por .o y los guardas en OBJS sin modificar los contenidos de SRC
OBJS = $(SRC:.c=.o)
 
#Si no ponemos all, se ejecuta solo la primera regla.
all: sorter run clean
# all: sorter, solo ejecuta las lineas de sorter.

clean:
	rm -f sorter $(OBJS)

#defincion para linkear
#compila de codigo a objeto
objetos:
	$(CC) $(CFLAGS) -c $(SRC)
#Aqui sorter lo linkea los objetos; Ademas $@ para referirnos a sorter
sorter:	$(OBJS)
	$(CC) $(CFLAGS) -o $@ sort_helpers.o $^ main.c
#Pusimos el $@ para no estar nombrando sorter cada vez que invocamos make ya que directamente make se dirije con a sorter con esa regla.

#Esta linea no es bash
option:
	@echo $(SRC) #Pero esta linea si la ejecuta como bash
	@echo $(OBJS)
	@echo "compilador "$(CC)
#Bash es lo que se ejecuta en compilar, es decir, en la terminal

#Para testear
run: sorter
	./sorter ../input/unsorted-100.in > salida.out
	diff ../input/unsorted-100.in salida.out
#Tambien se puede poner los diff o comparaciones

#Aqui la regla clean no va a generar un archivo, entonces  va a ignorar el hecho de mirar un archivo con esa regla. 
.PHONY: clean
#Esta linea borra los '.o', sin importar de que haya un clean no creado por el.
