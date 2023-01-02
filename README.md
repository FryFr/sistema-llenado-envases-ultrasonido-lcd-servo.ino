# Sistema llenado envases ultrasonido lcd servo

### Sebas Silva Tecnologia
¡Bienvenido a este mundo de la robótica! Aquí aprenderás paso a paso todo lo necesario para convertirte en un maestro de las maquinas del futuro.

En este GITHUB vas a encontrar varios proyectos de robotica, electronica y mecanica para la construccion de conocimiento juntos.


# Sistema semi-automatico de distribucion de producto en envases por medio de sensor de ultrasonido, servomotor y LCD

Aqui podras encontrar los detalles de los materiales, conexiones y algunas recomendaciones.

Materiales
-------------
- Servomotor TD-8120MG
- Pantalla LCD I2C
- Sensor de ultrasonido HC-SR04
- Arduino UNO

Procedimiento
-------------

Lo primero es realizar las conexiones entre el arduino y los diferentes materiales, las conexiones iniciales son entre el sensor de ultrasonido y el Arduino Uno, el sensor cuenta con 2 pines llamados Echo y Trigger, los cales deben ser conectados al pin 10 y 9 respectivamente, en caso de que tengas un arduino mega las conexiones son las mismas, lo siguiente es conectar el servomotor, el TD-8120MG cuenta con 3 conexiones, la de color rojo va a una fuente de poder positiva, el cable negro a una fuente de poder negativa, y el cable blanco de senal se conecta al pin 3 del arduino o cualquier otro pin que envie senales PWM, nuestro boton lo podemos conectar al pin 2 y al negativo del arduino. Nuestro display lo vamos a conectar a los pines A4 para el SDA(datos) y A5 para el SLC(reloj), estos pines pueden variar si estas usando un Arduino Uno o un Arduino Mega, te dejo dos imagenes de los pines para cada caso y las conexiones:

![Captura](https://user-images.githubusercontent.com/79547422/210284989-63c85e53-c950-488a-968f-19f1c035494e.JPG)
![7c9dfd832eed7972758545f30d9e6ac9](https://user-images.githubusercontent.com/79547422/210285020-27fdd9e4-4772-4e25-99ef-70de341cee68.jpeg)
![D_NQ_NP_918332-MCO45526687765_042021-O](https://user-images.githubusercontent.com/79547422/210285036-9749fee5-f08e-4fe6-bae3-89e2d50881dc.jpg)

Para poder ejecutar el codigo deberas instalar una libreria que te permita controlar la pantalla con el modulo I2C, solo debes descargar esta libreria e instalarla [LiquidCrystal](https://www.arduinolibraries.info/libraries/liquid-crystal-i2-c) 

-[Libreria LiquidCrystal](https://www.arduinolibraries.info/libraries/liquid-crystal-i2-c) 


Una vez descargada para instalarla debes abrir tu IDE de arduino, si no tienes lo tienes instalado puedes descararlo desde su web de [Software](https://www.arduino.cc/en/software), seleccionas el sistema operaivo en el que lo vas a instalar, lo bajas, y lo abres, siguiendo todas las instrucciones del instalador, no seria mucho mas.

[Descargar el IDE Arduino](https://www.arduino.cc/en/software)

Continuando con la instalacion de la libreria, debes dirigirte al apartado "Programa" en el menu superior y seleccionar "incluir libreria" y luego darle click a "Añadir biblioteca .ZIP", see te va a desplegar un buscador de archivos, deberas ubicar la libreria y seleccionarla, eso seria todo, ya tienes tu libreria instalada.

![libreria](https://user-images.githubusercontent.com/79547422/206586250-6a74be28-a28d-4b18-bc78-724f57af0c7b.JPG)
![lbreria2](https://user-images.githubusercontent.com/79547422/206586258-bab70188-d279-40f7-9561-eb14637e9967.JPG)
![libreria 3](https://user-images.githubusercontent.com/79547422/206586262-afd6d818-10d5-44ac-901a-1a7e0e9b10df.JPG)

Ahora debes utilizar el codigo [sistema-llenado-envases-ultrasonido-lcd-servo.ino](https://github.com/FryFr/sistema-llenado-envases-ultrasonido-lcd-servo.ino/blob/main/sistema-llenado-envases-ultrasonido-lcd-servo.ino) en una sketch en blanco, compilar y subir y tendras tu sensor funcionando!

Tambien puedes descargar este documento y el codigo directamente dirigiendote a la pestaña "Code" y luego darle click a "Download ZIP" con eso obtendras el repositorio completo.
![code](https://user-images.githubusercontent.com/79547422/210285341-1c76189c-eaf5-4aa4-8765-5d9569d0aeb1.JPG)
![down](https://user-images.githubusercontent.com/79547422/210285343-a9353c1c-b8d3-4f4b-a3b4-a2eca5cf7a6a.JPG)
