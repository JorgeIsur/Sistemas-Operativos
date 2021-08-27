#!/bin/ksh
#######################################################################
# Shell script para compilar la libreria de ecuación grado 4		  #
#																	  #
# $Id: compilar.sh,v 1.1.1.1 2018/01/29 20:36:45 hpl Exp $																  #
#																	  #
# $Author: hpl $															  #
#######################################################################

#######################################################################
# Ruta actual.														  #
#######################################################################
ACTUAL=`pwd` 

#######################################################################
# Ruta de lib.														  #
#######################################################################
cd ../../lib 
LIB=`pwd` 
cd $ACTUAL

#######################################################################
# Ruta de incl.														  #
#######################################################################
cd ../incl
INCL=`pwd` 
cd $ACTUAL

#######################################################################
# Compilar.															  #
#######################################################################
make $* RUTA_LIB=$LIB/ RUTA_INCL=$INCL/ 