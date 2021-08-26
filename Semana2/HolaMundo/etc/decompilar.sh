#!/bin/ksh 
####################################################################### 
# Shell script para descompilar modulos del proyecto                  # 
#                                                                     # 
# $Id$                                                                # 
#                                                                     # 
# $Author$                                                            # 
####################################################################### 
 
####################################################################### 
# Ruta de los fuentes.                                                # 
####################################################################### 
cd ../fuente 
ACTUAL=$PWD 
 
####################################################################### 
# Descompilar modulos.                                                # 
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
                        ./$shellscript BORRA 
                        echo "" 
                fi 
        done
done