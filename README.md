# Arduino Marble Maze

Proyecto realizado para la materia de Introducción a la Electrónica y Programación de Controladores con Arduino de la UNQ, consistente en un laberinto físico controlado mediante un joystick y una placa Arduino UNO.

El sistema utiliza dos servomotores SG90 para inclinar el tablero sobre los ejes X e Y. La posición del joystick es leída por el Arduino, que calcula el ángulo correspondiente para cada servo permitiendo controlar el movimiento de una canica a través del laberinto.

## Componentes

- Arduino UNO R3
- 2 × Servomotores SG90
- Módulo Joystick analógico
- Protoboard y cables
- Estructura construida en cartón

## Contenido del repositorio

- `marble_maze.ino`: código principal del proyecto.
- `marble-maze-wire-diagram.png`: esquema de conexiones.
- `marble-maze-structure.pdf`: planos para construir la estructura de cartón.

## Cómo utilizar

1. Construir la estructura siguiendo los planos incluidos.
2. Realizar las conexiones según el esquema del circuito.
3. Abrir `arduino-marblemaze.ino` con Arduino IDE.
4. Seleccionar la placa **Arduino Uno** y el puerto correspondiente.
5. Compilar y cargar el programa en la placa.
6. Alimentar el circuito y controlar el laberinto mediante el joystick.

## Mejoras realizadas

El proyecto fue desarrollado a partir del tutorial de Instructables de **ahmedazouz**. Sobre el código original se realizaron distintas modificaciones, entre ellas:

- Movimiento más suave de los servomotores.
- Reorganización y documentación del código.
- Ajustes para mejorar la legibilidad y facilitar futuras modificaciones.

## Referencias

- Tutorial original: https://www.instructables.com/Arduino-Marble-Maze-Labyrinth/
- Video demostración: https://youtube.com/shorts/6oUgudLQrGA
