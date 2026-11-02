/*
 * File:   main00.c
 * Author: Roger Salazar
 *
 * Created on 29 de octubre de 2026, 12:45 AM
 */
/*
#include <xc.h>
#include "cabecera.h"
#include "LCD.h"
#define _XTAL_FREQ 4000000UL

void main(void) {
    return;
}
*/

/*
 * File:   maincode00.c
 * Author: Alumnos
 *
 * Created on October 28, 2026, 10:13 AM
 */
/*

#include <xc.h>
#include "cabecera.h"
#include "LCD.h"
#define _XTAL_FREQ 4000000UL


unsigned char i_acento[]={0x02,0x04,0x00,0x0C,0x04,0x04,0x0E,0x00};
unsigned char o_acento[]={0x02,0x04,0x00,0x0E,0x11,0x11,0x0E,0x00};

void configuro(void){
    //conf mod osc
    OSCCON1 = 0x60;
    OSCFRQ = 0x02;
    OSCEN = 0x40;
    
    //conf E/S
    
    ANSELB = 0xFC;  //RB1 y RB0 digitales
    WPUB = 0x03;    //RB1 y RB0 weak pullup enabled
    //inicializar el LCD
    LCD_INIT();
    
    
    GENERACARACTER(i_acento,0); // al acento se le asigna la posisicon cero
    GENERACARACTER(o_acento,1);
    // conf ADC
    FVRCON=0x81;
    ADCON0=0x94;
    ADREF=0x03;
    ADPCH=0X00;
}

void Generador_ADC(){

}

void main(void) {
    configuro();
    while(1){
        POS_CURSOR(1,0);
        ESCRIBE_MENSAJE2("TERM");
        ENVIA_CHAR(1);
        ESCRIBE_MENSAJE2("METRO");
        POS_CURSOR(2,0);
        ESCRIBE_MENSAJE("sN.LM35: ");
        ADCON0bits.GO_nDONE=1;
        while(ADCON0bits.GO_nDONE==1);
        unsigned int resultado=((ADRESH << 8)+ ADRESL)/10;
        LCD_ESCRIBE_VAR_INT(resultado, 2);
        ENVIA_CHAR(0xDF);
        ENVIA_CHAR('C');
        
        __delay_ms(2000);
    }
}
*/


/*
#include <xc.h>
#include "cabecera.h"
#include "LCD.h"
#define _XTAL_FREQ 4000000UL


unsigned char i_tilde[]={0x02,0x04,0x00,0x0C,0x04,0x04,0x0E,0x00};
unsigned char o_tilde[]={0x02, 0x04, 0x00, 0x0E, 0x11, 0x11, 0x0E, 0x00};
unsigned char carita_1[]= {0x00, 0x11, 0x1F, 0X15, 0X1F, 0X11, 0X1F};

void configuracion(void){
    // Configuración del modulo de oscilador
    OSCCON1 = 0x60;
    OSCFRQ  = 0x02;
    OSCEN   = 0x40;
    // Configuración de entradas y salidas
    ANSELB  = 0xFC; // RB0 y RB1 digitales
    WPUB    = 0x03; // RB0 y RB1 pullup enabled
    //inicializar el lcd
    LCD_INIT();
    GENERACARACTER(o_tilde,0);
    GENERACARACTER(i_tilde,1);
    GENERACARACTER(carita_1,2);
    //conf adc
    FVRCON = 0X51 ;
    ADCON0 = 0X94 ;
    ADREF = 0X03 ;
    ADPCH = 0X00 ;
          
}

void main(void){
    configuracion();

    while (1) {
        POS_CURSOR(1,0);
        ESCRIBE_MENSAJE2("term");
        ENVIA_CHAR(0);
        ESCRIBE_MENSAJE2("metro UPC");
        POS_CURSOR(2,0);
        ESCRIBE_MENSAJE2("lm-35 : ");
        ///////////
        ADCON0bits.GO_nDONE =1 ;
        while(ADCON0bits.GO_nDONE == 1);
        unsigned int resultado = ((ADRESH << 8)+ ADRESL)/10;
        LCD_ESCRIBE_VAR_INT(resultado, 2);
        /////////////
        ENVIA_CHAR(0XDF);
        ENVIA_CHAR('C');
        
        
        if (resultado>=30){
            LATBbits.LATB2=1;
        }
        if(PORTBbits.RB0==1){
        
        }
        __delay_ms(2000);
        
    }
}

 */

