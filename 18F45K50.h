//////////// Standard Header file for the PIC18F45K50 device ////////////////
///////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996, 2013 Custom Computer Services          ////
//// This source code may only be used by licensed users of the CCS C  ////
//// compiler.  This source code may only be distributed to other      ////
//// licensed users of the CCS C compiler.  No other use, reproduction ////
//// or distribution is permitted without written permission.          ////
//// Derivative programs created using this software in object code    ////
//// form are not restricted in any way.                               ////
///////////////////////////////////////////////////////////////////////////
#device PIC18F45K50

#nolist
//////// Program memory: 16384x16  Data RAM: 2048  Stack: 31
//////// I/O: 33   Analog Pins: 25
//////// Data EEPROM: 256
//////// C Scratch area: 00   ID Location: 200000
//////// Fuses: PLL4X,PLL3X,NOPLLEN,PLLEN,NOCPUDIV,CPUDIV2,CPUDIV3,CPUDIV6
//////// Fuses: LS24MHZ,LS48MHZ,LP,XT,HSH,HSM,ECH,ECH_IO,RC,RC_IO,INTRC_IO
//////// Fuses: INTRC,ECM,ECM_IO,ECL,ECL_IO,PRIMARY_SW,PRIMARY,NOFCMEN,FCMEN
//////// Fuses: NOIESO,IESO,PUT,NOPUT,NOBROWNOUT,BROWNOUT_SW,BROWNOUT_NOSL
//////// Fuses: BROWNOUT,BORV28,BORV25,BORV22,BORV19,LPBOR,NOLPBOR,NOWDT
//////// Fuses: WDT_NOSL,WDT_SW,WDT,WDT1,WDT2,WDT4,WDT8,WDT16,WDT32,WDT64
//////// Fuses: WDT128,WDT256,WDT512,WDT1024,WDT2048,WDT4096,WDT8192
//////// Fuses: WDT16384,WDT32768,CCP2B3,CCP2C1,NOPBADEN,PBADEN,T3CKB5
//////// Fuses: T3CKC0,SDOC7,SDOB3,MCLR,NOMCLR,NOSTVREN,STVREN,NOLVP,LVP
//////// Fuses: ICSP1,ICSP2,NOXINST,XINST,DEBUG,NODEBUG,PROTECT,NOPROTECT
//////// Fuses: CPB,NOCPB,CPD,NOCPD,WRT,NOWRT,WRTC,NOWRTC,WRTB,NOWRTB,WRTD
//////// Fuses: NOWRTD,EBTR,NOEBTR,EBTRB,NOEBTRB
//////// 
#if (!defined(__PCH__)||defined(__ISNT_CCS__))
#define _bif
#define int8 char
#define int16 long
#define int32 long long
#define float32 float
#define int1 char

#endif
////////////////////////////////////////////////////////////////// I/O
// Discrete I/O Functions: SET_TRIS_x(), OUTPUT_x(), INPUT_x(),
//                         PORT_x_PULLUPS(), INPUT(),
//                         OUTPUT_LOW(), OUTPUT_HIGH(),
//                         OUTPUT_FLOAT(), OUTPUT_BIT()
// Discrete I/O Prototypes:
_bif void set_tris_a(int8 value);  
_bif void set_tris_b(int8 value);  
_bif void set_tris_c(int8 value);  
_bif void set_tris_d(int8 value);  
_bif void set_tris_e(int8 value);  
_bif int8 get_tris_a(void);  
_bif int8 get_tris_b(void);  
_bif int8 get_tris_c(void);  
_bif int8 get_tris_d(void);  
_bif int8 get_tris_e(void);  
_bif void output_a(int8 value);  
_bif void output_b(int8 value);  
_bif void output_c(int8 value);  
_bif void output_d(int8 value);  
_bif void output_e(int8 value);  
_bif int8 input_a(void);  
_bif int8 input_b(void);  
_bif int8 input_c(void);  
_bif int8 input_d(void);  
_bif int8 input_e(void);  
_bif int1 input_change_a(void);  
_bif int1 input_change_b(void);  
_bif int1 input_change_c(void);  
_bif int1 input_change_d(void);  
_bif int1 input_change_e(void);  
_bif int1 input(int16 pin);
_bif int1 input_state(int16 pin);
_bif void output_low(int16 pin);
_bif void output_high(int16 pin);
_bif void output_toggle(int16 pin);
_bif void output_bit(int16 pin, int1 level);
_bif void output_float(int16 pin);
_bif void output_drive(int16 pin);

// Constants used to identify pins in the above are:

#define PIN_A0  31744
#define PIN_A1  31745
#define PIN_A2  31746
#define PIN_A3  31747
#define PIN_A4  31748
#define PIN_A5  31749
#define PIN_A6  31750
#define PIN_A7  31751

#define PIN_B0  31752
#define PIN_B1  31753
#define PIN_B2  31754
#define PIN_B3  31755
#define PIN_B4  31756
#define PIN_B5  31757
#define PIN_B6  31758
#define PIN_B7  31759

#define PIN_C0  31760
#define PIN_C1  31761
#define PIN_C2  31762
#define PIN_C6  31766
#define PIN_C7  31767

#define PIN_D0  31768
#define PIN_D1  31769
#define PIN_D2  31770
#define PIN_D3  31771
#define PIN_D4  31772
#define PIN_D5  31773
#define PIN_D6  31774
#define PIN_D7  31775

#define PIN_E0  31776
#define PIN_E1  31777
#define PIN_E2  31778
#define PIN_E3  31779

