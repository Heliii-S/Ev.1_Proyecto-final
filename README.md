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

## Descripción del avance 3
Escribe aquí la descripción de lo que contiene este avance. 

### Cambios sobre el segundo avance
1. Se cambió la forma de implementar la queue o fila, ya no se encuentra implementada solamente sobre un vector, sino que al momento de crear una sugerencia de mazo y al hacer una simulación simple de una partida, se usa una lista ligada para guardar ahí las cartas seleccionadas, así se pueden realizar acciones de forma más eficiente sobre todo para la opción de simulación que se añadió en este avance.
2. Se agregó una nueva opción que es la opción de simular la entrega de cartas (solamente como se van entregando al jugador, no se realiza nada más); como en el juego se te van dando las cartas del mazo de forma aleatoria y tal como en el juego, es posible que algunas cartas no salgan nunca en la partida. Este pequeño simulador empieza mostrando al usuario las cuatro cartas que se le dan al inicio (de forma aleatoria). En cada ronda se le permitirá al usuario usar alguna carta o no, y también se le dará la opción de terminar la simulación. Otro aspecto importante de esta simulación es que deja de dar cartas si la mano del jugador se llena (es decir si ya tiene 7 cartas), además, da una carta nueva de forma aleatoria al inicio de cada turno, tal y como en el juego.
3. Se agregó una nueva función para guardar el resultado del análisis de cada colección, el reporte incluye los datos que se obtendrían si seleccionaras cada opción del menú (excepto la simulación) y se genera un archivo de texto aparte con el nombre de: "resultados.txt".

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

3. Si se elige la opción de cargar una colección, luego de cargar el archivo, el programa le dirá al usuario si la carga fue exitosa o no.
   
4. Si se elige la opción de mostrar colección actual, se mostrarán los nombres de las cartas de la colección actual.
   
5. Si se elige la opción de ordenar por poder, se mostrará el nombre de las cartas y el valor de su poder, de mayor a menor.
   
6. Si se elige la opción de ordenar por costo, se mostrará el nombre de las cartas y el costo que tienen, de menor a mayor.
   
7. Si se elige la opción de ordenar por tasa de victoria, se mostrará el nombre de las cartas y la tasa de victoria que tienen, de mayor a menor.
   
8. Si se elige la opción de crear un mazo con altas tasas de victorias, se mostrarán las 12 cartas con mayor tasa de victoria de la colección.
   
9. Si se elige la opción de simular una partida con el mazo recomendado, se empezarán a mostrar las cartas entregadas en cada turno, y al usuario se le permitirá "jugar" alguna de esas cartas, pasar de turno (0) o salir de la simulación (8).
    
10. Si se elige la opción de generar un archivo con el análisis realizado, se genera un archivo de texto aparte con el nombre de: "resultados.txt". Este archivo incluye los datos obtenidos luego de realizar: un ordenamiento por poder, por costo, por tasa de victoria, y un mazo que se recomienda. Todo esto lo puede hacer siempre y cuando se le haya brindado una colección válida al programa.
    
# Desarrollo de competencias

## SICT0301: Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

El algoritmo de ordenamiento que se usa es Merge, y en el mejor, peor y caso promedio tiene una complejidad de O(n log n) y en espacio de: O(n).

### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

En este programa uso 3 estructuras de datos: una queue o fila, listas enlazadas y vectores.

Las operaciones que realizo con la fila son: enqueue, dequeue, front, empty, full, con complejidad temporal O(1) en el mejor caso, peor caso y caso promedio). Además uso clear, con complejidad temporal O(1) en el mejor de los casos, y O(n) en el peor de los casos y el caso promedio, tiene este valor en el caso promedio en lugar de un O(1) porque al usar una queue con listas enlazadas, cada vez que se libera la memoria se debe liberar la memoria de cada nodo uno por uno.

En cuanto a la complejidad espacial, la queue tiene una complejidad total de O(n) y de O(1) por operación. 

Con respecto a la lista enlazada, su complejidad espacial y temporal es de O(1) por cada nodo en el mejor, peor y caso promedio. 

Por último, con el vector, el acceso a cartas[i] y size() tiene una complejidad temporal de O(1) en el mejor caso, el caso promedio y el peor caso. Pero en general el vector tiene una complejidad temporal de O(n) combinando el mejor caso, promedio y el caso peor de acciones como: insertar en medio, eliminar en medio, recorrer elementos, etc. 

