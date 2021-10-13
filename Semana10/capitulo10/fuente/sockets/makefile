#Make para compilar copiamemcom
COMPILADOR=gcc 

SRC0 = servidortcp.c

OBJ0 = $(SRC0:.c=.o)

PROG0 = servidortcp

SRC1 = clientetcp.c

OBJ1 = $(SRC1:.c=.o)

PROG1 = clientetcp

SRC2 = servidorudp.c

OBJ2 = $(SRC2:.c=.o)

PROG2 = servidorudp

SRC3 = clienteudp.c

OBJ3 = $(SRC3:.c=.o)

PROG3 = clienteudp

HDR = socket.h

$(PROG0): $(OBJ0)
	$(COMPILADOR) $(OBJ0) -lm -o $@
	@- echo "Compilación Terminada"

$(PROG1): $(OBJ1)
	$(COMPILADOR) $(OBJ1) -lm -o $@
	@- echo "Compilación Terminada"

$(PROG2): $(OBJ2)
	$(COMPILADOR) $(OBJ2) -lm -o $@
	@- echo "Compilación Terminada"

$(PROG3): $(OBJ3)
	$(COMPILADOR) $(OBJ3) -lm -o $@
	@- echo "Compilación Terminada"

clean:
	@-rm -f $(PROG0) $(OBJ0)
	@-rm -f $(PROG1) $(OBJ1)
	@-rm -f $(PROG2) $(OBJ2)
	@-rm -f $(PROG3) $(OBJ3)
	@-echo "Binarios limpiados"

.c.o: 
	$(COMPILADOR) -c $*.c 

$(OBJ0): $(HDR)
$(OBJ1): $(HDR)
$(OBJ2): $(HDR)
$(OBJ3): $(HDR)