////////////////////////////////////////////////////////////////// Useful defines
#define FALSE 0
#define TRUE 1

#define BYTE int8
#define BOOLEAN int1

#define getc getch
#define fgetc getch
#define getchar getch
#define putc putchar
#define fputc putchar
#define fgets gets
#define fputs puts

////////////////////////////////////////////////////////////////// Control
// Control Functions:  RESET_CPU(), SLEEP(), RESTART_CAUSE()
// Prototypes:
_bif int8 restart_cause(void);
_bif void reset_cpu(void);
_bif void sleep(void);
_bif void sleep(int8 type); 
// Constants returned from RESTART_CAUSE() are:
#define WDT_TIMEOUT       7    
#define MCLR_FROM_SLEEP  11    
#define MCLR_FROM_RUN    15    
#define NORMAL_POWER_UP  12    
#define BROWNOUT_RESTART 14    
#define WDT_FROM_SLEEP    3    
#define RESET_INSTRUCTION 0    

// Constants for calls to sleep() are:
#define SLEEP_FULL       0  // Default
#define SLEEP_IDLE       1  // Clock and peripherals don't stop

////////////////////////////////////////////////////////////////// Timer 0
// Timer 0 (AKA RTCC)Functions: SETUP_COUNTERS() or SETUP_TIMER_0(),
//                              SET_TIMER0() or SET_RTCC(),
//                              GET_TIMER0() or GET_RTCC()
// Timer 0 Prototypes:
_bif void setup_timer_0(int8 mode);
_bif void set_timer0(int16 value);     
_bif int16 get_timer0(void);           
_bif void setup_counters(int8 mode, int8 prescaler);
_bif void set_rtcc(int16 value);       
_bif int16 get_rtcc(void);             
// Constants used for SETUP_TIMER_0() are:
#define T0_INTERNAL   0   
#define T0_EXT_L_TO_H 32
#define T0_EXT_H_TO_L 48

#define T0_DIV_1      8
#define T0_DIV_2      0
#define T0_DIV_4      1
#define T0_DIV_8      2
#define T0_DIV_16     3
#define T0_DIV_32     4
#define T0_DIV_64     5
#define T0_DIV_128    6
#define T0_DIV_256    7

#define T0_OFF        0x80  

#define T0_8_BIT      0x40  

#define RTCC_INTERNAL   0      // The following are provided for compatibility
#define RTCC_EXT_L_TO_H 32     // with older compiler versions
#define RTCC_EXT_H_TO_L 48
#define RTCC_DIV_1      8
#define RTCC_DIV_2      0
#define RTCC_DIV_4      1
#define RTCC_DIV_8      2
#define RTCC_DIV_16     3
#define RTCC_DIV_32     4
#define RTCC_DIV_64     5
#define RTCC_DIV_128    6
#define RTCC_DIV_256    7
#define RTCC_OFF        0x80  
#define RTCC_8_BIT      0x40  

// Constants used for SETUP_COUNTERS() are the above
// constants for the 1st param and the following for
// the 2nd param:

////////////////////////////////////////////////////////////////// WDT
// Watch Dog Timer Functions: SETUP_WDT() or SETUP_COUNTERS() (see above)
//                            RESTART_WDT()
// WDT base is 4ms
// WDT Prototypes:
_bif void setup_wdt(int16 mode);
_bif void restart_wdt(void);
// Constants used for SETUP_WDT() are:
#define WDT_ON        0x100
#define WDT_OFF       0

#define WDT_4MS    0x300  
#define WDT_8MS    0x500  
#define WDT_16MS   0x700  
#define WDT_32MS   0x900  
#define WDT_64MS   0xB00  
#define WDT_128MS  0xD00  
#define WDT_256MS  0xF00  
#define WDT_512MS  0x1100  
#define WDT_1S     0x1300  
#define WDT_2S     0x1500  
#define WDT_4S     0x1700  
#define WDT_8S     0x1900  
#define WDT_16     0x1B00  
#define WDT_32S    0x1D00  
#define WDT_64S    0x1F00  
#define WDT_128S   0x2100  


////////////////////////////////////////////////////////////////// Timer 1
// Timer 1 Functions: SETUP_TIMER_1, GET_TIMER1, SET_TIMER1
// Timer 1 Prototypes:
_bif void setup_timer_1(int16 mode);
_bif int16 get_timer1(void);
_bif void set_timer1(int16 value);
// Constants used for SETUP_TIMER_1() are:
//      (or (via |) together constants from each group)
#define T1_DISABLED         0
#define T1_INTERNAL         0x07
#define T1_EXTERNAL         0x87
#define T1_EXTERNAL_SYNC    0x83
#define T1_FOSC             0x47

#define T1_ENABLE_SOSC		0x08

#define T1_DIV_BY_1         0
#define T1_DIV_BY_2         0x10
#define T1_DIV_BY_4         0x20
#define T1_DIV_BY_8         0x30

#define T1_GATE           0x8000
#define T1_GATE_INVERTED  0xC000
#define T1_GATE_TOGGLE    0xA000
#define T1_GATE_SINGLE    0x9000
#define T1_GATE_TIMER2    0x8100
#define T1_GATE_COMP1     0x8200
#define T1_GATE_COMP2     0x8300

