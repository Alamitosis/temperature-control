#include <18f45k50.h>
#device PASS_STRINGS =IN_RAM
#device adc = 10 
#use delay(internal=48MHz)
#build(reset=0x02000,interrupt=0x02008)     
#org 0x0000, 0x1FFF { }

#use I2C(MASTER, I2C1, FAST = 500000, stream = SSD1306_STREAM)
#include "SSD1306OLED.c"
#include <Imagenes.h>

//Definición y asignación de pines
#define BOTSEL      PIN_D5
#define BOTINC      PIN_D6
#define BOTDEC      PIN_D4
#define BOTCONF     PIN_D7

#define RESIST_CAL  PIN_A3
#define VENTI       PIN_A5

//Declaración de variables
unsigned long Adc0;
char text[16];            	//Variable caracter para desplegar en OLED los valores numéricos
unsigned int selec=1;
signed int hist=0;
int TH=60,TL=40, FLAG=0;   	//Coeficientes y bandera de estado anterior para BOTSEL
int Temp=0;					//Variable para temperatura medida
float Volts;

void main(void) {   
	delay_ms(500);             //Tiempo de espera OLED
	output_float(BOTSEL);      //Declaración de los botones de entrada
	output_float(BOTINC);      //ubicados en RD4, RD5, RD6 y RD7.
	output_float(BOTDEC);
	output_float(BOTCONF);
	
	output_drive(RESIST_CAL);	//Declaración de los pines de salida
	output_drive(VENTI);

	output_low(RESIST_CAL);		//Apagar salidas (seguridad)
	output_low(VENTI);

	// Initialize the SSD1306 OLED with an I2C addr = 0x7A (default address)
	SSD1306_Begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
	SSD1306_ClearDisplay();     //Limpia la pantalla OLED
	SSD1306_Display();         	//Despliega en la pantalla los cambios realizados en ella
	                     		//hasta este punto

	//Portada
	SSD1306_ROMBMP(0,0, &Portada_Oled, 128, 64);
	SSD1306_DrawText(15,3,"INST TEC LAZARO C",1);
	SSD1306_DrawText(48,17,"AP. MICROS",1);
	SSD1306_DrawText(50,27,"PROYECTO U2:",1);
	SSD1306_DrawText(30,35,"CONTROL TEMPER",1);
	SSD1306_DrawText(35,47,"DAYANA GOMEZ B",1);
	SSD1306_DrawText(55,56,"19560091",1);
	SSD1306_Display();         
	delay_ms(3000);               
	SSD1306_ClearDisplay();
   
	SSD1306_DrawText(10,0,"CONTROL TEMPERATURA",1); //Encabezado del programa
	SSD1306_DrawLine(0,8,127,8,TRUE);          		// Líneas de separación   
	SSD1306_DrawLine(0,10,127,10,TRUE);
	SSD1306_DrawText(20,20,"Temp. actual=",1);
	SSD1306_DrawText(52,42,"TH=",1);            	//Temperatura alta
	SSD1306_DrawText(52,55,"TL=",1);  				//Temperatura baja 
   
	//Conf. A/D
	setup_adc_ports(sAN0);                  		//Selec. pin analógico
	setup_adc(ADC_CLOCK_DIV_8 | ADC_TAD_MUL_8);   	//Conf. vel. reloj A/D
	set_adc_channel(0);                     		//Canal a utilizar
	delay_us(10);

	for(;;){										//Ciclo infinito
		Adc0=read_adc(ADC_START_AND_READ);   		//Lectura valor digital del conv.
		Volts=Adc0*0.0048876;           			//Valor digital*resolución (0 -> 0, 1023 -> 5V)
		Temp=Volts*100;                				//Volts/(10 mV)       
		delay_us(10);
		
		//Menú principal
		SSD1306_FillRect(0,12,128,28,FALSE);
		SSD1306_DrawText(20,20,"Temp. actual=",1);
		sprintf(text,"%d",Temp);					//Temp. detectada por LM35
		SSD1306_DrawText(103,20,text,1); 
		SSD1306_DrawCircle(115, 18, 1);
		SSD1306_DrawText(117,20,"C",1);

		if (selec==1 && FLAG){           			//Selección de TH para modificar
			output_low(RESIST_CAL);
			output_low(VENTI);
			SSD1306_FillRect(0,12,128,28,FALSE);
			SSD1306_DrawText(30,20,"CONFIGURACION",1);
			SSD1306_DrawText(38,42,"->",TRUE);
			SSD1306_FillRect(38,55,11,7,FALSE);
			SSD1306_Display();
			delay_ms(2);

			if(!input(BOTINC) && TH<100){
				TH++;                  				//Incrementar TH en una unidad
				delay_ms(10);
				//while(!input(BOTINC));
			}
			
			else if(!input(BOTDEC) && TH>60){
				TH--;                  				//Decrementar TH en una unidad
				delay_ms(10);
				//while(!input(BOTDEC));
			}
		}
   
		else if (selec==2 && FLAG){         		//Selección de TL para modificar
			output_low(RESIST_CAL);
			output_low(VENTI);
			SSD1306_FillRect(0,12,128,28,FALSE);
			SSD1306_DrawText(30,20,"CONFIGURACION",1);
			SSD1306_DrawText(38,55,"->",TRUE);
			SSD1306_FillRect(38,42,11,7,FALSE);
			SSD1306_Display();
			delay_ms(2);

			if(!input(BOTINC) && TL<90){			//Incrementar TL en una unidad
				TL++;                  				
				delay_ms(10);
				//while(!input(BOTINC));
			}
			
			else if(!input(BOTDEC) && TL>40){
				TL--;								//Decrementar TL en una unidad
				delay_ms(10);            
				//while(!input(BOTDEC));
			}
		}

		if(!input(BOTSEL) && FLAG){      			//Si botón de selección es presionado...
			selec++;								//Incrementar "selec" en una unidad
			if(selec>2){							//Si selec es mayor a 2, devolver al valor 1.
				selec=1;            				
				delay_ms(2);
			}   
			while(!input(BOTSEL));
		}


		if(!input(BOTCONF) && FLAG==0){			
			FLAG=1;									//Cuando FLAG=1, el botón ya fue presionado una vez
			delay_ms(30);
		}

		else if(!input(BOTCONF) && FLAG){
			hist=TH-TL;
			if(hist>=10){							//Si la diferencia entre TH y TL es mayor a 10 (histérsis)
				FLAG=0;								//Cuando FLAG=0, el botón ya fue presionado de nuevo
				selec=1;
				SSD1306_FillRect(38,42,11,30,FALSE);
				delay_ms(5);
				if(Temp<TL){						//Cuando la temp. sea menor a TL
					output_high(RESIST_CAL);		//Encender resist. calefactora
					output_low(VENTI);				//Apagar ventilador
				}
				else if(Temp>TH){					//Cuando la temp. sea maoyr a TH
					output_high(VENTI);				//Encender ventilador
					output_low(RESIST_CAL);			//Apagar resist. calefactora
				}
			}
			
			else if(hist<10){						//Si la histéresis es menor a 10
				SSD1306_FillRect(0,12,128,28,FALSE);//Solicitar al usuario nuevos valores
				SSD1306_DrawText(15,20,"TH-TL>=10 NO CUMPLE",1);
				SSD1306_DrawText(3,30,"INGRESE OTROS VALORES",1);
				SSD1306_Display();
				delay_ms(3000);
				SSD1306_FillRect(0,12,128,28,FALSE);
				SSD1306_DrawText(30,20,"CONFIGURACION",1);
				SSD1306_Display();
			}
			while(!input(BOTCONF));
		}

		SSD1306_FillRect(73,42,20,7,FALSE);			//Limpiar sección de TH en OLED
		SSD1306_FillRect(73,55,20,7,FALSE);			//Limpiar sección de TL en OLED
		sprintf(text,"%d",TH);                  	
		SSD1306_DrawText(73,42,text,1);            	//Desplegar valor TH actual
		sprintf(text,"%d",TL);	
		SSD1306_DrawText(73,55,text,1);				//Desplegar valor TL actual
		SSD1306_Display();
		delay_ms(10);

		hist=TH-TL;
		if(hist>=10 && FLAG==0){					//Si histérsis=10 y NO se está en modo conf...
			if(Temp<TL){
				output_high(RESIST_CAL);			//Encender resist. calef. si la temp. es menor a TL
				output_low(VENTI);
			}
			else if(Temp>TH){
				output_high(VENTI);					//Encender ventilador si la temp. es mayor a TH
				output_low(RESIST_CAL);
			}
		}
      
   }
}