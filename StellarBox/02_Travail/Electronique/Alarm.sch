EESchema Schematic File Version 4
LIBS:stellarbox-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Reference_Voltage:REF3030 U7
U 1 1 5B9E39FC
P 3700 2250
F 0 "U7" H 3470 2296 50  0000 R CNN
F 1 "REF3030" H 3470 2205 50  0000 R CIN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3700 1800 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/symlink/ref3033.pdf" H 3800 1900 50  0001 C CIN
	1    3700 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 5B9E3A78
P 2600 2300
F 0 "C8" H 2715 2346 50  0000 L CNN
F 1 "2.2µF" H 2715 2255 50  0000 L CNN
F 2 "" H 2638 2150 50  0001 C CNN
F 3 "~" H 2600 2300 50  0001 C CNN
	1    2600 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 1950 2600 1950
Wire Wire Line
	2600 1950 2600 2150
Wire Wire Line
	2600 2450 2600 2700
Wire Wire Line
	3600 2700 3600 2550
$Comp
L power:GND #PWR0123
U 1 1 5B9E3B79
P 3600 2800
F 0 "#PWR0123" H 3600 2550 50  0001 C CNN
F 1 "GND" H 3605 2627 50  0000 C CNN
F 2 "" H 3600 2800 50  0001 C CNN
F 3 "" H 3600 2800 50  0001 C CNN
	1    3600 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 2700 3600 2800
Connection ~ 3600 2700
$Comp
L power:+5V #PWR0124
U 1 1 5B9E3BE0
P 2600 1950
F 0 "#PWR0124" H 2600 1800 50  0001 C CNN
F 1 "+5V" H 2615 2123 50  0000 C CNN
F 2 "" H 2600 1950 50  0001 C CNN
F 3 "" H 2600 1950 50  0001 C CNN
	1    2600 1950
	1    0    0    -1  
$EndComp
Connection ~ 2600 1950
$Comp
L Device:C C12
U 1 1 5B9E3BF6
P 4300 2450
F 0 "C12" H 4415 2496 50  0000 L CNN
F 1 "4.7µF" H 4415 2405 50  0000 L CNN
F 2 "" H 4338 2300 50  0001 C CNN
F 3 "~" H 4300 2450 50  0001 C CNN
	1    4300 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 5B9E3C76
P 4800 2450
F 0 "C13" H 4915 2496 50  0000 L CNN
F 1 "0.1µF" H 4915 2405 50  0000 L CNN
F 2 "" H 4838 2300 50  0001 C CNN
F 3 "~" H 4800 2450 50  0001 C CNN
	1    4800 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2300 4800 2250
Wire Wire Line
	4300 2300 4300 2250
Wire Wire Line
	4000 2250 4300 2250
Connection ~ 4300 2250
Wire Wire Line
	4300 2250 4800 2250
Connection ~ 4800 2250
Wire Wire Line
	4800 2250 4800 1950
Wire Wire Line
	3600 2700 4300 2700
Wire Wire Line
	4800 2700 4800 2600
Wire Wire Line
	4300 2700 4300 2600
Connection ~ 4300 2700
Wire Wire Line
	4300 2700 4800 2700
Text HLabel 3350 3550 1    50   Input ~ 0
Y_OUT
Text HLabel 2900 3550 1    50   Input ~ 0
X_OUT
Text HLabel 3800 3550 1    50   Input ~ 0
Z_OUT
$Comp
L Device:C C10
U 1 1 5B9E4092
P 3350 3700
F 0 "C10" H 3465 3746 50  0000 L CNN
F 1 "0.1µF" H 3465 3655 50  0000 L CNN
F 2 "" H 3388 3550 50  0001 C CNN
F 3 "~" H 3350 3700 50  0001 C CNN
	1    3350 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C9
U 1 1 5B9E40F8
P 2900 3700
F 0 "C9" H 3015 3746 50  0000 L CNN
F 1 "0.1µF" H 3015 3655 50  0000 L CNN
F 2 "" H 2938 3550 50  0001 C CNN
F 3 "~" H 2900 3700 50  0001 C CNN
	1    2900 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 5B9E411C