////////////////////////////////////////////////////////////////// Timer 2
// Timer 2 Functions: SETUP_TIMER_2, GET_TIMER2, SET_TIMER2
// Timer 2 Prototypes:
_bif void setup_timer_2(int8 mode, int8 period, int8 postscale); 
_bif int8 get_timer2(void);
_bif void set_timer2(int8 value);
// Constants used for SETUP_TIMER_2() are:
#define T2_DISABLED         0
#define T2_DIV_BY_1         4
#define T2_DIV_BY_4         5
#define T2_DIV_BY_16        6 

////////////////////////////////////////////////////////////////// Timer 3
// Timer 3 Functions: SETUP_TIMER_3, GET_TIMER3, SET_TIMER3
// Timer 3 Prototypes:
_bif void setup_timer_3(int16 mode);
_bif int16 get_timer3(void);
_bif void set_timer3(int16 value);
// Constants used for SETUP_TIMER_3() are:
//      (or (via |) together constants from each group)
#define T3_DISABLED         0
#define T3_INTERNAL         0x07
#define T3_EXTERNAL         0x87
#define T3_EXTERNAL_SYNC    0x83
#define T3_FOSC             0x47

#define T3_ENABLE_SOSC		0x08

#define T3_DIV_BY_1         0
#define T3_DIV_BY_2         0x10
#define T3_DIV_BY_4         0x20
#define T3_DIV_BY_8         0x30

#define T3_GATE           0x8000
#define T3_GATE_INVERTED  0xC000
#define T3_GATE_TOGGLE    0xA000
#define T3_GATE_SINGLE    0x9000
#define T3_GATE_TIMER4    0x8100
#define T3_GATE_COMP1     0x8200
#define T3_GATE_COMP2     0x8300

////////////////////////////////////////////////////////////////// CCP
// CCP Functions: SETUP_CCPx, SET_PWMx_DUTY
// CCP Variables: CCP_x, CCP_x_LOW, CCP_x_HIGH
// CCP1 Prototypes:
_bif void setup_ccp1(int32 mode);
_bif void setup_ccp1(int32 mode, int8 pwm);
_bif void set_pwm1_duty(int16 value);
// Constants used for SETUP_CCPx() are:
#define CCP_OFF                         0
#define CCP_CAPTURE_FE                  4
#define CCP_CAPTURE_RE                  5
#define CCP_CAPTURE_DIV_4               6
#define CCP_CAPTURE_DIV_16              7
#define CCP_COMPARE_SET_ON_MATCH        8
#define CCP_COMPARE_CLR_ON_MATCH        9
#define CCP_COMPARE_INT                 0xA
#define CCP_COMPARE_INT_AND_TOGGLE      0x2       
#define CCP_COMPARE_RESET_TIMER         0xB
#define CCP_PWM                         0xC
#define CCP_PWM_PLUS_1                  0x1c  
#define CCP_PWM_PLUS_2                  0x2c
#define CCP_PWM_PLUS_3                  0x3c
//#define CCP_USE_TIMER3                0x100  OBSOLETE, SEE TIMER-3     
#word   CCP_1       =                   getenv("SFR:CCPR1L")
#byte   CCP_1_LOW   =                   getenv("SFR:CCPR1L")
#byte   CCP_1_HIGH  =                   getenv("SFR:CCPR1H")
// The following are used to select the Timer source for the CCP/ECCP
// The first timer is the timer used when in CAPTURE or COMPARE mode
// The second timer is the timer used when in PWM mode
#define CCP_USE_TIMER1_AND_TIMER2       0x0000
#define CCP_USE_TIMER3_AND_TIMER2       0x0100

// The following should be used with the ECCP unit only (or these in)
#define CCP_PWM_H_H                     0x0c
#define CCP_PWM_H_L                     0x0d
#define CCP_PWM_L_H                     0x0e
#define CCP_PWM_L_L                     0x0f

#define CCP_PWM_FULL_BRIDGE             0x40
#define CCP_PWM_FULL_BRIDGE_REV         0xC0
#define CCP_PWM_HALF_BRIDGE             0x80

#define CCP_SHUTDOWN_ON_COMP1           0x100000
#define CCP_SHUTDOWN_ON_COMP2           0x200000
#define CCP_SHUTDOWN_ON_COMP            0x300000
#define CCP_SHUTDOWN_ON_INT0            0x400000
#define CCP_SHUTDOWN_ON_COMP1_INT0      0x500000
#define CCP_SHUTDOWN_ON_COMP2_INT0      0x600000
#define CCP_SHUTDOWN_ON_COMP_INT0       0x700000

#define CCP_SHUTDOWN_AC_L               0x000000
#define CCP_SHUTDOWN_AC_H               0x040000
#define CCP_SHUTDOWN_AC_F               0x080000

#define CCP_SHUTDOWN_BD_L               0x000000
#define CCP_SHUTDOWN_BD_H               0x010000
#define CCP_SHUTDOWN_BD_F               0x020000

#define CCP_SHUTDOWN_RESTART            0x80000000  

#define CCP_PULSE_STEERING_A            0x01000000
#define CCP_PULSE_STEERING_B            0x02000000
#define CCP_PULSE_STEERING_C            0x04000000
#define CCP_PULSE_STEERING_D            0x08000000
#define CCP_PULSE_STEERING_SYNC         0x10000000


