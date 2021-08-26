#!/bin/ksh 
####################################################################### 
# Shell script para compilar modulos del proyecto                     # 
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
# Compilar libreria.                                                  # 
####################################################################### 
cd $ACTUAL/lib 
for shellscript in *.sh
do 
        if 
                [ -x $PWD/$shellscript ]
        then 
                ./$shellscript 
                echo "" 
        fi 
done 
cd $ACTUAL 
 
####################################################################### 
# Compilar modulos.                                                   # 
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
                        ./$shellscript 
                        echo "" 
                fi 
        done 
done 