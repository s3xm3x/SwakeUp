EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:power-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title "LED Driver Red"
Date "2016-11-24"
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Q_NPN_BCE Q2
U 1 1 58375354
P 2850 5900
F 0 "Q2" H 3150 5900 50  0000 R CNN
F 1 "Q_NPN_BCE" H 3450 5850 50  0001 R CNN
F 2 "" H 3050 6000 50  0000 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2850 5900 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 3550 5850 60  0001 C CNN "Digikey"
	1    2850 5900
	1    0    0    -1  
$EndComp
$Comp
L Q_PMOS_DGS Q3
U 1 1 583753F3
P 3400 5450
F 0 "Q3" V 3650 5450 50  0000 R CNN
F 1 "Q_PMOS_DGS" H 4050 5400 50  0001 R CNN
F 2 "" H 3600 5550 50  0000 C CNN
F 3 "http://www.diodes.com/_files/datasheets/DMG2305UX.pdf" H 3400 5450 50  0001 C CNN
F 4 "DMG2305UX-13DICT-ND" H 3400 5450 60  0001 C CNN "Digikey"
	1    3400 5450
	0    -1   -1   0   
$EndComp
$Comp
L D D1
U 1 1 5837550B
P 3400 6300
F 0 "D1" V 3400 6150 50  0000 C CNN
F 1 "D" H 3400 6200 50  0001 C CNN
F 2 "" H 3400 6300 50  0000 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Vishay%20Semiconductors/1N4148WFL-G.pdf" H 3400 6300 50  0001 C CNN
F 4 "1N4148WFL-G3-08GITR-ND" V 3350 5550 60  0001 C CNN "Digikey"
	1    3400 6300
	0    -1   -1   0   
$EndComp
$Comp
L R R2
U 1 1 58375629
P 2600 5600
F 0 "R2" V 2680 5600 50  0000 C CNN
F 1 "10k" V 2600 5600 50  0000 C CNN
F 2 "" V 2530 5600 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 2600 5600 50  0001 C CNN
F 4 "311-10KGRCT-ND" V 2600 5600 60  0001 C CNN "Digikey"
	1    2600 5600
	-1   0    0    1   
$EndComp
$Comp
L R R1
U 1 1 5837574C
P 2000 6750
F 0 "R1" V 2080 6750 50  0000 C CNN
F 1 "470R" V 2000 6750 50  0000 C CNN
F 2 "" V 1930 6750 50  0000 C CNN
F 3 "https://industrial.panasonic.com/cdbs/www-data/pdf/RDA0000/AOA0000COL70.pdf" H 2000 6750 50  0001 C CNN
F 4 "P20245CT-ND" V 2000 6750 60  0001 C CNN "Digikey"
	1    2000 6750
	0    1    1    0   
$EndComp
$Comp
L C C1
U 1 1 5837578D
P 2000 6450
F 0 "C1" H 2025 6550 50  0000 L CNN
F 1 "150p" H 2025 6350 50  0000 L CNN
F 2 "" H 2038 6300 50  0000 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM033R71E151KA01-01.pdf" H 2000 6450 50  0001 C CNN
F 4 "490-3174-1-ND" H 2000 6450 60  0001 C CNN "Digikey"
	1    2000 6450
	0    1    1    0   
$EndComp
Text HLabel 1650 6750 0    60   Input ~ 0
PWM_G
$Comp
L INDUCTOR L1
U 1 1 58375D14
P 4150 6200
F 0 "L1" V 4350 6200 50  0000 C CNN
F 1 "33u" V 4250 6200 50  0000 C CNN
F 2 "" H 4150 6200 50  0000 C CNN
F 3 "http://www.bourns.com/docs/Product-Datasheets/SRN3015.pdf" H 4150 6200 50  0001 C CNN
F 4 "SRN3015-330MCT-ND" V 4300 5650 60  0001 C CNN "Digikey"
	1    4150 6200
	0    -1   -1   0   
