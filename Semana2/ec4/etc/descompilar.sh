#!/bin/ksh
#######################################################################
# Shell script para descompilar modulos proyecto de ecuación grado 4  #
#																	  #
# $Id: descompilar.sh,v 1.1.1.1 2018/01/29 20:36:45 hpl Exp $																  #
#																	  #
# $Author: hpl $															  #
#######################################################################

#######################################################################
# Ruta de los fuentes.												  #
#######################################################################
cd ../fuente
ACTUAL=$PWD

#######################################################################
# Descompilar modulos.												  #
#######################################################################
for directorio in *
do
	if
		test -d $ACTUAL/$directorio
	then
		cd $ACTUAL/$directorio
	else
		continue
	fi
	for shellscript in *.sh
	do
		if
			[ -x $PWD/$shellscript ]
		then
			$shellscript BORRA
			echo ""
		fi
	done
done
