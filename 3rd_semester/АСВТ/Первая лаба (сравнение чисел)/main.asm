	;Запись в R3 число 127
	LDI R16, 127
	MOV R3, R16
	;Запись в R4 число 63
	LDI R16, 63
	MOV R4, R16
	;Настройка ножек 7, 3, 2, 1, 0 PORTA на вход
	LDI R16, 0b01110000
	OUT DDRA, R16
	;Настройка PORTB на выход
	LDI R16, 255
	OUT DDRB, R16
	;Считывание PINA в R0
enter1:
	IN R16, PINA
	MOV R0, R16
	LDI R16, 0b10000000
	CP R0, R16
	BRMI enter1 ;Если PINA.7 не сброшен, повторное считывание
	;Запись R0 в R1
	MOV R1, R0
	;Логическое И R1 с 15
	LDI R16, 15
	AND R1, R16
	;Считывание PINA в R0
enter2:
	IN R16, PINA
	MOV R0, R16
	LDI R16, 0b10000000
	CP R0, R16
	BRPL enter2 ;Если PINA.7 не установлен, повторное считывание
	;Считывание PINA в R0
enter3:
	IN R16, PINA
	MOV R0, R16
	LDI R16, 0b10000000
	CP R0, R16
	BRMI enter3 ;Если PINA.7 не сброшен, повторное считывание
	;Запись R0 в R2
	MOV R2, R0
	;Логическое И R2 c 15 
	LDI R16, 15
	AND R2, R16
	;Вычисление R2-R1
	CP R2, R1
	BRPL plus
	BRMI minus
	;Если результат положительный, вывод в PORTB R4
plus:
	OUT PORTB, R4
	JMP exit
	;Если результат отрицательный, вывод в PORTB R3
minus:
	OUT PORTB, R3
	JMP exit
exit:
	NOP