$EndComp
$Comp
L D_Schottky D2
U 1 1 58375DFD
P 3750 6600
F 0 "D2" V 3750 6750 50  0000 C CNN
F 1 "D_Schottky" H 3750 6500 50  0001 C CNN
F 2 "" H 3750 6600 50  0000 C CNN
F 3 "http://www.vishay.com/docs/88869/packaging.pdf" H 3750 6600 50  0001 C CNN
F 4 "10MQ060NPBFCT-ND" V 3800 7200 60  0001 C CNN "Digikey"
	1    3750 6600
	0    1    1    0   
$EndComp
$Comp
L C C2
U 1 1 58375E8F
P 4550 6600
F 0 "C2" H 4575 6700 50  0000 L CNN
F 1 "10u" H 4575 6500 50  0000 L CNN
F 2 "" H 4588 6450 50  0000 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 4550 6600 50  0001 C CNN
F 4 "490-12323-1-ND" H 4550 6600 60  0001 C CNN "Digikey"
	1    4550 6600
	1    0    0    -1  
$EndComp
Text HLabel 5800 6200 2    60   Output ~ 0
LED_G_P
Text HLabel 5800 6350 2    60   Output ~ 0
LED_G_N
$Comp
L R R3
U 1 1 5837686D
P 4850 6850
F 0 "R3" V 4930 6850 50  0000 C CNN
F 1 "0.1R" V 4850 6850 50  0000 C CNN
F 2 "" V 4780 6850 50  0000 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RU_Series_ds.pdf" H 4850 6850 50  0001 C CNN
F 4 "1276-6155-1-ND" V 4850 6850 60  0001 C CNN "Digikey"
	1    4850 6850
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 583772C0
P 5600 6850
F 0 "C3" H 5625 6950 50  0000 L CNN
F 1 "22n" H 5625 6750 50  0000 L CNN
F 2 "" H 5638 6700 50  0000 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_highreliability_general_en.pdf" H 5600 6850 50  0001 C CNN
F 4 "445-8118-1-ND" H 5600 6850 60  0001 C CNN "Digikey"
	1    5600 6850
	-1   0    0    1   
$EndComp
$Comp
L R R4
U 1 1 5837748D
P 5250 6650
F 0 "R4" V 5330 6650 50  0000 C CNN
F 1 "4.7k" V 5250 6650 50  0000 C CNN
F 2 "" V 5180 6650 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5250 6650 50  0001 C CNN
F 4 "311-4.7KGRCT-ND" V 5250 6650 60  0001 C CNN "Digikey"
	1    5250 6650
	0    1    1    0   
$EndComp
Wire Wire Line
	1050 5350 3200 5350
Wire Wire Line
	2600 5450 2600 5350
Connection ~ 2600 5350
Wire Wire Line
	2600 5750 2600 6550
Wire Wire Line
	2600 5900 2650 5900
Wire Wire Line
	2950 5700 2950 5350
Connection ~ 2950 5350
Wire Wire Line
	2950 6100 3400 6100
Wire Wire Line
	3400 5650 3400 6150
Connection ~ 3400 6100
Wire Wire Line
	3400 6500 3400 6450
Wire Wire Line
	1650 6750 1850 6750
Wire Wire Line
	2150 6750 2300 6750
Wire Wire Line
	1850 6450 1800 6450
Wire Wire Line
	1800 6450 1800 6750
Connection ~ 1800 6750
Wire Wire Line
	2150 6450 2200 6450
Wire Wire Line
	2200 6450 2200 6750
Connection ~ 2200 6750
Connection ~ 2600 5900
Wire Wire Line
	2600 6500 3400 6500
Wire Wire Line
	3750 6200 3850 6200
Connection ~ 2600 6500
Wire Wire Line
	4550 6450 4550 6200
Connection ~ 4550 6200
Wire Wire Line
	3750 6750 3750 7050
