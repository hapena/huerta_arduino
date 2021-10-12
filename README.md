# huerta_arduino

                                                                           INTELLIGEN GREENHOUSE
                                                           
                                                           
Descripción del proyecto:

El proyecto Huerta Inteligente se plantea en el contexto de la revolución industrial 4.0 y el uso de las TIC en el ámbito urbano; debido a la constante necesidad del uso adecuado de los recursos naturales y en la búsqueda  de incrementar y mejorar la producción de  productos de primera necesidad se genera la idea de automatizar  las huertas existentes o de generar nuevas huertas tecnológicas y controladas para autoconsumo.
La Academia Cisco del colegio Jorge Gaitán Cortés utilizará cómo herramientas mediadoras la programación en Python y Arduino, los conceptos de Internet de las Cosas y Redes para mejorar y crear las condiciones de producción de alimentos de primera necesidad en entornos controlados para espacios urbanos como patios o terrazas de casas o edificios. 
En el proyecto participarán estudiantes de grado décimo y undécimo de la academia CISCO, quienes generarán   prototipos del sistema de control de la huerta inteligente a través de distintos sistemas que monitorean y generan las condiciones óptimas para el mejoramiento de la producción de productos como verduras, hortalizas, frutas, legumbres o plantas aromáticas.
Debido a todo lo anterior el sistema creado se podrá ir mejorando y actualizando según las tecnologías que vayan saliendo en el mercado.
El proyecto será asesorado por los instructores de la Academia SED-CISCO Jorge Gaitán Cortes IED.

Los estudiantes están en proceso de certificación CISCO en Partner: PCAP - Programming Essentials in Python, IoT Fundamentals: Connecting Things y CCNAv7: Introduction to Networks.
Se cuenta con el material de laboratorio ofrecido por la institución educativa; entre ellos las plataformas de desarrollo basadas en hardware Libre (Arduino UNO R3, Raspberry Pi 4 Modelo B 4gb Kit, Esp32 Wifi + Bluetooth 4.2 Ble Nodemcu Esp32s), sensores y actuadores; además en la parte del software se trabaja, Python 3, Arduino, Thonny IDE, y las plataformas de desarrollo de Cisco Webex Teams. 	

Ambiente de desarrollo: 

