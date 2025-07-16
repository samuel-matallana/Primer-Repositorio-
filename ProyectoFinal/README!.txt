# Proyecto Final - Filtros PGM con Apptainer

Este repositorio contiene una imagen de contenedor (`.sif`) creada con Apptainer para ejecutar filtros sobre imágenes `.pgm`.

##  Archivos incluidos

 pgm_filters.def
 pgm_filters.sif(aa, ab) _(dividido en partes por límites de GitHub)
Dado que nuestro archivo .sif esta divido, aquí están las recomendaciones para reconstruirlo( no se preocupen, están relativamente fáciles de seguir)

Instrucciones para recomponer a .sif 

Es fundamental que tengas apptainer instalado, y es el paso 0, hay muchos tutoriales que te pueden ayudar a instalarlo en caso de que no lo tengas y no sepas como se hace

Como el archivo `.sif` supera los 100MB, se ha dividido en partes utilizando Split vamos a reconstruirlo:

INSTRUCCIONES:


Desde la raíz del proyecto, entra a la carpeta en la que están ubicados pgm_filters_xz_part(aa, ab)

Luego abre un bash, una vez en el bash debes introducir el siguiente comando: (hasta copiado y pegado si quieres)

cat pgm_filters_xz_part_* > pgm_filters.sif.xz 

Tras hacer esto, debes realizar el comando:

xz -d pgm_filters.sif.xz

Luego debes introducir el comando:

apptainer run pgm_filters.sif

Todo esto estando en el bash.

Y ya estaría completo y listo para correr tu programa.