Wire Wire Line
	2600 7050 5600 7050
Wire Wire Line
	2600 7050 2600 6950
Wire Wire Line
	4550 7050 4550 6750
Connection ~ 3750 7050
Connection ~ 4550 7050
Wire Wire Line
	4850 7050 4850 7000
Wire Wire Line
	4450 6200 5800 6200
Wire Wire Line
	3750 5350 3750 6450
Connection ~ 3750 6200
Wire Wire Line
	3600 5350 3750 5350
Wire Wire Line
	5800 6350 4850 6350
Wire Wire Line
	4850 6350 4850 6700
Wire Wire Line
	5100 6650 4850 6650
Connection ~ 4850 6650
Wire Wire Line
	5400 6650 5800 6650
Wire Wire Line
	5600 6650 5600 6700
Connection ~ 4850 7050
Wire Wire Line
	5600 7050 5600 7000
Text HLabel 5800 6650 2    60   Output ~ 0
OPAMP_G
Connection ~ 5600 6650
$Comp
L Q_NPN_BCE Q1
U 1 1 583781C6
P 2500 6750
F 0 "Q1" H 2800 6750 50  0000 R CNN
F 1 "Q_NPN_BCE" H 3100 6700 50  0001 R CNN
F 2 "" H 2700 6850 50  0000 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2500 6750 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 3200 6700 60  0001 C CNN "Digikey"
	1    2500 6750
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCE Q?
U 1 1 5837BEE8
P 2850 3700
F 0 "Q?" H 3150 3700 50  0000 R CNN
F 1 "Q_NPN_BCE" H 3450 3650 50  0001 R CNN
F 2 "" H 3050 3800 50  0000 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2850 3700 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 3550 3650 60  0001 C CNN "Digikey"
	1    2850 3700
	1    0    0    -1  
$EndComp
$Comp
L Q_PMOS_DGS Q?
U 1 1 5837BEEF
P 3400 3250
F 0 "Q?" V 3650 3250 50  0000 R CNN
F 1 "Q_PMOS_DGS" H 4050 3200 50  0001 R CNN
F 2 "" H 3600 3350 50  0000 C CNN
F 3 "http://www.diodes.com/_files/datasheets/DMG2305UX.pdf" H 3400 3250 50  0001 C CNN
F 4 "DMG2305UX-13DICT-ND" H 3400 3250 60  0001 C CNN "Digikey"
	1    3400 3250
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5837BEF6
P 3400 4100
F 0 "D?" V 3400 3950 50  0000 C CNN
F 1 "D" H 3400 4000 50  0001 C CNN
F 2 "" H 3400 4100 50  0000 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Vishay%20Semiconductors/1N4148WFL-G.pdf" H 3400 4100 50  0001 C CNN
F 4 "1N4148WFL-G3-08GITR-ND" V 3350 3350 60  0001 C CNN "Digikey"
	1    3400 4100
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 5837BEFE
P 2600 3400
F 0 "R?" V 2680 3400 50  0000 C CNN
F 1 "10k" V 2600 3400 50  0000 C CNN
F 2 "" V 2530 3400 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 2600 3400 50  0001 C CNN
F 4 "311-10KGRCT-ND" V 2600 3400 60  0001 C CNN "Digikey"
	1    2600 3400
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5837BF05
P 2000 4550
F 0 "R?" V 2080 4550 50  0000 C CNN
F 1 "470R" V 2000 4550 50  0000 C CNN
F 2 "" V 1930 4550 50  0000 C CNN
F 3 "https://industrial.panasonic.com/cdbs/www-data/pdf/RDA0000/AOA0000COL70.pdf" H 2000 4550 50  0001 C CNN
F 4 "P20245CT-ND" V 2000 4550 60  0001 C CNN "Digikey"
	1    2000 4550
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 5837BF0C
P 2000 4250
F 0 "C?" H 2025 4350 50  0000 L CNN
F 1 "150p" H 2025 4150 50  0000 L CNN
F 2 "" H 2038 4100 50  0000 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM033R71E151KA01-01.pdf" H 2000 4250 50  0001 C CNN
F 4 "490-3174-1-ND" H 2000 4250 60  0001 C CNN "Digikey"
	1    2000 4250
	0    1    1    0   
