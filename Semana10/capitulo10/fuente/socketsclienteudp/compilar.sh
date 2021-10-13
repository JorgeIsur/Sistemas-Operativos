#!/bin/ksh
#Shell Script de compilación de clienteudp
ACTUAL=$PWD
cd ../../bin 
BIN=`pwd`
cd $ACTUAL
cd ../incl
INCL=$PWD/
cd $ACTUAL
cd ../util
UTIL=$PWD/
cd $ACTUAL

make $* RUTA_BIN=$BIN/ RUTA_INCL=$INCL/ RUTA_UTIL=$UTIL/