// CCP2 Prototypes:
_bif void setup_ccp2(int32 mode);
_bif void setup_ccp2(int32 mode, int8 pwm);
_bif void set_pwm2_duty(int16 value);
#word   CCP_2       =                   getenv("SFR:CCPR2L")
#byte   CCP_2_LOW   =                   getenv("SFR:CCPR2L")
#byte   CCP_2_HIGH  =                   getenv("SFR:CCPR2H")
////////////////////////////////////////////////////////////////// SPI
// SPI Functions: SETUP_SPI, SPI_WRITE, SPI_READ, SPI_DATA_IN
// SPI Prototypes:
_bif void setup_spi(int32 mode);
_bif void spi_write(int8 value);
_bif int8 spi_read(void);
_bif int8 spi_read(int8 value);
_bif int1 spi_data_in(void);
// Constants used in SETUP_SPI() are:
#define SPI_DISABLED             0x00
#define SPI_MASTER               0x20
#define SPI_SLAVE                0x24
#define SPI_SCK_IDLE_HIGH        0x10
#define SPI_SCK_IDLE_LOW         0x00
#define SPI_CLK_DIV_4            0x00
#define SPI_CLK_DIV_16           0x01
#define SPI_CLK_DIV_64           0x02
#define SPI_CLK_T2               0x03
#define SPI_SS_DISABLED          0x01

#define SPI_XMIT_L_TO_H          0x4000
#define SPI_XMIT_H_TO_L          0x0000

#define SPI_SAMPLE_AT_MIDDLE     0x0000
#define SPI_SAMPLE_AT_END        0x8000

//The following are provided for compatibility
#define SPI_L_TO_H       SPI_SCK_IDLE_LOW
#define SPI_H_TO_L       SPI_SCK_IDLE_HIGH

////////////////////////////////////////////////////////////////// UART
// UART Prototypes:
_bif void setup_uart(int32 baud);
_bif void setup_uart(int32 baud, int8 stream);
_bif void setup_uart(int32 baud, int8 stream, int32 clock);
_bif void set_uart_speed(int32 baud);
_bif void set_uart_speed(int32 baud, int8 stream);
_bif void set_uart_speed(int32 baud, int8 stream, int32 clock);
// Constants used in setup_uart() are:
// FALSE - Turn UART off
// TRUE  - Turn UART on
#define UART_ADDRESS           2
#define UART_DATA              4
#define UART_AUTODETECT        8
#define UART_AUTODETECT_NOWAIT 9
#define UART_WAKEUP_ON_RDA     10
#define UART_SEND_BREAK        13
////////////////////////////////////////////////////////////////// COMP
// Comparator Variables: C1OUT, C2OUT
// Comparator Prototypes:
_bif void setup_comparator(int32 mode);
// Constants used in setup_comparator() are:
//
#define NC_NC_NC_NC   0x404
#define NC_NC         0x404

//Pick one constant for COMP1
#define CP1_A0_A3       0x000080
#define CP1_A1_A3       0x000081
#define CP1_B3_A3       0x000082
#define CP1_B1_A3       0x000083
#define CP1_A0_DAC      0x000084
#define CP1_A1_DAC      0x000085
#define CP1_B3_DAC      0x000086
#define CP1_B1_DAC      0x000087
#define CP1_A0_FVR      0x200084
#define CP1_A1_FVR      0x200085
#define CP1_B3_FVR      0x200086
#define CP1_B1_FVR      0x200087
//Optionally OR with any of the following
#define CP1_OUT_ON_A4   0x000020
#define CP1_INVERT    	0x000010
#define CP1_FAST      	0x000008
#define CP1_SYNC        0x020000

//OR with one constant for COMP2
#define CP2_A0_A2       0x008000
#define CP2_A1_A2       0x008100
#define CP2_B3_A2       0x008200
#define CP2_B1_A2       0x008300
#define CP2_A0_DAC      0x008400
#define CP2_A1_DAC      0x008500
#define CP2_B3_DAC      0x008600
#define CP2_B1_DAC      0x008700
#define CP2_A0_FVR      0x108400
#define CP2_A1_FVR      0x108500
#define CP2_B3_FVR      0x108600
#define CP2_B1_FVR      0x108700
//Optionally OR with any of the following
#define CP2_OUT_ON_A5   0x002000
#define CP2_INVERT      0x001000
#define CP2_FAST        0x000800
#define CP2_SYNC        0x010000

#bit C1OUT = 0xF79.6
#bit C2OUT = 0xF78.6

////////////////////////////////////////////////////////////////// VREF
// VREF Prototypes:
_bif void setup_vref(int8 mode);
// Constants used in setup_vref() are:
#define VREF_OFF     0
#define VREF_1v024   0x90
#define VREF_2v048   0xA0
#define VREF_4v096   0xB0

////////////////////////////////////////////////////////////////// VREF
// LVD Prototypes:
_bif void setup_low_volt_detect(int8 mode);
// Constants used in setup_low_volt_detect() are:
#define LVD_LVDIN   0x1F
#define LVD_47      0x1E
#define LVD_43      0x1D
#define LVD_41      0x1C
#define LVD_38      0x1B
#define LVD_36      0x1A
#define LVD_34      0x19
#define LVD_32      0x18
#define LVD_29      0x17
#define LVD_28      0x16
#define LVD_27      0x15
#define LVD_25      0x14
#define LVD_24      0x13
#define LVD_22      0x12
#define LVD_20      0x11
#define LVD_18      0x10

#define LVD_TRIGGER_BELOW 0
#define LVD_TRIGGER_ABOVE 0x80