$EndComp
Text HLabel 1650 4550 0    60   Input ~ 0
PWM_B
$Comp
L INDUCTOR L?
U 1 1 5837BF14
P 4150 4000
F 0 "L?" V 4350 4000 50  0000 C CNN
F 1 "33u" V 4250 4000 50  0000 C CNN
F 2 "" H 4150 4000 50  0000 C CNN
F 3 "http://www.bourns.com/docs/Product-Datasheets/SRN3015.pdf" H 4150 4000 50  0001 C CNN
F 4 "SRN3015-330MCT-ND" V 4300 3450 60  0001 C CNN "Digikey"
	1    4150 4000
	0    -1   -1   0   
$EndComp
$Comp
L D_Schottky D?
U 1 1 5837BF1B
P 3750 4400
F 0 "D?" V 3750 4550 50  0000 C CNN
F 1 "D_Schottky" H 3750 4300 50  0001 C CNN
F 2 "" H 3750 4400 50  0000 C CNN
F 3 "http://www.vishay.com/docs/88869/packaging.pdf" H 3750 4400 50  0001 C CNN
F 4 "10MQ060NPBFCT-ND" V 3800 5000 60  0001 C CNN "Digikey"
	1    3750 4400
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 5837BF22
P 4550 4400
F 0 "C?" H 4575 4500 50  0000 L CNN
F 1 "10u" H 4575 4300 50  0000 L CNN
F 2 "" H 4588 4250 50  0000 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 4550 4400 50  0001 C CNN
F 4 "490-12323-1-ND" H 4550 4400 60  0001 C CNN "Digikey"
	1    4550 4400
	1    0    0    -1  
$EndComp
Text HLabel 5800 4000 2    60   Output ~ 0
LED_B_P
Text HLabel 5800 4150 2    60   Output ~ 0
LED_B_N
$Comp
L R R?
U 1 1 5837BF2B
P 4850 4650
F 0 "R?" V 4930 4650 50  0000 C CNN
F 1 "0.1R" V 4850 4650 50  0000 C CNN
F 2 "" V 4780 4650 50  0000 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RU_Series_ds.pdf" H 4850 4650 50  0001 C CNN
F 4 "1276-6155-1-ND" V 4850 4650 60  0001 C CNN "Digikey"
	1    4850 4650
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5837BF32
P 5600 4650
F 0 "C?" H 5625 4750 50  0000 L CNN
F 1 "22n" H 5625 4550 50  0000 L CNN
F 2 "" H 5638 4500 50  0000 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_highreliability_general_en.pdf" H 5600 4650 50  0001 C CNN
F 4 "445-8118-1-ND" H 5600 4650 60  0001 C CNN "Digikey"
	1    5600 4650
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5837BF39
P 5250 4450
F 0 "R?" V 5330 4450 50  0000 C CNN
F 1 "4.7k" V 5250 4450 50  0000 C CNN
F 2 "" V 5180 4450 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5250 4450 50  0001 C CNN
F 4 "311-4.7KGRCT-ND" V 5250 4450 60  0001 C CNN "Digikey"
	1    5250 4450
	0    1    1    0   
$EndComp
Wire Wire Line
	1050 3150 3200 3150
Wire Wire Line
	2600 3250 2600 3150
Connection ~ 2600 3150
Wire Wire Line
	2600 3550 2600 4350
Wire Wire Line
	2600 3700 2650 3700
Wire Wire Line
	2950 3500 2950 3150
