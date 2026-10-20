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
Escribe aquí la descripción de lo que contiene este avance. 

### Cambios sobre el primer avance
1. Escribe la lista de cambios realizados sobre el planteamiento original: Argumenta la razón por la que decidiste el cambio. Estos argumentos puedes retomarlos más adelante en tu argumentación de competencias.
2. Cambio 2: Razón del cambio
3. Cambio 3: Razón del cambio
4. etc...: etc...

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

> g++ main.cpp -o intento

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

> ./intento  

## Descripción de las entradas del avance de proyecto
Escribe aquí la descripción de las entradas del proyecto, por ejemplo, si de entrada se requieren varios archivos, hay que indicar el formato de cada uno de ellos, y proporcionar un ejemplo de los datos de cada archivo.

## Descripción de las salidas del avance de proyecto
Escribe aquí la descripción de los resultados de la ejecución de tu programa.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
El algoritmo de ordenamiento que se usa es Merge, y en el mejor, peor y caso promedio tiene una complejidad de O(n log n) y en espacio de: O(n).

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
   Elegí el algoritmo de ordenamiento de merge, porque mantiene la misma complejidad temporal y creo que esto es útil ya que no sé cuantas cartas llegará a manejar el programa, y este algoritmo permite que aunque la colección crezca, el comportamiento general del programa sea predecible.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.