////////////////////////////////////////////////////////////////// DAC
// Digital to Analog Functions: SETUP_DAC(), DAC_WRITE()
// DAC Prototypes:
_bif void setup_dac(int8 mode);
_bif void dac_write(int8 value);
// Constants used in SETUP_DAC() are:
#define DAC_OFF  0
#define DAC_VSS_VDD   0x80
#define DAC_VREF_VDD  0x81
#define DAC_VSS_VREF  0x84
#define DAC_VREF_VREF 0x85
#define DAC_VSS_FVR   0x88
#define DAC_FVR_VREF  0x89
// The following may be OR'ed in with the above using |
#define DAC_OUTPUT    0x20
#define DAC_LVP_POS   0x40  
#define DAC_LVP_NEG   0  


////////////////////////////////////////////////////////////////// INTERNAL RC
// Oscillator Prototypes:
_bif int16 setup_oscillator(int32 mode);
_bif int16 setup_oscillator(int32 mode, signed int8 tune);
_bif void setup_act(int8 mode);
_bif int8 setup_act(void);
_bif int8 setup_act(int8 mode);
_bif int8 act_status(void);
// Constants used in setup_oscillator() are:
// First param:
#define OSC_31KHZ                 0
#define OSC_31250                 0x4000
#define OSC_250KHZ                0x10
#define OSC_500KHZ                0x20
#define OSC_1MHZ                  0x30
#define OSC_2MHZ                  0x40
#define OSC_4MHZ                  0x50
#define OSC_8MHZ                  0x60
#define OSC_16MHZ                 0x70
// One of the following may be OR'ed in with the above using |
#define OSC_SOSC                  1
#define OSC_INTRC                 2
#define OSC_NORMAL                0
// The following may be OR'ed in with the above using |
#define OSC_PRIMARY_CIRCUIT_ON    0x000400
#define OSC_PRIMARY_CIRCUIT_OFF   0x000000
#define OSC_SOSC_ON               0x000800
#define OSC_PLL_ON                0x001000
#define OSC_PLL_OFF               0x000000
#define OSC_PLL_3X                0x800000
#define OSC_PLL_4X                0x000000
// A second optional parameter may be used with this part to fine
// tune the speed (signed int,-64 to 63)
// Result may be (ignore all other bits)
#define OSC_HFINTRC_STABLE        0x0004
#define OSC_RUNNING_FROM_PRIMARY  0x0008
#define OSC_LFINTRC_STABLE        0x0100
#define OSC_HFINTRC_RUNNING       0x0200
#define OSC_RUNNING_FROM_SOSC     0x4000
#define OSC_RUNNING_FROM_PLL      0x8000

// Constants used in setup_act() are:
#define ACT_DISABLED              0
#define ACT_ENABLED               0x80
#define ACT_TUNED_TO_SOSC         0
#define ACT_TUNED_TO_USB          0x10
// Result for setup_act() and act_status() may be (ignore all other bits)
#define ACT_CLOCK_LOCKED          0x08  //16 MHz internal oscillator is within � 0.20%
#define ACT_OUT_OF_RANGE          0x02  //oscillator frequency is outside of the OSCTUNE range


////////////////////////////////////////////////////////////////// ADC
// ADC Functions: SETUP_ADC(), SETUP_ADC_PORTS() (aka SETUP_PORT_A),
//                SET_ADC_CHANNEL(), READ_ADC()
// ADC Prototypes:
_bif void setup_adc(int16 mode);
_bif int8 read_adc(void);
_bif int8 read_adc(int8 mode);
_bif int16 read_adc(void);
_bif int16 read_adc(int8 mode);
_bif int1 adc_done(void);
// Constants used for SETUP_ADC() are:
#define ADC_OFF               0           // ADC Off
#define ADC_CLOCK_DIV_2   0x100
#define ADC_CLOCK_DIV_4    0x04
#define ADC_CLOCK_DIV_8    0x01
#define ADC_CLOCK_DIV_16   0x05
#define ADC_CLOCK_DIV_32   0x02
#define ADC_CLOCK_DIV_64   0x06
#define ADC_CLOCK_INTERNAL 0x07           // Internal 2-6us
// The following may be OR'ed in with the above using |
#define ADC_TAD_MUL_0      0x00
#define ADC_TAD_MUL_2      0x08
#define ADC_TAD_MUL_4      0x10
#define ADC_TAD_MUL_6      0x18
#define ADC_TAD_MUL_8      0x20
#define ADC_TAD_MUL_12     0x28
#define ADC_TAD_MUL_16     0x30
#define ADC_TAD_MUL_20     0x38

//ADC Prototypes:
_bif void setup_adc_ports(int32 pins);
_bif void setup_adc_ports(int32 pins, int32 reference);
_bif void set_adc_channel(int8 channel);
// Constants used in SETUP_ADC_PORTS() are:
// First argument:
// OR together desired pins
#define sAN0         0x00800000       //| A0
#define sAN1         0x01000000       //| A1
#define sAN2         0x02000000       //| A2
#define sAN3         0x04000000       //| A3
#define sAN4         0x08000000       //| A5
#define sAN5         0x00100000       //| E0  
#define sAN6         0x00200000       //| E1  
#define sAN7         0x00400000       //| E2  
#define sAN8         0x00010000       //| B2
#define sAN9         0x00020000       //| B3
#define sAN10        0x00008000       //| B1
#define sAN11        0x00040000       //| B4
#define sAN12        0x00004000       //| B0
#define sAN13        0x00080000       //| B5
#define sAN14        0x00000100       //| C2
#define sAN18        0x00001000       //| C6
#define sAN19        0x00002000       //| C7
#define sAN20        0x00000001       //| D0  
#define sAN21        0x00000002       //| D1  
#define sAN22        0x00000004       //| D2  
#define sAN23        0x00000008       //| D3  
#define sAN24        0x00000010       //| D4  
#define sAN25        0x00000020       //| D5  
#define sAN26        0x00000040       //| D6  
#define sAN27        0x00000080       //| D7  
#define NO_ANALOGS            0       // None
#define ALL_ANALOG   0x0FFFF1FF       // A0 A1 A2 A3 A5 E0 E1 E2 B2 B3 B1 B4 B0 B5 C2 C6 C7 D0 D1 D2 D3 D4 D5 D6 D7  