Connection ~ 2950 3150
Wire Wire Line
	2950 3900 3400 3900
Wire Wire Line
	3400 3450 3400 3950
Connection ~ 3400 3900
Wire Wire Line
	3400 4300 3400 4250
Wire Wire Line
	1650 4550 1850 4550
Wire Wire Line
	2150 4550 2300 4550
Wire Wire Line
	1850 4250 1800 4250
Wire Wire Line
	1800 4250 1800 4550
Connection ~ 1800 4550
Wire Wire Line
	2150 4250 2200 4250
Wire Wire Line
	2200 4250 2200 4550
Connection ~ 2200 4550
Connection ~ 2600 3700
Wire Wire Line
	2600 4300 3400 4300
Wire Wire Line
	3750 4000 3850 4000
Connection ~ 2600 4300
Wire Wire Line
	4550 4250 4550 4000
Connection ~ 4550 4000
Wire Wire Line
	3750 4550 3750 4850
Wire Wire Line
	2600 4850 5600 4850
Wire Wire Line
	2600 4850 2600 4750
Wire Wire Line
	4550 4850 4550 4550
Connection ~ 3750 4850
Connection ~ 4550 4850
Wire Wire Line
	4850 4850 4850 4800
Wire Wire Line
	4450 4000 5800 4000
Wire Wire Line
	3750 3150 3750 4250
Connection ~ 3750 4000
Wire Wire Line
	3600 3150 3750 3150
Wire Wire Line
	5800 4150 4850 4150
Wire Wire Line
	4850 4150 4850 4500
Wire Wire Line
	5100 4450 4850 4450
Connection ~ 4850 4450
Wire Wire Line
	5400 4450 5800 4450
Wire Wire Line
	5600 4450 5600 4500
Connection ~ 4850 4850
Wire Wire Line
	5600 4850 5600 4800
Text HLabel 5800 4450 2    60   Output ~ 0
OPAMP_B
Connection ~ 5600 4450
$Comp
L Q_NPN_BCE Q?
U 1 1 5837BF6E
P 2500 4550
F 0 "Q?" H 2800 4550 50  0000 R CNN
F 1 "Q_NPN_BCE" H 3100 4500 50  0001 R CNN
F 2 "" H 2700 4650 50  0000 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2500 4550 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 3200 4500 60  0001 C CNN "Digikey"
	1    2500 4550
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCE Q?
U 1 1 5837C3ED
P 2850 1650
F 0 "Q?" H 3150 1650 50  0000 R CNN
F 1 "Q_NPN_BCE" H 3450 1600 50  0001 R CNN
F 2 "" H 3050 1750 50  0000 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2850 1650 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 3550 1600 60  0001 C CNN "Digikey"
	1    2850 1650
	1    0    0    -1  
$EndComp
$Comp
L Q_PMOS_DGS Q?
U 1 1 5837C3F4
P 3400 1200
F 0 "Q?" V 3650 1200 50  0000 R CNN
F 1 "Q_PMOS_DGS" H 4050 1150 50  0001 R CNN
F 2 "" H 3600 1300 50  0000 C CNN
F 3 "http://www.diodes.com/_files/datasheets/DMG2305UX.pdf" H 3400 1200 50  0001 C CNN
F 4 "DMG2305UX-13DICT-ND" H 3400 1200 60  0001 C CNN "Digikey"
	1    3400 1200
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 5837C3FB
P 3400 2050
F 0 "D?" V 3400 1900 50  0000 C CNN
F 1 "D" H 3400 1950 50  0001 C CNN
F 2 "" H 3400 2050 50  0000 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Vishay%20Semiconductors/1N4148WFL-G.pdf" H 3400 2050 50  0001 C CNN
F 4 "1N4148WFL-G3-08GITR-ND" V 3350 1300 60  0001 C CNN "Digikey"
	1    3400 2050
	0    -1   -1   0   
