# %W%
COMPILADOR=gcc
FUENTE = ejemplocreat.c
OBJS=$(FUENTE:.c=.o)
HEADER=ejemplocreat.h
PROG= $(RUTA_BIN)ejemplocreat
CC: $(OBJS) 
	$(COMPILADOR) $(OBJS) -lm -o $(PROG)
	@- echo "Compilación terminada”
LIMPIA:
	@- rm -f $(OBJS)
	@- echo "Borrado de objetos terminado”
BORRA:
	@- rm -f $(OBJS) $(PROG)
	@- echo "Borrado de archivos terminado”
.c.o: 
	$(COMPILADOR) -c -I$(RUTA_INCL) $*.c -o $*.o
$(OBJS): $(RUTA_INCL)$(HEADER)