P 3800 3700
F 0 "C11" H 3915 3746 50  0000 L CNN
F 1 "0.1µF" H 3915 3655 50  0000 L CNN
F 2 "" H 3838 3550 50  0001 C CNN
F 3 "~" H 3800 3700 50  0001 C CNN
	1    3800 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0126
U 1 1 5B9E43DC
P 3350 4050
F 0 "#PWR0126" H 3350 3800 50  0001 C CNN
F 1 "GND" H 3355 3877 50  0000 C CNN
F 2 "" H 3350 4050 50  0001 C CNN
F 3 "" H 3350 4050 50  0001 C CNN
	1    3350 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 3850 3350 3850
Connection ~ 3350 3850
Wire Wire Line
	3350 3850 3800 3850
Wire Wire Line
	3350 3850 3350 4050
$Comp
L SparkFun-Sensors:ADXL335 U8
U 1 1 5B9E48EA
P 7050 2250
F 0 "U8" H 7050 2815 50  0000 C CNN
F 1 "ADXL335" H 7050 2724 50  0000 C CNN
F 2 "LFCSP-16" H 7080 2400 20  0001 C CNN
F 3 "" H 7050 2250 50  0001 C CNN
	1    7050 2250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0127
U 1 1 5B9E4988
P 6250 2550
F 0 "#PWR0127" H 6250 2300 50  0001 C CNN
F 1 "GND" V 6255 2422 50  0000 R CNN
F 2 "" H 6250 2550 50  0001 C CNN
F 3 "" H 6250 2550 50  0001 C CNN
	1    6250 2550
	0    1    1    0   
$EndComp
Wire Wire Line
	6400 2250 6550 2250
Wire Wire Line
	6400 2550 6550 2550
Wire Wire Line
	6550 2450 6400 2450
Connection ~ 6400 2450
Wire Wire Line
	6400 2450 6400 2550
Wire Wire Line
	6550 2350 6400 2350
Connection ~ 6400 2350
Wire Wire Line
	6400 2350 6400 2250
Wire Wire Line
	6250 2550 6400 2550
Connection ~ 6400 2550
Wire Wire Line
	6400 2350 6400 2450
Wire Wire Line
	6550 2050 6400 2050
Wire Wire Line
	6400 2050 6400 1950
Connection ~ 6400 1950
Wire Wire Line
	6400 1950 6550 1950
Text HLabel 7800 2050 2    50   Input ~ 0
Y_OUT
Text HLabel 7800 1950 2    50   Input ~ 0
X_OUT
Text HLabel 7800 2150 2    50   Input ~ 0
Z_OUT
Wire Wire Line
	7550 1950 7800 1950
Wire Wire Line
	7550 2050 7800 2050
Wire Wire Line
	7550 2150 7800 2150
NoConn ~ 7550 2550
Wire Wire Line
	2600 2700 3600 2700
Wire Wire Line
	6250 1950 6400 1950
$Comp
L power:+3V3 #PWR0128
U 1 1 5B9E5332
P 6250 1950
F 0 "#PWR0128" H 6250 1800 50  0001 C CNN
F 1 "+3V3" V 6265 2078 50  0000 L CNN
F 2 "" H 6250 1950 50  0001 C CNN
F 3 "" H 6250 1950 50  0001 C CNN
	1    6250 1950
	0    -1   -1   0   
$EndComp
$Comp
L power:+3V3 #PWR0125
U 1 1 5B9E3D0D
P 4800 1950
F 0 "#PWR0125" H 4800 1800 50  0001 C CNN
F 1 "+3V3" H 4815 2123 50  0000 C CNN
F 2 "" H 4800 1950 50  0001 C CNN
F 3 "" H 4800 1950 50  0001 C CNN
	1    4800 1950
	1    0    0    -1  
$EndComp
$EndSCHEMATC