$EndComp
Text GLabel 950  1100 0    60   Input ~ 0
V20
$Comp
L R R?
U 1 1 5837C403
P 2600 1350
F 0 "R?" V 2680 1350 50  0000 C CNN
F 1 "10k" V 2600 1350 50  0000 C CNN
F 2 "" V 2530 1350 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 2600 1350 50  0001 C CNN
F 4 "311-10KGRCT-ND" V 2600 1350 60  0001 C CNN "Digikey"
	1    2600 1350
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5837C40A
P 2000 2500
F 0 "R?" V 2080 2500 50  0000 C CNN
F 1 "470R" V 2000 2500 50  0000 C CNN
F 2 "" V 1930 2500 50  0000 C CNN
F 3 "https://industrial.panasonic.com/cdbs/www-data/pdf/RDA0000/AOA0000COL70.pdf" H 2000 2500 50  0001 C CNN
F 4 "P20245CT-ND" V 2000 2500 60  0001 C CNN "Digikey"
	1    2000 2500
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 5837C411
P 2000 2200
F 0 "C?" H 2025 2300 50  0000 L CNN
F 1 "150p" H 2025 2100 50  0000 L CNN
F 2 "" H 2038 2050 50  0000 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM033R71E151KA01-01.pdf" H 2000 2200 50  0001 C CNN
F 4 "490-3174-1-ND" H 2000 2200 60  0001 C CNN "Digikey"
	1    2000 2200
	0    1    1    0   
$EndComp
Text HLabel 1650 2500 0    60   Input ~ 0
PWM_R
$Comp
L INDUCTOR L?
U 1 1 5837C419
P 4150 1950
F 0 "L?" V 4350 1950 50  0000 C CNN
F 1 "33u" V 4250 1950 50  0000 C CNN
F 2 "" H 4150 1950 50  0000 C CNN
F 3 "http://www.bourns.com/docs/Product-Datasheets/SRN3015.pdf" H 4150 1950 50  0001 C CNN
F 4 "SRN3015-330MCT-ND" V 4300 1400 60  0001 C CNN "Digikey"
	1    4150 1950
	0    -1   -1   0   
$EndComp
$Comp
L D_Schottky D?
U 1 1 5837C420
P 3750 2350
F 0 "D?" V 3750 2500 50  0000 C CNN
F 1 "D_Schottky" H 3750 2250 50  0001 C CNN
F 2 "" H 3750 2350 50  0000 C CNN
F 3 "http://www.vishay.com/docs/88869/packaging.pdf" H 3750 2350 50  0001 C CNN
F 4 "10MQ060NPBFCT-ND" V 3800 2950 60  0001 C CNN "Digikey"
	1    3750 2350
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 5837C427
P 4550 2350
F 0 "C?" H 4575 2450 50  0000 L CNN
F 1 "10u" H 4575 2250 50  0000 L CNN
F 2 "" H 4588 2200 50  0000 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRT188R61E106ME13-01.pdf" H 4550 2350 50  0001 C CNN
F 4 "490-12323-1-ND" H 4550 2350 60  0001 C CNN "Digikey"
	1    4550 2350
	1    0    0    -1  