// Optional Second argument:
#define VSS_VDD      0x00000000       //| Range 0-Vdd
#define VSS_VREF     0x40000000       //| Range 0-VrefH
#define VSS_FVR      0x80000000       //| Range 0-Fvr BUF2
#define VREF_VDD     0x10000000       //| Range VrefL-Vdd
#define VREF_VREF    0x50000000       //| Range VrefL-VrefH
#define VREF_FVR     0x90000000       //| Range VrefL-Fvr BUF2

// Constants used in SET_ADC_CHANNEL() are:
// either use the channel number or one of the following
#define TEMPERATURE_DIODE   0x1C  
#define CTMU_CHANNEL        0x1D
#define DAC_CHANNEL         0x1E
#define FVR_CHANNEL         0x1F

// Constants used in READ_ADC() are:
#define ADC_START_AND_READ     7   // This is the default if nothing is specified
#define ADC_START_ONLY         1
#define ADC_READ_ONLY          6

////////////////////////////////////////////////////////////////// BIF
// Built In Functions Prototypes
//
// Math Prototypes:
_bif signed int8 abs(signed int8 x);
_bif signed int16 abs(signed int16 x);
_bif signed int32 abs(signed int32 x);
_bif float32 abs(float32 x);
_bif unsigned int16 _mul(unsigned int8, unsigned int8);
_bif signed int16 _mul(signed int8, signed int8);
_bif unsigned int32 _mul(unsigned int16, unsigned int16);
_bif signed int32 _mul(signed int16, signed int16);

// Memory Manipulation Prototypes:
_bif int8 read_bank(int8 bank, int8 offset);
_bif void write_bank(int8 bank, int8 offset, int8 value);
_bif void strcpy(char* dest, char* src);
_bif void strcopy(char* dest, char* src);
_bif void memset(unsigned int8* destination, unsigned int8 value, unsigned int16 num);
_bif void memcpy(unsigned int8* destination, unsigned int8* source, unsigned int16 num);

// String Prototypes:
_bif char toupper(char cvalue);
_bif char tolower(char cvalue);
_bif void sprintf(char* string, char* cstring, ...);

// Data Manipulators Prototypes:
_bif int1 shift_left(unsigned int8* address, unsigned int8 bytes, int1 value);
_bif int1 shift_right(unsigned int8* address, unsigned int8 bytes, int1 value);
_bif void rotate_left(unsigned int8* address, unsigned int8 bytes);
_bif void rotate_right(unsigned int8* address, unsigned int8 bytes);
_bif void swap(unsigned int8 value);
_bif unsigned int8 make8(unsigned int16 var, unsigned int8 offset);
_bif unsigned int8 make8(unsigned int32 var, unsigned int8 offset);
_bif unsigned int16 make16(unsigned int8 varhigh, unsigned int8 varlow);
_bif unsigned int32 make32(unsigned int16 var1);
_bif unsigned int32 make32(unsigned int16 var1, unsigned int16 var2);
_bif unsigned int32 make32(unsigned int16 var1, unsigned int8 var2);
_bif unsigned int32 make32(unsigned int16 var1, unsigned int8 var2, unsigned int8 var3);
_bif unsigned int32 make32(unsigned int8 var1);
_bif unsigned int32 make32(unsigned int8 var1, unsigned int8 var2);
_bif unsigned int32 make32(unsigned int8 var1, unsigned int8 var2, unsigned int8 var3);
_bif unsigned int32 make32(unsigned int8 var1, unsigned int8 var2, unsigned int8 var3, unsigned int8 var4);
_bif unsigned int32 make32(unsigned int8 var1, unsigned int16 var2);
_bif unsigned int32 make32(unsigned int8 var1, unsigned int16 var2, unsigned int8 var3);
_bif unsigned int32 make32(unsigned int8 var1, unsigned int8 var2, unsigned int16 var3);
_bif void bit_set(unsigned int8 var, unsigned int8 bit);
_bif void bit_set(unsigned int16 var, unsigned int8 bit);
_bif void bit_set(unsigned int32 var, unsigned int8 bit);
_bif void bit_clear(unsigned int8 var, unsigned int8 bit);
_bif void bit_clear(unsigned int16 var, unsigned int8 bit);
_bif void bit_clear(unsigned int32 var, unsigned int8 bit);
_bif int1 bit_test(unsigned int8 var, unsigned int8 bit);
_bif int1 bit_test(unsigned int16 var, unsigned int8 bit);
_bif int1 bit_test(unsigned int32 var, unsigned int8 bit);

// #use delay() Prototypes:
_bif void delay_cycles(unsigned int8 count);
_bif void delay_ms(unsigned int16 time);
_bif void delay_us(unsigned int16 time);

