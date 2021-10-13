# %W%
COMPILADOR=gcc 
FUENTE = servidorudp.c $(RUTA_UTIL)error.c
OBJS=$(FUENTE:.c=.o)
HEADER=sockets.h 
PROG= $(RUTA_BIN)servidorudp

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

