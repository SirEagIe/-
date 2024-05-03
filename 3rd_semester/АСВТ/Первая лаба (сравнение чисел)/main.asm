	;������ � R3 ����� 127
	LDI R16, 127
	MOV R3, R16
	;������ � R4 ����� 63
	LDI R16, 63
	MOV R4, R16
	;��������� ����� 7, 3, 2, 1, 0 PORTA �� ����
	LDI R16, 0b01110000
	OUT DDRA, R16
	;��������� PORTB �� �����
	LDI R16, 255
	OUT DDRB, R16
	;���������� PINA � R0
enter1:
	IN R16, PINA
	MOV R0, R16
	LDI R16, 0b10000000
	CP R0, R16
	BRMI enter1 ;���� PINA.7 �� �������, ��������� ����������
	;������ R0 � R1
	MOV R1, R0
	;���������� � R1 � 15
	LDI R16, 15
	AND R1, R16
	;���������� PINA � R0
enter2:
	IN R16, PINA
	MOV R0, R16
	LDI R16, 0b10000000
	CP R0, R16
	BRPL enter2 ;���� PINA.7 �� ����������, ��������� ����������
	;���������� PINA � R0
enter3:
	IN R16, PINA
	MOV R0, R16
	LDI R16, 0b10000000
	CP R0, R16
	BRMI enter3 ;���� PINA.7 �� �������, ��������� ����������
	;������ R0 � R2
	MOV R2, R0
	;���������� � R2 c 15 
	LDI R16, 15
	AND R2, R16
	;���������� R2-R1
	CP R2, R1
	BRPL plus
	BRMI minus
	;���� ��������� �������������, ����� � PORTB R4
plus:
	OUT PORTB, R4
	JMP exit
	;���� ��������� �������������, ����� � PORTB R3
minus:
	OUT PORTB, R3
	JMP exit
exit:
	NOP