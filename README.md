# Ev.1_Proyecto-final
Proyecto final para la UF: TC1031, Programación de estructuras de datos y algoritmos fundamentales.

## Avance 1

Este proyecto es un *"Recomendador de mazos" para el videojuego Marvel Snap.*

*Resumen del juego:* 
Marvel Snap es un videojuego de cartas coleccionables digital, cada juego dura aproximadamente 3 minutos y consta de solo 6 turnos, el objetivo es conseguir la mayor puntuación de poder en al menos 2 de las 3 localizaciones del tablero, los mazos son de solo 12 cartas únicas (sin duplicados), cada partida cuenta con tres ubicaciones aleatorias que tienen efectos únicos (por ejemplo doblar el poder o que no se puedan jugar cartas de costo 1), estos efectos en las localizaciones hacen que se cambie por completo la estrategia en cada juego. 

Además cuenta con una mecánica insignia inspirada en el póker: el “snap”, ya que si confías en tu victoria, puedes hacer “snap” para duplicar los puntos (cubos) de clasificación que ganas en cada juego. El rival puede aceptar la apuesta o retirarse para perder solo un cubo en lugar de varios, lo mismo para el jugador en caso de que su rival haga un "snap".

*Resumen del proyecto:* 
Durante el juego, terminas teniendo una colección masiva de cartas, este programa ayudará a gestionar esta colección y ayudar al usuario a armar el mazo ideal según diferentes criterios (como tener cierta cantidad de cartas con ciertos costos de energía o hacer un orden por tipos de poder).

*El primer avance* 
Ordenar una serie de cartas (se proporcionarán los datos de mi colección actual):

- Por su poder: el poder de una carta va de -3 hasta 15, se ordenará de mayor a menor para ver las cartas más fuertes primero.

- Por el costo de energía: las cartas pueden costar de 0 a 6 puntos de energía, se ordenará de menor a mayor, para ver las cartas que cuestan menos primero.
  
- Por la tasa de victoria: puede ser de 1 en adelante, se ordenará de mayor a menor para ver las cartas que más han triunfado primero.

### Los criterios de sub-competencias a evaluar en este avance son:
-> SICT0301: Evalúa los componentes
  * Análisis de complejidad para los algoritmos de ordenamiento:
    El algoritmo de ordenamiento que se usa es Merge, y en el mejor, peor y caso     promedio tiene una complejidad de O(n log n) y en espacio de: O(n).
    
  * Análisis de complejidad para las estructuras de datos:
    La estructura de datos que uso es <vector>, tiene un acceso O(1) a vector[i].
    
  * Análisis de los demás componentes del programa:
    Uso la clase tipo "tarjeta" para poder comparar los distintos atributos que      puede tener una tarjeta, y quizá en un futuro agregar más atributos; también     uso una función merge que toma en cuenta el atributo con base en el cuál         quiero ordenar, para así no escribir tres veces el mismo algoritmo de            búsqueda.
    
  * Complejidad final del programa: O(n log n)

-> SICT0302: Toma decisiones
  * ¿Por qué seleccioné este algoritmo de ordenamiento?
    Elegí el algoritmo de ordenamiento de merge, porque mantiene la misma            complejidad temporal y creo que esto es útil ya que no sé cuantas cartas         llegará a manejar el programa, y este algoritmo permite que aunque la            colección crezca, el comportamiento general del programa sea predecible.
    
  * ¿Por qué seleccioné estas estructuras de datos?
    Elegí un vector de objetos de tipo Carta porque me permite almacenar los         atributos de las cartas y proporciona acceso directo a sus elementos             mediante índices con una complejidad O(1). Además, me permite incorporar         nuevas cartas a la colección conforme esta aumente.
