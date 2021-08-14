EESchema Schematic File Version 4
LIBS:stellarbox-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 6
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
L Device:R R18
U 1 1 5B9E19F5
P 2900 1750
F 0 "R18" V 2693 1750 50  0000 C CNN
F 1 "3.9K" V 2784 1750 50  0000 C CNN
F 2 "" V 2830 1750 50  0001 C CNN
F 3 "~" H 2900 1750 50  0001 C CNN
	1    2900 1750
	0    1    1    0   
$EndComp
$Comp
L Device:R R19
U 1 1 5B9E1A53
P 3750 2000
F 0 "R19" H 3820 2046 50  0000 L CNN
F 1 "1.3K" H 3820 1955 50  0000 L CNN
F 2 "" V 3680 2000 50  0001 C CNN
F 3 "~" H 3750 2000 50  0001 C CNN
	1    3750 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Zener D9
U 1 1 5B9E1B1E
P 3300 2000
F 0 "D9" V 3254 2079 50  0000 L CNN
F 1 "5.1V" V 3345 2079 50  0000 L CNN
F 2 "" H 3300 2000 50  0001 C CNN
F 3 "~" H 3300 2000 50  0001 C CNN
	1    3300 2000
	0    1    1    0   
$EndComp
Wire Wire Line
	3050 1750 3300 1750
Wire Wire Line
	3750 1750 3750 1850
Wire Wire Line
	3300 1850 3300 1750
Connection ~ 3300 1750
Wire Wire Line
	3300 1750 3750 1750
Wire Wire Line
	3300 2150 3500 2150
Wire Wire Line
	3750 1750 4150 1750
Connection ~ 3750 1750
Text HLabel 2500 1750 0    50   Input ~ 0
INPUT_VOLTAGE
Text HLabel 4150 1750 2    50   Input ~ 0
VOLTAGE_MEASURE
Wire Wire Line
	2500 1750 2750 1750
$Comp
L power:GND #PWR018
U 1 1 5B9E1C92
P 3500 2250
F 0 "#PWR018" H 3500 2000 50  0001 C CNN
F 1 "GND" H 3505 2077 50  0000 C CNN
F 2 "" H 3500 2250 50  0001 C CNN
F 3 "" H 3500 2250 50  0001 C CNN
	1    3500 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 2250 3500 2150
Connection ~ 3500 2150
Wire Wire Line
	3500 2150 3750 2150
$EndSCHEMATC