![image](https://user-images.githubusercontent.com/71275875/136999445-6c7675c3-f7f5-41dd-9652-672586e57242.png)


En este apartado se procederá a explicar el contenido el cual es la base para que el programa funcione de la manera establecida, se abordarán aspectos del código y se profundizará en el circuito conformado para este proyecto. 


Circuito:



Recursos:


Arduino Uno: 
 
 ![image](https://user-images.githubusercontent.com/71275875/136999593-7f404fe8-9938-4f9a-b961-8ab067cb15eb.png)


Arduino es una plataforma de desarrollo basada en una placa electrónica de hardware libre que incorpora un microcontrolador re-programable y una serie de pines hembra. Estos permiten establecer conexiones entre el microcontrolador y los diferentes sensores y actuadores de una manera muy sencilla.

Sensor de temperatura y humedad DTH11:

 ![image](https://user-images.githubusercontent.com/71275875/136999631-cd11aab2-f0ae-4c54-991c-46570a660ff1.png)

 
El DHT11 es un sensor digital de bajo costo de temperatura y humedad. El sensor de humedad utiliza un principio capacitivo mientras que el de temperatura utiliza un termistor. El sensor se integra fácilmente con un Arduino dado que contiene librerías desarrolladas específicamente para el mismo. Las lecturas del sensor sólo pueden realizarse cada dos segundos

Luz LED 5mm:


![image](https://user-images.githubusercontent.com/71275875/136999666-1307e950-efad-48b1-b115-7da70d8f851f.png)

 
Diodos disponen de un ánodo y un cátodo suelen utilizarse en dispositivos electrónicos como iluminaciones de semáforos, juguetes, publicidades e incluso como alarmas, la funcionalidad varía dependiendo del enfoque que le quiera brindar su usuario.

Sensor de agua: 

![image](https://user-images.githubusercontent.com/71275875/136999708-6f943ba2-9202-4cfb-9a36-46f1734d8b3d.png)

 
El módulo sensor de humedad de suelo resulta ser otro módulo que utiliza la conductividad entre dos terminales para determinar ciertos parámetros relacionados a agua, líquidos y humedad.

Buzzer:

![image](https://user-images.githubusercontent.com/71275875/136999744-24e603d0-b28d-458f-bc2b-ce21f3235260.png)

 Un buzzer pasivo o un altavoz son dispositivos que permiten convertir una señal eléctrica en una onda de sonido.


Sensor Humedad de Suelo


 ![image](https://user-images.githubusercontent.com/71275875/137006028-8a60f294-3f07-4da4-9193-8d34cde876e7.png)


Es un sensor de agua simple que se puede utilizar para detectar la humedad del suelo cuando el módulo de déficit de humedad del suelo genera un nivel alto y viceversa baja


Servomotor:


![image](https://user-images.githubusercontent.com/71275875/136999784-3af49c37-ce25-435f-9831-331cf6c842a5.png)

Un servomotor es un dispositivo eléctrico; el   eje de salida de este motor se puede mover a un ángulo, posición y velocidad particulares que un motor normal no tiene.


Sensor Detector Mq-9 Gas Infamable Monóxido:
 
 ![image](https://user-images.githubusercontent.com/71275875/136999821-674681ae-c733-4179-a13c-9f8d143aa50a.png)
 
El módulo MQ-9 es adecuado para la detección de monóxido de carbono en concentraciones de 10 hasta 1000ppm y gas combustible desde 100 hasta 10000ppm, altamente sensible. La sensibilidad se puede ajustar por un potenciómetro incluido en el módulo.

Ventilador:

![image](https://user-images.githubusercontent.com/71275875/136999902-f116a5f0-d7f3-4cdb-9607-73372b9cfa3a.png)

 
Es un sistema para incrementar el flujo de admisión de aire; gira cuando las variables programadas necesitan extraer y generar aire limpio en el invernadero.


Arduino IDE:

![image](https://user-images.githubusercontent.com/71275875/137000244-6bbfaadc-5dac-4181-980f-d63046f35126.png)

El entorno de desarrollo integrado (IDE) de Arduino es una aplicación multiplataforma que está escrita en el lenguaje de programación Java. Se utiliza para escribir y cargar programas en placas compatibles con Arduino



Lenguaje de programación Arduino: 

![image](https://user-images.githubusercontent.com/71275875/137000513-eb801eef-c7b2-4c17-adf8-fc18b63289e1.png)

Arduino se programa con un lenguaje propio basado en el lenguaje de programación de alto nivel Processing, lo que significa que es similar a C++.


El codigo:


El código ha sido escrito en el lenguaje de programación Arduino; Arduino proporciona un entorno de programación sencillo y potente para programar, pero además incluye las herramientas necesarias para compilar el programa y grabar  el programa ya compilado en la memoria flash del microcontrolador. Además el  IDE nos ofrece un sistema de gestión de librerías para el  sensor  DHT11, el Servo_Motor, el sensor de Agua y diferentes pines de entrada y salida.

1.(Lineas 1 a 2) En primer lugar, se importan las librerias   "Servo, DHT11”, para usar el sensor de temperatura y Humedad ambiente y hacer uso del Servo-Motor.

2.(Lineas 6 a 26) Creamos las diferentes variables asociadas a los PINES IN/OUT de la tarjeta Arduino Uno  que me permitirán realizar la lectura de los diferentes sensores; 
  HUMEDAD Y LUZ, TEMPERATURA, MONOXIDO DE CARBONO, AGUA, BUZZER; Los diferentes LED Utilizados como Indicadores, Motores y Servo_motores.
  
3.(Líneas 32 a 51) void setup; se configuran como se van a comportar los Pines asociados a las diferentes variable; INPUT (Entrada para los sensores),  OUTPUT (Salidas para los actuadores); se inicializa la comunicación Serial.

4.(Líneas 52 a 75) void loop: Creamos el bucle infinito; Realizar la lectura de la humedad del suelo; establece las condiciones de acuerdo con la variable "humedad".

5.(Líneas 81  a 130) Creamos el  objeto "sensorDHT” que me permitirán realizar la lectura temperatura y humedad  ambiente. Se establecen las condiciones de acuerdo con la variable temperatura para ser visualizadas en el monitor serial.

6.(Líneas 132 a 152) Creamos la variable para el sensor Detector Mq-9 que me permitirán realizar la lectura monóxido de carbono en el invernadero. Se establecen las condiciones de acuerdo con la variable para ser visualizadas en el monitor serial y se utilizan las salidas para los actuadores (Ventilador).

7.(Líneas 154 a 159) Creamos la variable para el sensor de Agua que me permitirán realizar la lectura de lluvia  en el invernadero. Se establecen las condiciones de acuerdo con la variable para ser visualizadas en el monitor serial y se utilizan las salidas para los actuadores (Servo_motor).


Resultados: 


a. Apertura de Canal de recolección para Agua(Servomotor) activado con el sensor de agua (Lluvia)

![image](https://user-images.githubusercontent.com/71275875/137003827-ab5b872a-a60a-4457-879c-272e87a3f2d1.png)

b. Activación de bomba de agua y Buzzer a través del sensor de Humedad del suelo.

![image](https://user-images.githubusercontent.com/71275875/137004315-807570d5-fd25-476a-b097-04c6a0cf1460.png)


c. Activación del ventilador con el aumento de monóxido de carbono  a través del sensor Detector Mq-9.

![image](https://user-images.githubusercontent.com/71275875/137004682-14349fc7-25b2-44fc-b399-16d295d9a6cd.png)


d.  activación de los actuadores (ventilador, Leds Indicadores) a través del sensor DHT11 de temperatura ambiente.

![image](https://user-images.githubusercontent.com/71275875/137004924-84c06cbe-a685-4b14-9079-2da3b3c6afec.png)


e. visualización de las lecturas y las variables creadas  a través de la consola serial de Arduino.

![image](https://user-images.githubusercontent.com/71275875/137005330-1f9863b7-48cd-46f7-ac7b-69ff93be68f3.png)


Conclusiones: 







Video:

https://www.youtube.com/watch?v=4aPN4FNdY-8


