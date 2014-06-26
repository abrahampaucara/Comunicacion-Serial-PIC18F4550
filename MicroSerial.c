#include <18F4550.h>
#device adc=8
#include <stdio.h>
#include <string.h>


#fuses INTRC_IO
#use delay(INTERNAL=8MHZ) //si habilito afecta al clock=20M
//#use delay(clock=4M)
//#use rs232(baud=9600,bits=8,parity=N,XMIT=PIN_B1,RCV=PIN_B0,Stream=COM_A)
#use rs232(baud=9600,bits=8,parity=N,STOP=1,XMIT=PIN_C6,RCV=PIN_C7,Stream=COM_B)
#define led1     PIN_D1
#define led2     PIN_D2
#define led3     PIN_D3
#define led4     PIN_D4
#define led5     PIN_D5
#define led6     PIN_D6
#define pin_on   output_high
#define pin_off  output_low

int8 q;
//float voltsan0;
int a;
char x;
int sen1();
int sen1()
{
float voltsan0;
q=read_adc();
voltsan0 = q* 0.061;
a=voltsan0;
return (q);
}

#int_rda
void rd_isr(void)//función de interrupción por recepción de datos USART
{
 x=getc(COM_B);
 //putc(x,COM_B);
}

void main() {
//set_tris_b(0x0);
set_tris_b(0b00000000);
set_tris_d(0b00000000);
//set_tris_c(0b10000000);

enable_interrupts(global);//Habilito interrupción USART
enable_interrupts(int_rda);

setup_adc_ports(AN0|VSS_VDD);
//setup_adc(ADC_CLOCK_INTERNAL);
setup_adc(ADC_CLOCK_DIV_32);
////////////////////////////////////////////////
////////////////////////////////////////////////
salir:

   pin_off(led1);                            //Apagar LEDs
   pin_off(led2);
   pin_off(led3);
   pin_off(led4);
   pin_off(led5);
   pin_off(led6);

while(1){
           
      set_adc_channel(0);
      delay_us(20);      
      output_b (sen1()); 
      putc(sen1(),COM_B);
      switch(x) 
               { 
               case 'a': 
                        output_high(led1);
                        
                       break; 
               case 'b': 
                       output_toggle(led2);
                       
                       break; 
               case 'c': 
                       output_toggle(led3);
                       
                       break; 
               case 'd': 
                       output_toggle(led4);
                       
                       break; 
               case 'e': 
                       output_toggle(led5);
                       
                       break; 
               case 'f': 
                       output_toggle(led6);
                       
                       break; 
               case 'g': 
                       output_high(led1); 
                       delay_ms(2000); 
                       output_low(led1);
                       if(x=='j') goto salir;
                       output_high(led2); 
                       delay_ms(2000); 
                       output_low(led2);
                       if(x=='j') goto salir;
                       output_high(led3); 
                       delay_ms(2000); 
                       output_low(led3);
                       if(x=='j') goto salir;
                       output_high(led4); 
                       delay_ms(2000); 
                       output_low(led4);
                       if(x=='j') goto salir;
                       output_high(led5); 
                       delay_ms(2000); 
                       output_low(led5);
                       if(x=='j') goto salir;
                       output_high(led6); 
                       delay_ms(2000); 
                       output_low(led6);
                       if(x=='j') goto salir;
                       break; 
                     
                 case 'h':                         
                        output_low(led1); 
                        output_low(led2);
                        output_low(led3);
                        output_low(led4);
                        output_low(led5);
                        output_low(led6);                                                
                        break;  
               } 
   
      }
}

