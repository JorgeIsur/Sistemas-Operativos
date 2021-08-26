######################################################################## 
# Archivo de descripci▒n para compilar la librer▒a                     # 
#                                                                      # 
# $Id$                                                                 # 
#                                                                      # 
# $Author$                                                             # 
######################################################################## 
 
######################################################################## 
# Definici▒n de Macros                                                 # 
######################################################################## 
 
LIBRERO=ar -rc 
 
COMPILADOR=cc 
 
FUENTE = mensaje.c 
 
OBJS=$(FUENTE:.c=.o) 
 
HEADER=$(RUTA_INCL)aviso.h

LIB= $(RUTA_LIB)libaviso.a 
 
####################################################################### 
# Target principal para compilar la libreria.                         # 
####################################################################### 
$(LIB): $(OBJS)
        $(LIBRERO) $@ $(OBJS)
        @- echo "Compilaci▒n de libreria terminada $(LIB)" 
 
####################################################################### 
# Target para eliminar Objetos.                                       # 
####################################################################### 
LIMPIA: 
        @- rm -f $(OBJS) 
        @- echo "Borrado de objetos terminada $(LIB)" 
 
####################################################################### 
# Target para eliminar Objetos y ejecutable.                          # 
####################################################################### 
BORRA: 
        @- rm -f $(OBJS) $(LIB) 
        @- echo "Borrado de archivos terminada $(LIB)" 
 
####################################################################### 
# Dependencia de Objetos con fuentes.                                 # 
####################################################################### 
.c.o: 
        $(COMPILADOR) -c -I$(RUTA_INCL) $*.c 
 
####################################################################### 
# Dependencia de Objetos con headers.                                 # 
####################################################################### 
$(OBJS): $(HEADER) 