// #use rs232() Prototypes:
_bif void putchar(char cdata);
_bif void putchar(char cdata, unsigned int8 stream);
_bif void puts(char* string);
_bif void puts(char* string, unsigned int8 stream);
_bif char getch(void);
_bif char getch(unsigned int8 stream);
_bif void gets(char* string);
_bif void gets(char* string, unsigned int8 stream);
_bif int1 kbhit(void);
_bif int1 kbhit(unsigned int8 stream);
_bif void printf(char* string, ...);
_bif void fprintf(unsigned int8 stream, char* string, ...);
_bif void putc_send(void);
_bif void fputc_send(unsigned int8 stream);
_bif int1 rcv_buffer_full(void);
_bif int1 rcv_buffer_full(unsigned int8 stream);
_bif unsigned int16 rcv_buffer_bytes(void);
_bif unsigned int16 rcv_buffer_bytes(unsigned int8 stream);
_bif int1 tx_buffer_full(void);
_bif int1 tx_buffer_full(unsigned int8 stream);
_bif unsigned int16 tx_buffer_bytes(void);
_bif unsigned int16 tx_buffer_bytes(unsigned int8 stream);

// #use i2c() Prototypes:
_bif unsigned int8 i2c_read(void);
_bif unsigned int8 i2c_read(unsigned int8 stream);
_bif unsigned int8 i2c_read(unsigned int8 stream, int1 ack);
_bif int1 i2c_write(unsigned int8 data);
_bif int1 i2c_write(unsigned int8 stream, unsigned int8 data);
_bif void i2c_start(void);
_bif void i2c_start(unsigned int8 stream);
_bif void i2c_start(unsigned int8 stream, unsigned int8 restart);
_bif void i2c_stop(void);
_bif void i2c_stop(unsigned int8 stream);
_bif int8 i2c_isr_state(void);
_bif void i2c_slaveaddr(unsigned int8 addr);
_bif void i2c_slaveaddr(unsigned int8 stream, unsigned int8 addr);
_bif int1 i2c_poll(void);
_bif int1 i2c_poll(unsigned int8 stream);
_bif void i2c_init(unsigned int32 baud);
_bif void i2c_init(unsigned int8 stream, unsigned int32 baud);

// #use spi() Prototypes:
_bif unsigned int8 spi_xfer(void);
_bif unsigned int16 spi_xfer(void);
_bif unsigned int32 spi_xfer(void);
_bif unsigned int8 spi_xfer(unsigned int8 data);
_bif unsigned int16 spi_xfer(unsigned int16 data);
_bif unsigned int32 spi_xfer(unsigned int32 data);
_bif unsigned int8 spi_xfer(unsigned int8 stream, unsigned int8 data);
_bif unsigned int16 spi_xfer(unsigned int8 stream, unsigned int16 data);
_bif unsigned int32 spi_xfer(unsigned int8 stream, unsigned int32 data);
_bif unsigned int8 spi_xfer(unsigned int8 stream, unsigned int8 data, unsigned int8 bits);
_bif unsigned int16 spi_xfer(unsigned int8 stream, unsigned int16 data, unsigned int8 bits);
_bif unsigned int32 spi_xfer(unsigned int8 stream, unsigned int32 data, unsigned int8 bits);
_bif void spi_init(unsigned int32 baud);
_bif void spi_init(unsigned int8 stream, unsigned int32 baud);
_bif void spi_speed(unsigned int32 baud);
_bif void spi_speed(unsigned int8 stream, unsigned int32 baud);
_bif void spi_speed(unsigned int8 stream, unsigned int32 baud, unsigned int32 clock);
_bif void spi_prewrite(unsigned int8 data);
_bif void spi_prewrite(unsigned int16 data);
_bif void spi_prewrite(unsigned int32 data);
_bif void spi_prewrite(unsigned int8, unsigned int8 data);
_bif void spi_prewrite(unsigned int8, unsigned int16 data);
_bif void spi_prewrite(unsigned int8, unsigned int32 data);
_bif unsigned int8 spi_xfer_in(void);
_bif unsigned int16 spi_xfer_in(void);
_bif unsigned int32 spi_xfer_in(void);
_bif unsigned int8 spi_xfer_in(unsigned int8 bits);
_bif unsigned int16 spi_xfer_in(unsigned int8 bits);
_bif unsigned int32 spi_xfer_in(unsigned int8 bits);
_bif unsigned int8 spi_xfer_in(unsigned int8 stream, unsigned int8 bits);
_bif unsigned int16 spi_xfer_in(unsigned int8 stream, unsigned int8 bits);
_bif unsigned int32 spi_xfer_in(unsigned int8 stream, unsigned int8 bits);

// #use rtos() Prototypes:
_bif void rtos_run(void);
_bif void rtos_yield(void);
_bif void rtos_enable(unsigned int8 task);
_bif void rtos_disable(unsigned int8 task);
_bif void rtos_terminate(void);
_bif void rtos_await(int1 flag);
_bif void rtos_wait(unsigned int8 sem);
_bif void rtos_signal(unsigned int8 sem);
_bif void rtos_msg_send(unsigned int8 task, unsigned int8 msg);
_bif unsigned int8 rtos_msg_read(void);
_bif unsigned int8 rtos_msg_poll(void);
_bif int1 rtos_overrun(unsigned int8 task);
_bif void rtos_stats(unsigned int8 task, unsigned int8* stat);

// #use timer() Prototypes:
_bif unsigned int8 get_ticks(void);
_bif unsigned int16 get_ticks(void);
_bif unsigned int32 get_ticks(void);
_bif unsigned int8 get_ticks(unsigned int8 stream);
_bif unsigned int16 get_ticks(unsigned int8 stream);
_bif unsigned int32 get_ticks(unsigned int8 stream);
_bif void set_ticks(unsigned int8 value);
_bif void set_ticks(unsigned int16 value);
_bif void set_ticks(unsigned int32 value);
_bif void set_ticks(unsigned int8 stream, unsigned int8 value);
_bif void set_ticks(unsigned int8 stream, unsigned int16 value);
_bif void set_ticks(unsigned int8 stream, unsigned int32 value);

