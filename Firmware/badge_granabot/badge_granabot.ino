/************************************************************************************
 *    Programa test del badge de GranaBot                                           *
 *   -------------------------------------                                          *
 *                                                                                  *
 *    GranaBot 2018                                                                 *
 *                                                                                  *
 *    Paco López, Dpto. de Electrónica del I.E.S. Virgen de las Nieves, Granada.    *
 *                                                                                  *
 ************************************************************************************/

//El ATtiny85 deberá ser programado para que funcione a 8MHz o a 16MHz usando el reloj interno.

#include <Adafruit_NeoPixel.h>  //Para el control de los LEDs RGB.
#include <CapacitiveSensor.h>   //Para la lectura del sensor capacitivo incluido en la PCB del badge.

#define umbral 300        //Umbral para determinar si se está tocando el sensor. A mayor valor menor sensibilidad..
#define pin_leds PB4      //Los LEDs se controlan con el pin PB4 del ATtiny.
#define brillo 50         //Controla el brillo máximo de los LEDs.
#define antirrebotes 200  //Tiempo establecido entre lecturas sucesivas del sensor capacitivo, en ms.
#define retardo_ruleta 40 //Tiempo de reatrdo usado para controlar la velocidad de la "ruleta" de LEDs, en ms.

//Instanciación de los objetos usados en el sketch.
Adafruit_NeoPixel tira_leds = Adafruit_NeoPixel(8, pin_leds, NEO_GRB + NEO_KHZ800); //El badge tiene 8 LEDs RGB.
CapacitiveSensor cs_0_1 = CapacitiveSensor(PB0,PB1); //La resistencia de 1M está entre los pines PB0 y PB1. El pin PB1 es el que tiene conectado el sensor.

byte contador_de_toques=0;    //Para llevar la cuenta de las veces que se toca el sensor. Un máximo de 5 toques, tras los cuales la variable vuelve a valer 0.
                              //El valor de esta variable, el contador de toques, es el que determina el comportamiento del badge en cada instante.

void setup()                    
{
   tira_leds.setBrightness(brillo);     //Ajuste del brillo máximo.
   tira_leds.begin();                   //Inicialización del objeto "tira_leds".
   tira_leds.show();                    //Inicialmente todos los LEDs apagados (por defecto se tiene tira_leds.Color(0,0,0)).
}

void loop()                    
{
  //Lectura del sensor y control del contador de toques.
  long total_PB1 =  cs_0_1.capacitiveSensor(30);  //Lectura del sensor capacitivo. El valor leído se almacena en total_PB1.

  if (total_PB1 > umbral) //Si se ha tocado el sensor...
  {
    contador_de_toques++; //... se incrementa el contador de toques y ...
    if (contador_de_toques > 4) contador_de_toques = 0; //... se comprueba que su valor no exceda el máximo. Si es así se reinicia su valor a 0.
  }

  //Determinación del comportamiento del badge.
  switch (contador_de_toques)
    {
      case 0: //Todos los LEDs apagados.
              for(int cont=0; cont<9; cont++)
              {
                tira_leds.setPixelColor(cont, tira_leds.Color(0,0,0));  //Se configuran todos los LEDs para que se apaguen...
              }
              tira_leds.show();                                         //... y se manda esta configuración al badge (actualización del estado de los LEDs).
              delay(antirrebotes);                                      //Para evitar nuevas lecturas del sensor antes de que dé tiempo de retirar el dedo.
              break;
              
      case 1: //Todos los LEDs a rojo.
              for(int cont=0; cont<9; cont++)
              {
                tira_leds.setPixelColor(cont, tira_leds.Color(255,0,0));
              }
              tira_leds.show();
              delay(antirrebotes);
              break;
              
      case 2: //Todos los LEDs a verde.
              for(int cont=0; cont<9; cont++)
              {
                tira_leds.setPixelColor(cont, tira_leds.Color(0,255,0));
              }
              tira_leds.show();
              delay(antirrebotes);
              break;
              
      case 3: //Todos los LEDs a azul
              for(int cont=0; cont<9; cont++)
              {
                tira_leds.setPixelColor(cont, tira_leds.Color(0,0,255));
              }
              tira_leds.show();
              delay(antirrebotes);
              break;
              
      case 4: //FX (efectos especiales) de LEDs bailoteando.
              delay(antirrebotes);    //Para evitar nuevas lecturas del sensor antes de que dé tiempo de retirar el dedo.
              bailoteo_leds();        //Llamada a la función de bailoteo de los LEDs.
              break;
    }
}




//-------------------------------------------------------------//
//                DEFINICIÓN DE FUNCIONES PROPIAS              //
//-------------------------------------------------------------//

//Función que realiza un FX.
//Esta función está diseñada en principio para llamar a la función vuelta_ruleta(), pero es
//fácilmente modificable para usar otras funciones de efectos diferentes (a diseñar por el futuro
//programador del badge).
void bailoteo_leds (void)
{
  while(1)  //La ruleta de LEDs se ejecutará de forma indefinida...
  {
    if( vuelta_ruleta(255,0,0) )     return;  //... hasta que alguna de las llamadas a la función vuelta_ruleta() devuelva el valor true.
    if( vuelta_ruleta(255,255,0) )   return;
    if( vuelta_ruleta(0,255,0) )     return;
    if( vuelta_ruleta(0,255,255) )   return;
    if( vuelta_ruleta(0,0,255) )     return;
    if( vuelta_ruleta(255,0,255) )   return;
    if( vuelta_ruleta(255,255,255) ) return;
  }
}

//Cada llamada a esta función realiza una vuelta completa de la ruleta de LEDs. En concreto, se realiza un
//encendido sucesivo de los LEDs del badge, simulando el efecto de una ruleta de LEDs con colores cambiantes.
//La función requiere como parámetros el color, en formato RGB, con el que deben ir encendiéndose los LEDs.
//La función retorna un valor lógico dependiendo de que durante su ejecución se active o no el sensor capacitivo:
//      true  -> se ha producido la activación del sensor durante la ejecución de la función.
//      false -> no se ha producido la activación del sensor.
boolean vuelta_ruleta (byte r, byte g, byte b)
{
  for(int cont=0; cont<9; cont++)   //Para ir encendiendo progresivamente cada uno de los 8 LEDs del badge.
      {
        tira_leds.setPixelColor(cont, tira_leds.Color(r,g,b));  //Se configura el LED indicado por cont con el color dado como parámetro de la función.
        tira_leds.show();                                       //Se actualiza el estado del LED.
        if (cs_0_1.capacitiveSensor(30) > umbral)               //Cada vez que se procede a actualizar un LED se realiza la lectura del sensor...
        {                                                       //... y si se ha activado entonces...
          contador_de_toques = 0;                               //... se restituye el contador de toques a su valor inicial, ...
          delay(antirrebotes);                                  //... se espera el tiempo antirrebote para dejar tiempo de retirar el dedo del sensor y ...
          return true;                                          //... se retorna devolviendo el valor true.
        }
        delay(retardo_ruleta);                                  //En caso de no haberse activado el sensor se introduce un retardo para que el encendido ...
      }                                                         //... de los LEDs de la ruleta no sea demasiado rápido, ya que entonces se perdería el efecto buscado ...
      return false;                                             //... y se retorna devolviendo el valor false.
}

