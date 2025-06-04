# Trabajo Práctico de System Programming

Arquitectura y Organización del Computador

## Partes

- [Parte 1: Pasaje a modo protegido](modo-protegido.md)

## Introducción

Durante la actual y las próximas clases, vamos a adentrarnos al mundo de
System Programming. Como hemos visto en la teórica, al arrancar una
computadora, hay una serie de tareas que realiza el sistema operativo
que tienen como objetivo crear un entorno controlado y seguro donde
ejecutar programas y arbitrar el acceso a los recursos.

El trabajo va a ser incremental a lo largo de varias clases prácticas.
Vamos a crear un único software en modo 32 bits desde hoy a fin de
cuatrimestre. Por lo tanto, cada encuentro va a tener el mismo conjunto
de archivos y código al cual se le van a ir agregando más código y
nuevos archivos.

Clase a clase, vamos a trabajar una perspectiva o parte diferente del
sistema.

## El manual

Intel nos ofrece documentación para que podamos llevar a cabo la tarea
antes descripta. A partir de ahora, vamos a utilizar también el manual:

[*Intel® 64 and IA-32 Architectures Software Developer's Manual Volume 3
(3A, 3B, 3C & 3D):System Programming
Guide*](https://software.intel.com/content/dam/develop/external/us/en/documents-tps/325384-sdm-vol-3abcd.pdf)

Adicionalmente, van a tener que consultar los manuales que vimos en la
primeras clases:

[*Intel® 64 and IA-32 Architectures Software Developer\'s Manual Volume
1: Basic
Architecture*](https://software.intel.com/content/dam/develop/external/us/en/documents-tps/253665-sdm-vol-1.pdf)

[*Intel® 64 and IA-32 Architectures Software Developer\'s Manual Volume
2: Instruction Set Reference,
A-Z*](https://software.intel.com/content/dam/develop/external/us/en/documents-tps/325383-sdm-vol-2abcd.pdf)

## QEMU

Vamos a utilizar como entorno de pruebas el programa QEMU. Este nos
permite simular el arranque de una computadora IBM-PC compatible.

Como vimos en las clases teóricas, al inicio, una computadora comienza
con la ejecución del POST y del BIOS. El BIOS se encarga de reconocer el
primer dispositivo de booteo. En nuestro taller, vamos a utilizar como
dispositivo un Floppy Disk (el disquete en lugar del disco rígido como
suele ser comúnmente). Para eso, vamos a utilizar una imagen Floppy Disk
virtual en QEMU como dispositivo de booteo. En el primer sector del
floppy, se almacena el boot-sector (sector de arranque). El BIOS se
encarga de copiar a memoria 512 bytes del sector de booteo, y dejarlo a
partir de la dirección `0x7C00`. Luego, se comienza a ejecutar el código a
partir de esta dirección. El boot-sector debe encontrar en el floppy el
archivo `KERNEL.BIN` y copiarlo a memoria. Éste se copia a partir de la
dirección `0x1200`, y luego se ejecuta a partir de esa misma dirección.

Es importante tener en cuenta que el código del boot-sector se encarga
exclusivamente de copiar el kernel y dar el control al mismo, es decir,
no cambia el modo del procesador. Este código inicial viene dado en el
taller y nuestro trabajo, a partir de ahí, va a ser construir parte de
ese kernel de modo que a final de cuatrimestre, pueda ejecutar programas
y tareas sencillas.

## Preparación: actualizando su fork del repositorio grupal

Iremos agregando distintas partes al TP a medida que vayamos presentando los temas correspondientes. En general estas partes llegarán en forma de un **PR automáticamente abierto en su repositorio y deben aceptar**. Dejamos instrucciones de como hacerlo en la próxima sección. Puede ocurrir que dichos PRs fallen en crearse, en cuyo caso deben seguir las instrucciones de la sección correspondiente más abajo **en una branch distinta a main**. Es probable que una vez actualicen main manualmente, no podamos crear más PRs automáticos para entregas siguientes. Solo tiene 4 partes el TP, así que esto no es grave.

### Actualizando su fork mediante el PR automático
[Pendiente]

### Actualizando su fork manualmente
Estas son las instrucciones para sincronizar manualmente su fork grupal con el taller de **system programming**. Deben seguirlas en una branch distinta a main.

1. Agregar el repositorio de la cátedra como *upstream* remoto:
   - Si usaron https:
	```sh
	git remote add upstream https://github.com/AyOC-exactas/TP-SP.git
	```
   - Si usaron ssh:
	```sh
	git remote add upstream git@github.com:AyOC-exactas/TP-SP.git
	```
2. Traer el último estado del upstream
```sh
git fetch upstream
```
3. Moverse al branch donde quieran traer los cambios, se sincronizarán en dicha branch únicamente
```sh
git checkout <branch>
```
4. Combinar los cambios locales con los del *upstream*
```sh
git merge upstream/main
```

Es posible que al ejecutar el merge les aparezca CONFLICT y diga que arreglen los conflictos para poder terminar el merge.
En ese caso, deben:
1. Resolver los conflictos, ya sea con la herramienta de resolución de conflictos de VScode o a mano (se recomienda utilizar VScode).
2. Una vez resueltos los conflictos, tomar nota de cuales archivos tenían conflictos que fueron resueltos y ejecutar:
```sh
git add <archivos modificados>
git commit -m "Merge con actualizaciones cátedra"
git push origin
```

Cuando estén listos para avanzar con la siguiente parte del taller, tienen dos opciones. Antes de hacer cualquiera de las dos **deben** pararse en la branch donde estuvieron trabajando en la solución de la parte anterior y pushear todos sus cambios actuales mediante `git push`.
1. Crear una nueva branch desde main y traer los cambios de la parte anterior desde la branch donde hayan trabajado, de forma manual o con git cherry-pick.
2. Pararse en la branch con su trabajo actual (`git switch <branch>`) y actualizarla con los nuevos contenidos mediante `git merge upstream/main`.
