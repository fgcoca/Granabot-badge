# **Documentación del badge Granabot** 
Se trata de una PCB diseñada en base al logo de Granabot como un kit de soldadura SMD y se basa en un micro controlador ATTiny85 y unos cuantos LEDs con control inteligente tipo WS2812B.

![GrB][1]

 [1]: https://github.com/fgcoca/Granabot-badge/blob/master/Images/Top-Botton.png

# **Contenidos del repositorio**
1. Diseños originales de Gustavo Reynaga de la PCB realizados con [KICad](http://kicad-pcb.org/)

    * [Granabot badge original](https://github.com/fgcoca/Granabot-badge/tree/master/Granabot-Badge-Original)
    * [Imágenes para el diseño](https://github.com/fgcoca/Granabot-badge/tree/master/Granabot-Badge-Original/Design/images)
    * [Diseño para el patrocinio de PCBWay](https://github.com/fgcoca/Granabot-badge/tree/master/Granabot-Badge-Original/Hardware/PCBWay)
    * [Diseño para patrocinio de OSH Park](https://github.com/fgcoca/Granabot-badge/tree/master/Granabot-Badge-Original/Hardware/OSHPark)
2. Debido a dos pequeños errores de encapsulado en el diseño original de Gustavo se hace necesaria la revisión de este para dotar al Attiny85 y al diodo MBRA140 de footprint correctos. La citada revisión y adaptación la Realiza francisco López.

    * [Granabot badge revisado](https://github.com/fgcoca/Granabot-badge/tree/master/Granabot-Badge-revisado)
    * [Diseño para el patrocinio de PCBWay](https://github.com/fgcoca/Granabot-badge/tree/master/Granabot-Badge-revisado/Hardware/PCBWay)
    * [Diseño para patrocinio de OSH Park](https://github.com/fgcoca/Granabot-badge/tree/master/Granabot-Badge-revisado/Hardware/OSHPark)
   
3. Firmware de prueba cargado en los badges que se entregan que sirve para probar el funcionamiento simplemente con alimentarlo. Se trata de un archivo .ino listo para cargarr en el ATTiny85 via ICSP. En el [manual de uso](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Programacion/Manual.pdf) se explican todos los detalles para trabajar con el badge.
    * [Firmware](https://github.com/fgcoca/Granabot-badge/tree/master/Firmware/badge_granabot)

4. El Kit. Al badge Granabot se le da formato de kit para su entrega estando este formado por la PCB, los componentes necesarios para montarlo, un manual de montaje impreso y una fe de erratas. Todo ello introducido en una cajita adornada con [pegatinas](https://github.com/fgcoca/Granabot-badge/tree/master/Pegatinas-Caja) de Granabot y de los patrocinadores. En las imágenes se ve el aspecto final del kit listo para su entrega de una caja individual y de un conjunto de cajas preparadas para su entrega el día de la celebración del evento [Granabot](https://sites.google.com/site/granabot18/)

![Vista desde la derecha][10] ![Conjunto visto desde la izquierda][11]

 [10]: https://github.com/fgcoca/Granabot-badge/blob/master/Images/VDcha.jpg
 [11]: https://github.com/fgcoca/Granabot-badge/blob/master/Images/VIzdaConj.jpg

En la imagen vemos a Juan Robles de [Createc](https://createc3d.com/) (uno de nuestros patrocinadores) con el badge recien entregado.

![Juan Robles][12]

 [12]: https://github.com/fgcoca/Granabot-badge/blob/master/Images/Juan.jpg

5. Información del kit Granabot

    * [Listas de materiales](https://github.com/fgcoca/Granabot-badge/tree/master/Kit/BOM)
      * [Formato .odt](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/BOM/BOM-con-links-compras.ods)
      * [Formato .pdf](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/BOM/BOM-con-links-compras.pdf)
      * [Formato .png](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/BOM/BOM.png)      
    * [Erratas en la primera edición del kit](https://github.com/fgcoca/Granabot-badge/tree/master/Kit/Erratas)
      * [Formato .odt](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Erratas/Erratas.odt)
      * [Formato .pdf](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Erratas/Erratas.pdf)      
    * [Manuales de montaje](https://github.com/fgcoca/Granabot-badge/tree/master/Kit/Montaje)
      * [Formato comprimido .7z](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Montaje/Manual-montaje.7z)
      * [Formato .pdf](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Montaje/Manual-montaje.pdf)
      * [Formato .png](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Montaje/Manual-montaje.png)      
    * [Manuales de configuraciones y uso de librerias para programar el kit](https://github.com/fgcoca/Granabot-badge/tree/master/Kit/Programacion)
      * [Formato .odt](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Programacion/Manual.odt)
      * [Formato .pdf](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Programacion/Manual.pdf)
      * [Video de funcionamiento](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Programacion/video/Test-badge-Granabot.mp4)       
    * [Programando físicamente el kit](https://github.com/fgcoca/Granabot-badge/tree/master/Kit/Programando)
      * [Formato .odt](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Programando/Programando.odt)
      * [Formato .pdf](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Programando/Programando.pdf)        
    * [Pinza de sujeción diseñada en 3D](https://github.com/fgcoca/Granabot-badge/tree/master/Kit/Programando/Design)
      * [Diseño en FreeCAD](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Programando/Design/Pinzas-Centrador.FCStd)
      * [Archivo stl de la pinza](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Programando/Design/Pinza.stl)  
      * [Archivo stl de la pieza usada para posicionar el chip](https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Programando/Design/Centrador.stl)

![Guía de posicionado][20] ![Pinza de sujeción con el muelle montado][21]

 [20]: https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Programando/Images/03Guia-posicionadoM.jpg
 [21]: https://github.com/fgcoca/Granabot-badge/blob/master/Kit/Programando/Images/10Pinza-sujecionM.jpg

# **Enlaces**

[Web de Granabot 2018](https://sites.google.com/site/granabot18/)

 
# **Autores**
Gustavo Reynaga https://github.com/hulkco @gsreynaga 

Jorge Pérez https://github.com/akirasan @akirasan

José Antonio Vacas https://github.com/javacasm @javacasm

Federico Coca Caba https://github.com/fgcoca @fgcoca

Francisco López Castro @flopcas 

# **Licencia**
![License][88]

 [88]: https://github.com/fgcoca/3D-Design_Robots_Other/blob/master/Lapicero/Licencia/licencia.png
[Enlace al texto de la licencia](https://github.com/fgcoca/Granabot-badge/blob/master/LICENSE)