/*
#include <xc.h>
#include "cabecera.h"
#include "LCD.h"
#define _XTAL_FREQ 4000000UL

unsigned char admiracion[]={0x04,0x00,0x00,0x04,0x04,0x04,0x04,0x00};
unsigned char i_acento[]={0x02,0x04,0x00,0x0C,0x04,0x04,0x0E,0x00};
unsigned char e_acento[]={0x02,0x04,0x0E,0x11,0x1F,0x10,0x0E,0x00};
unsigned char o_acento[] = {0x02, 0x04, 0x00, 0x0E, 0x11, 0x11, 0x0E, 0x00};


void configuracion(void) {
    // Conf modulo de oscilador
    OSCCON1 = 0x60;
    OSCFRQ  = 0x02;
    OSCEN   = 0x40;
    // Conf las E/S
    ANSELB  = 0xFC; // RB0 y RB1 digitales
    WPUB    = 0x03; // RB0 y RB1 pullup
    
    TRISBbits.TRISB0 = 1; 
    //inicializando del lcd
    LCD_INIT();
    GENERACARACTER(admiracion,0);
    GENERACARACTER(i_acento,1);
    GENERACARACTER(e_acento,2);
    GENERACARACTER(o_acento,3);
    
    //CON ADC
    FVRCON = 0x81;
    ADCON0 = 0x94;
    ADREF = 0x03;
    ADPCH = 0x00;
}


void main(void) {
    configuracion();   
    while (1) {
        
        ADCON0bits.GO_nDONE = 1;
        while(ADCON0bits.GO_nDONE == 1);
        unsigned int resultado = ((ADRESH << 8)+ ADRESL)/10;
        if(resultado > 15){
            LATCbits.LATC0=1;
        }
        else{
            LATCbits.LATC0=0;
        }
        if(PORTBbits.RB0==0){
            BORRAR_LCD();
            POS_CURSOR(1, 0);
            ESCRIBE_MENSAJE2("DAIRON LOPEZ");
            POS_CURSOR(2, 0);
            ESCRIBE_MENSAJE2("TORRES");
            __delay_ms(1000);
        }
        else{
            POS_CURSOR(1, 0);
            ESCRIBE_MENSAJE2("Term");
            ENVIA_CHAR(3);
            ESCRIBE_MENSAJE2("metro UPC");
            POS_CURSOR(2,0);
            ESCRIBE_MENSAJE2("Sn. LM35: ");
            ADCON0bits.GO_nDONE = 1;
            while(ADCON0bits.GO_nDONE == 1);
            unsigned int resultado = ((ADRESH << 8)+ ADRESL)/10;
            LCD_ESCRIBE_VAR_INT(resultado,2);
            ENVIA_CHAR(0xDF);
            ENVIA_CHAR('C');
            
 

            
            __delay_ms(200);
        }
    }
} */


#include <xc.h>
#include "cabecera.h"
#include "LCD.h"
#define _XTAL_FREQ 4000000UL

unsigned char admiracion[]={0x04,0x00,0x00,0x04,0x04,0x04,0x04,0x00};
unsigned char i_acento[]={0x02,0x04,0x00,0x0C,0x04,0x04,0x0E,0x00};
unsigned char e_acento[]={0x02,0x04,0x0E,0x11,0x1F,0x10,0x0E,0x00};
unsigned char o_acento[] = {0x02, 0x04, 0x00, 0x0E, 0x11, 0x11, 0x0E, 0x00};

void configuracion(void) {
    // Conf modulo de oscilador
    OSCCON1 = 0x60;
    OSCFRQ  = 0x02;
    OSCEN   = 0x40;
    
    // Conf las E/S
    ANSELB  = 0xFC; // RB0 y RB1 digitales
    ANSELC  = 0xFE; // RC0 digital (para el buzzer/salida), RC1..7 según uso
    WPUC    = 0x01;
    WPUB    = 0x03; // RB0 y RB1 pullup activados correctamente
    
    TRISBbits.TRISB0 = 1; // RB0 como entrada (Botón)
    TRISCbits.TRISC0 = 0; // RC0 como salida (Buzzer)
    
    // Inicializando el LCD
    LCD_INIT();
    GENERACARACTER(admiracion,0);
    GENERACARACTER(i_acento,1);
    GENERACARACTER(e_acento,2);
    GENERACARACTER(o_acento,3);
     
    // CONFIGURACIÓN ADC
    FVRCON = 0x81;
    ADCON0 = 0x94;
    ADREF  = 0x03;
    ADPCH  = 0x00;
}

void main(void) {
    unsigned int resultado; // Declarada una sola vez
    configuracion();   
    
    while (1) {
        // 1. Lectura del ADC única por ciclo
        ADCON0bits.GO_nDONE = 1;
        while(ADCON0bits.GO_nDONE == 1);
        resultado = ((ADRESH << 8) + ADRESL) / 10;
        
        // 2. Control del Buzzer (Se ejecuta siempre, sin importar el botón)
        if(resultado > 10){
            LATCbits.LATC0 = 1; // Suena el buzzer
        } else {
            LATCbits.LATC0 = 0; // Apaga el buzzer
        }
        
        // 3. Lógica de la Pantalla LCD según el Botón en RB0 (Pull-up activo)
        if(PORTBbits.RB0 == 0){ // Botón presionado (nivel bajo por pull-up)
            BORRAR_LCD();
            POS_CURSOR(1, 0);
            ESCRIBE_MENSAJE2("ROGER");
            POS_CURSOR(2, 0);
            ESCRIBE_MENSAJE2("SALAZAR HUAMANI");
            __delay_ms(1000);
        }
        else { // Botón no presionado
            POS_CURSOR(1, 0);
            ESCRIBE_MENSAJE2("Term");
            ENVIA_CHAR(3);
            ESCRIBE_MENSAJE2("metro UPC");
            POS_CURSOR(2,0);
            ESCRIBE_MENSAJE2("Sn. LM35: ");
            
            // Muestra el resultado ya calculado previamente
            LCD_ESCRIBE_VAR_INT(resultado, 2);
            ENVIA_CHAR(0xDF);
            ENVIA_CHAR('C');
            __delay_ms(200);
        }
    }
}