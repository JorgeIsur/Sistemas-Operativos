# %W%
COMPILADOR=gcc
FUENTE = ejemplodeadlock.c vbloqa.c $(RUTA_UTIL)error.c
OBJS=$(FUENTE:.c=.o)
HEADER=ejemplodeadlock.h 
PROG= $(RUTA_BIN)ejemplodeadlock

CC: $(OBJS) 
	$(COMPILADOR) $(OBJS) -lm -o $(PROG)
	@- echo "Compilación terminada"

LIMPIA:
	@- rm -f $(OBJS)
	@- echo "Borrado de objetos terminado"

BORRA:
	@- rm -f $(OBJS) $(PROG)
	@- echo "Borrado de archivos terminado"

.c.o: 
	$(COMPILADOR) -c -I$(RUTA_INCL) $*.c -o $*.o

$(OBJS): $(RUTA_INCL)$(HEADER) 

