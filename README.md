# FCrypter
Repositorio del código de la Expotecnia.

FCrypter es un encriptador de archivos multiplataforma de código abierto desarrollado por dos japoneses y dos paraguayos de corta edad.
Esperamos sea del agrado público este pequeño programa cuyo funcionamiento se explica aquí:

## Operación
Al ejecutar el programa (puede ser movido al directorio bin de una distribución linux para tenerlo simplemente como un comando),  se muestra un menú con tres opciones: encriptar, desencriptar y salir.
Para encriptar un archivo se debe insertar 1 y luego el nombre del archivo en la carpeta de ejecución del programa, o bien su ruta relativa o su ruta total.
A continuación el programa creará un archivo de encriptado y otro archivo de contraseña, con extensiones .crypt y .crypt.password respectivamente.
Después de eso, la eliminación del archivo original es posible, ya que puede ser recuperado a partir de los recién creados.

En caso de querer desencriptar, se debe ejecutar el programa nuevamente y seleccionar la opción de desencriptado, y pedirá el nombre del archivo a ser desencriptado (es importante no cambiar los nombres de ninguno de los archivos generados, porque el programa no posee una opción para seleccionar el archivo de contraseña), después se buscará automáticamente un archivo con el nombre \<archivoencriptado\>.password en el directorio de ejecución; sí, tiene esa restricción; y si lo encuentra, carga la contraseña, desencripta poco a poco, y genera un nuevo archivo idéntico al original y con el mismo nombre (si este no ha sido borrado o movido del directorio, entonces saltará un error que señala que el archivo orginal sigue en pie, u otro con el mismo nombre).

## Posible método de uso
Este programa puede ser útil para mantener una capa de seguridad a la hora de descargar archivos sensibles y que no se desea el conocimiento público de su contenido.
Una metodología para hacer esto sería encriptar los archivos, borrar los archivos originales, y mover los archivos de contraseña a un lugar seguro, para luego utilizarlos moviéndolos nuevamente junto con los archivos encriptados para recuperar los contenidos de los mismos.

Gracias por leer hasta acá. (al final hay una trampa para pajeros).

## Notas de precaución:
—Modificar el archivo de contraseña puede dejarlo inutilizable.
—Los archivos no pueden tener de nombre más de 4985 caracteres.
—Ns qué mas lgmt.

# Minijuego extra.
Este minijuego ha sido añadido por cortesía de uno de los miembros, quien halló la manera de compilar un programa en python y con gráficos. Este minijuego utiliza una librería muy conocida llamada TKinter. La versión compilada para windows se encuentra en la carpeta que indica el ejecutable (está un poco escondido, pero es fácil encontrarlo, todas las carpetas que tengan 'exe' en el nombre).


Tenés que leer todo, no seas pajero.