// #use pwm() Prototypes:
_bif void pwm_on(void);
_bif void pwm_on(unsigned int8 stream);
_bif void pwm_off(void);
_bif void pwm_off(unsigned int8 stream);
_bif void pwm_set_duty(unsigned int16 duty);
_bif void pwm_set_duty(unsigned int8 stream, unsigned int16 duty);
_bif void pwm_set_duty_percent(unsigned int16 percent);
_bif void pwm_set_duty_percent(unsigned int8 stream, unsigned int16 percent);
_bif void pwm_set_frequency(unsigned int32 frequency);
_bif void pwm_set_frequency(unsigned int8 stream, unsigned int32 frequency);

// #use capture() Prototypes:
_bif unsigned int16 get_capture_time(void);
_bif unsigned int16 get_capture_time(unsigned int8 stream);
_bif int1 get_capture_event(void);
_bif int1 get_capture_event(unsigned int8 stream);

// Enviroment Prototypes:
//_bif unsigned int8 getenv(char* cstring);

// Address Prototypes:
#ifndef __ADDRESS__
 #if defined(__PCM__) || define(__PCB__)
  typedef unsigned int16 __ADDRESS__;
 #else
  typedef unsigned int32 __ADDRESS__;
 #endif
#endif
_bif void goto_address(__ADDRESS__ address);
_bif __ADDRESS__ label_address(__ADDRESS__ label);

// Program Memory Prototypes:
_bif void read_program_memory(__ADDRESS__ address, unsigned int8* dataptr, unsigned int16 count);
_bif unsigned int16 read_program_eeprom(__ADDRESS__ address);
_bif void erase_program_eeprom(__ADDRESS__ address);
_bif void write_program_memory(__ADDRESS__ address, unsigned int8* dataptr, unsigned int16 count);
_bif void write_program_eeprom(__ADDRESS__ address, unsigned int16 data);

// EEPROM Prototypes:
#ifndef __EEADDRESS__
 #if getenv("DATA_EEPROM")>=0x100
  typedef unsigned int16 __EEADDRESS__;
 #else
  typedef unsigned int8 __EEADDRESS__;
 #endif
#endif
_bif unsigned int8 read_eeprom(__EEADDRESS__ address);
_bif void write_eeprom(__EEADDRESS__ address, unsigned int8 value);

// #use touchpad() Prototypes:
_bif void touchpad_state(unsigned int8 state);
_bif char touchpad_getc(void);
_bif int1 touchpad_hit(void);
////////////////////////////////////////////////////////////////// INT
// Interrupt Functions: ENABLE_INTERRUPTS(), DISABLE_INTERRUPTS(),
//                      CLEAR_INTERRUPT(), INTERRUPT_ACTIVE(),
//                      EXT_INT_EDGE()
// INT Prototypes:
_bif void enable_interrupts(int32 interrupt);
_bif void disable_interrupts(int32 interrupt);
_bif void clear_interrupt(int32 interrupt);
_bif int1 interrupt_active(int32 interrupt);
_bif int1 interrupt_enabled(int32 interrupt);
_bif void ext_int_edge(int8 source, int8 edge);
_bif void jump_to_irs(int16 address);
// Constants used in EXT_INT_EDGE() are:
#define L_TO_H              0x40
#define H_TO_L                 0
// Constants used in ENABLE/DISABLE_INTERRUPTS() are:
#define GLOBAL                    0xF2C0
#define PERIPH                    0xF240
#define INT_RTCC                  0x00F220
#define INT_TIMER0                0x00F220
#define INT_TIMER1                0x009D01
#define INT_TIMER2                0x009D02
#define INT_TIMER3                0x00A002
#define INT_EXT_L2H               0x5000F210
#define INT_EXT_H2L               0x6000F210
#define INT_EXT                   0x00F210
#define INT_EXT1_L2H              0x5001F008
#define INT_EXT1_H2L              0x6001F008
#define INT_EXT1                  0x00F008
#define INT_EXT2_L2H              0x5002F010
#define INT_EXT2_H2L              0x6002F010
#define INT_EXT2                  0x00F010
#define INT_RB                    0x01FFF208
#define INT_AD                    0x009D40
#define INT_RDA                   0x009D20
#define INT_TBE                   0x009D10
#define INT_SSP                   0x009D08
#define INT_CCP1                  0x009D04
#define INT_CCP2                  0x00A001
#define INT_BUSCOL                0x00A008
#define INT_COMP                  0x00A040
#define INT_EEPROM                0x00A010
#define INT_OSCF                  0x00A080
#define INT_HLVD                  0x00A004
#define INT_COMP2                 0x00A020
#define INT_TMR1G                 0x00A301
#define INT_TMR3G                 0x00A302
#define INT_CTMU                  0x00A308
#define INT_RC                    0x02FFF208
#define INT_USB                   0x00A304
#define INT_ACT                   0x009D80
#define INT_RB4                   0x110F208
#define INT_RB5                   0x120F208
#define INT_RB6                   0x140F208
#define INT_RB7                   0x180F208
#define INT_RC0                   0x201F208
#define INT_RC1                   0x202F208
#define INT_RC2                   0x204F208
#define INT_RC6                   0x240F208
#define INT_RC7                   0x280F208

#list