En cuanto a la complejidad espacial, el vector tiene una complejidad espacial de O(n): porque el vector almacena n elementos y necesita memoria proporcional a la cantidad de elementos.

### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

La complejidad temporal general del programa es O(n log n) y su complejidad espacial es O(n), donde "n" representa el número de cartas almacenadas en la colección.

Esto se debe a que, la mayor parte de las operaciones individuales, como consultar los atributos de una carta, insertar o eliminar elementos de la cola y acceder a posiciones del vector, tienen una complejidad constante O(1). Por otro lado, recorrer, cargar y guardar una colección requiere O(n), ya que es necesario procesar sus elementos.

El algoritmo que tiene mayor influencia en la complejidad final es el “Merge”, utilizado para ordenar las cartas por poder, costo y tasa de victoria. Ya que su complejidad temporal es O(n log n), tanto en el mejor como en el promedio y peor caso. 
Además, las opciones de creación de mazos, guardado de resultados y simulación de partidas también utilizan este algoritmo, por lo que su complejidad temporal termina siendo,  también: O(n log n). 

## SICT0302: Toma decisiones
### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Elegí el algoritmo de ordenamiento de "Merge", porque mantiene la misma complejidad temporal y creo que esto es útil ya que no sé cuantas cartas llegará a manejar el programa, y este algoritmo permite que aunque la colección crezca, el comportamiento general del programa sea predecible.

### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

En el proyecto se utilizan tres estructuras de datos: filas o <queues>, listas enlazadas para implementar la fila y vectores.

La fila se utiliza para almacenar y entregar las cartas del mazo recomendado. 
Su funcionamiento hace que la primera carta que ingresa es también la primera en salir. Esto resulta útil para simular la entrega de cartas al jugador, ya que permite obtenerlas en el mismo orden en el que fueron organizadas después de mezclar el mazo.

> Es importante mencionar que la selección de las 12 cartas con mayor tasa de victoria no depende directamente de la cola, sino del “Merge”, que ordena la colección de mayor a menor tasa de victoria. Ya que cuando ya se encuentran ordenadas las cartas de mayor a menor es cuando las primeras 12 se agregan a la estructura Queue.

Se eligió una fila en lugar de una pila porque en las pilas, el último elemento que ingresa es el primero en salir y ese comportamiento no sería el más adecuado para la entrega de cartas que se busca simular.

Por otra parte, se usa una lista simplemente enlazada para implementar la fila. Esta estructura está formada por nodos que almacenan una “carta” y una referencia al siguiente nodo (o carta). Además, permite agregar elementos al final y eliminarlos al inicio en tiempo constante O(1).

Una ventaja de esta implementación es que la memoria se asigna dinámicamente conforme se agregan nuevos nodos, sin necesidad de reservar una capacidad fija desde el inicio. Además, no es necesario desplazar los demás elementos al insertar o eliminar una carta, a diferencia de algunas operaciones realizadas sobre un vector.

Finalmente, se usan vectores para almacenar la colección completa de cartas, ordenar copias de esta colección y administrar las cartas que tiene el jugador durante la simulación. Se eligió porque permite acceder directamente a cualquier posición mediante un índice.

## SICT0303: Implementa acciones científicas
### Implementa mecanismos correctos para consultar información de las estructuras.

Considero que si consulto de forma correcta la información que incluyo en las estructuras, ya que en cada clase tengo declarados getters que me permiten obtener los valores que las estructuras están guardando. Por ejemplo: en la clase nodo tengo un getter para obtener el dato que guarda y el dato del nodo siguiente. En la clase queue uso los métodos de front o empty para conocer el valor al principio de la fila o si la fila se encuentra vacía. En la clase carta tengo getters para conocer le valor de cad uno de los atributos de una carta (nombre, costo, poder y tasa de victoria)

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

Considero que si implemento mecanismos para leer los archivos, ya que creé otra clase, llamada "Carga" donde tengo un método que me permite leer los datos de distintos archivos de texto siempre y cuando estos sigan el formato antes especificado.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta

Considero que si implemento mecanismos para leer los archivos, ya que dentro de la clase que se creó en el avance anterior (llamada "Carga") agregué un método que permite guardar los datos obtenidos luego de realizar: un ordenamiento por poder, por costo, por tasa de victoria, y un mazo que se recomienda. Todo esto lo puede hacer siempre y cuando se le haya brindado una colección válida al programa.
