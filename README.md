# Proyecto: Recomendador de mazos para Marvel Snap
Este proyecto es un *"Recomendador de mazos" para el videojuego Marvel Snap.* usa como guía la siguiente página web [Marvel Snap Card Database](https://marvelsnapzone.com/cards/) 

Marvel Snap es un videojuego de cartas coleccionables digital, cada juego dura aproximadamente 3 minutos y consta de solo 6 turnos, el objetivo es conseguir la mayor puntuación de poder en al menos 2 de las 3 localizaciones del tablero, los mazos son de solo 12 cartas únicas (sin duplicados), cada partida cuenta con tres ubicaciones aleatorias que tienen efectos únicos (por ejemplo doblar el poder o que no se puedan jugar cartas de costo 1), estos efectos en las localizaciones hacen que se cambie por completo la estrategia en cada juego. 

Además cuenta con una mecánica insignia inspirada en el póker: el “snap”, ya que si confías en tu victoria, puedes hacer “snap” para duplicar los puntos (cubos) de clasificación que ganas en cada juego. El rival puede aceptar la apuesta o retirarse para perder solo un cubo en lugar de varios, lo mismo para el jugador en caso de que su rival haga un "snap".

Durante el juego, terminas teniendo una colección masiva de cartas, este programa ayudará a gestionar esta colección y ayudar al usuario a armar el mazo ideal según diferentes criterios (como tener cierta cantidad de cartas con ciertos costos de energía o hacer un orden por tipos de poder).


## Descripción del avance 1
> En el primer avance solo se podía ordenar una colección pre-cargada en el programa con base en el atributo que decida el usuario (costo, poder, tasa de victoria).

Ordenar una serie de cartas (se proporcionarán los datos de mi colección actual):

- Por su poder: el poder de una carta va de -3 hasta 15, se ordenará de mayor a menor para ver las cartas más fuertes primero.

- Por el costo de energía: las cartas pueden costar de 0 a 6 puntos de energía, se ordenará de menor a mayor, para ver las cartas que cuestan menos primero.
  
- Por la tasa de victoria: puede ser de 1 en adelante, se ordenará de mayor a menor para ver las cartas que más han triunfado primero.

## Descripción del avance 2
En este segundo avance se corrigieron las observaciones del avance 1, también se agregaron dos métodos al main del proyecto: 

- Cargar una colección: para empezar a usar el programa ahora tendrá que cargarse un archivo de texto, el cual será evaluado.

> Se proporcionan 4 archivos de textos diferentes para probar el funcionamiento del programa.

- Crear un mazo con altas tasas de victoria: se agregó una nueva función que usa un Merge para poder obtener las 12 cartas con mayor tasa de victoria, luego junta esas 12 cartas en una cola/queue y las muestra al usuario.

### Cambios sobre el primer avance
1. Cambiar Sí y No a ser controlados por 0 y 1, en lugar de 1 y 2: para que el programa pueda ser usado más fácilmente.
2. Implementar un solo Merge en lugar de tres para cada atributo: esto se hizo para simplificar el código. 
3. Opción de cargar una colección: para poder aplicar la competencia de lectura de archivos y poder cambiar los datos que el programa va a analizar.
4. Opción de crear un mazo con altas tasas de victoria: para poder cumplir el propósito del programa, y aplicar la competencia de usar otras estructuras de datos.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

> g++ main.cpp -o intento

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

> ./intento

## Instrucciones para ejecutar el avance de proyecto

> Elegir la opción 3 y cargar datos al programa, ver la siguiente sección para más información.

## Descripción de las entradas del avance de proyecto
Para cargar datos en el programa, ya se incluyen ejemplos de 4 archivos diferentes de texto para cargar, lo único que el usuario tiene que hacer es seguir los siguientes pasos:
1. Elegir la opción "3"
2. Escribir alguno de estos nombres cuando pide el "Nombre del archivo:"
> coleccion1.txt

> coleccion2.txt

> coleccion3.txt

> coleccion4.txt

Si el usuario desea ingresar su propia colección de cartas, lo que tiene que hacer es crear un archivo de texto (.txt)

Y en cada línea del archivo escribir:

> Nombre, costo, poder, tasa de victoria

Por ejemplo:

> Gambit,3,3,43.2

Datos importantes a considerar: 
1. Los valores deben estar separados por comas, no se puede usar ningún otro tipo separador como espacios o comillas o cualquier otro símbolo que no sea una coma.
2. Se deben ingresar mínimo 12 cartas.
3. Las cartas deben ser diferentes, no pueden repetirse.

## Descripción de las salidas del avance de proyecto
El programa muestra en la terminal lo que el usuario haya decidido que muestre.
1.Si se elige la opción de cargar una colección, luego de cargar el archivo, el programa le dirá al usuario si la carga fue exitosa o no.
2. Si se elige la opción de mostrar colección actual, se mostrarán los nombres de las cartas de la colección actual.
3. Si se elige la opción de ordenar por poder, se mostrará el nombre de las cartas y el valor de su poder, de mayor a menor.
4. Si se elige la opción de ordenar por costo, se mostrará el nombre de las cartas y el costo que tienen, de menor a mayor.
5. Si se elige la opción de ordenar por tasa de victoria, se mostrará el nombre de las cartas y la tasa de victoria que tienen, de mayor a menor.
6. Si se elige la opción de crear un mazo con altas tasas de victorias, se mostrarán las 12 cartas con mayor tasa de victoria de la colección.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
El algoritmo de ordenamiento que se usa es Merge, y en el mejor, peor y caso promedio tiene una complejidad de O(n log n) y en espacio de: O(n).

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

Una fila o queue tiene una complejidad espacial de: O(n) y una complejidad temporal de: O(1) en el caso de este programa, ya que solo uso los métodos de queue, enqueue y otros que tienen esta complejidad.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Elegí el algoritmo de ordenamiento de merge, porque mantiene la misma complejidad temporal y creo que esto es útil ya que no sé cuantas cartas llegará a manejar el programa, y este algoritmo permite que aunque la colección crezca, el comportamiento general del programa sea predecible.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Uso la estructura de datos <queue> o fila porque me ayuda a que las primeras cartas que ingreso a la fila (que son las mayores) sean también las primeras en salir, y eso es justo lo que quiero, mostrar las 12 cartas que tienen las tasas de victoria más altas. 

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos correctos para consultar información de las estructuras.
Considero que si consulto de forma correcta la información que incluyo en las estructuras, ya que ingreso a cada posición y extraigo los valores necesarios para que el programa sea útil para el usuario.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Considero que si implemento mecanismos para leer los archivos, ya que creé otra clase, llamada "Carga" donde tengo un método que me permite leer los datos de distintos archivos de texto siempre y cuando estos sigan el formato antes especificado.