$EndComp
Text HLabel 5800 1950 2    60   Output ~ 0
LED_R_P
Text HLabel 5800 2100 2    60   Output ~ 0
LED_R_N
$Comp
L R R?
U 1 1 5837C430
P 4850 2600
F 0 "R?" V 4930 2600 50  0000 C CNN
F 1 "0.1R" V 4850 2600 50  0000 C CNN
F 2 "" V 4780 2600 50  0000 C CNN
F 3 "http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RU_Series_ds.pdf" H 4850 2600 50  0001 C CNN
F 4 "1276-6155-1-ND" V 4850 2600 60  0001 C CNN "Digikey"
	1    4850 2600
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5837C437
P 5600 2600
F 0 "C?" H 5625 2700 50  0000 L CNN
F 1 "22n" H 5625 2500 50  0000 L CNN
F 2 "" H 5638 2450 50  0000 C CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/mlcc_highreliability_general_en.pdf" H 5600 2600 50  0001 C CNN
F 4 "445-8118-1-ND" H 5600 2600 60  0001 C CNN "Digikey"
	1    5600 2600
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5837C43E
P 5250 2400
F 0 "R?" V 5330 2400 50  0000 C CNN
F 1 "4.7k" V 5250 2400 50  0000 C CNN
F 2 "" V 5180 2400 50  0000 C CNN
F 3 "http://www.yageo.com.tw/exep/pages/download/literatures/PYu-R_INT-thick_7.pdf" H 5250 2400 50  0001 C CNN
F 4 "311-4.7KGRCT-ND" V 5250 2400 60  0001 C CNN "Digikey"
	1    5250 2400
	0    1    1    0   
$EndComp
Wire Wire Line
	950  1100 3200 1100
Wire Wire Line
	2600 1200 2600 1100
Connection ~ 2600 1100
Wire Wire Line
	2600 1500 2600 2300
Wire Wire Line
	2600 1650 2650 1650
Wire Wire Line
	2950 1450 2950 1100
Connection ~ 2950 1100
Wire Wire Line
	2950 1850 3400 1850
Wire Wire Line
	3400 1400 3400 1900
Connection ~ 3400 1850
Wire Wire Line
	3400 2250 3400 2200
Wire Wire Line
	1650 2500 1850 2500
Wire Wire Line
	2150 2500 2300 2500
Wire Wire Line
	1850 2200 1800 2200
Wire Wire Line
	1800 2200 1800 2500
Connection ~ 1800 2500
Wire Wire Line
	2150 2200 2200 2200
Wire Wire Line
	2200 2200 2200 2500
Connection ~ 2200 2500
Connection ~ 2600 1650
Wire Wire Line
	2600 2250 3400 2250
Wire Wire Line
	3750 1950 3850 1950
Connection ~ 2600 2250
Wire Wire Line
	4550 2200 4550 1950
Connection ~ 4550 1950
Wire Wire Line
	3750 2500 3750 2800
Wire Wire Line
	2600 2800 5600 2800
Wire Wire Line
	2600 2800 2600 2700
Wire Wire Line
	4550 2800 4550 2500
Connection ~ 3750 2800
Connection ~ 4550 2800
Wire Wire Line
	4850 2800 4850 2750
Wire Wire Line
	4450 1950 5800 1950
Wire Wire Line
	3750 1100 3750 2200
Connection ~ 3750 1950
Wire Wire Line
	3600 1100 3750 1100
Wire Wire Line
	5800 2100 4850 2100
Wire Wire Line
	4850 2100 4850 2450
Wire Wire Line
	5100 2400 4850 2400
Connection ~ 4850 2400
Wire Wire Line
	5400 2400 5800 2400
Wire Wire Line
	5600 2400 5600 2450
Connection ~ 4850 2800
Wire Wire Line
	5600 2800 5600 2750
Text HLabel 5800 2400 2    60   Output ~ 0
OPAMP_R
Connection ~ 5600 2400
$Comp
L Q_NPN_BCE Q?
U 1 1 5837C473
P 2500 2500
F 0 "Q?" H 2800 2500 50  0000 R CNN
F 1 "Q_NPN_BCE" H 3100 2450 50  0001 R CNN
F 2 "" H 2700 2600 50  0000 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MMBT3904(SOT-23).pdf" H 2500 2500 50  0001 C CNN
F 4 "MMBT3904TPMSCT-ND" H 3200 2450 60  0001 C CNN "Digikey"
	1    2500 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 3150 1050 5350
Wire Wire Line
	1050 3200 1050 1100
Connection ~ 1050 1100
Connection ~ 1050 3200
NoConn ~ 7900 3350
$EndSCHEMATC
