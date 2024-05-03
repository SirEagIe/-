start:
	;Настройка PORTA на вход
	LDI R16, 0
	OUT DDRA, R16
	;Настройка PORTB на выход
	LDI R16, 255
	OUT DDRB, R16
	
enter1: ;Считывание PINA в R16
	IN R16, PINA
	SBRS R16, 7
	RJMP enter1 ;Если PINA.7 не установлен, повторное считывание
	ANDI R16, 127
	
enter2: ;Считывание PINA в R17
	IN R17, PINA
	SBRC R17, 7
	RJMP enter2 ;Если PINA.7 не сброшен, повторное считывание
	
enter3: ;Считывание PINA в R17
	IN R17, PINA
	SBRS R17, 7
	RJMP enter3 ;Если PINA.7 не установлен, повторное считывание
	ANDI R17, 127
	
enter4: ;Считывание PINA в R18
	IN R18, PINA
	SBRC R18, 7
	RJMP enter4 ;Если PINA.7 не установлен, повторное считывание
	
	MOV R18, R16 ;Записываем в R18
	ADD R18, R17 ;сумму R16 и R17
	
	MOV R19, R16 ;Записываем в R19
	SUB R19, R17 ;разность R16 и R17
	
	MOV R20, R18 ;Вычисляем исключающее ИЛИ
	EOR R20, R19 ;суммы и разности R16 и R17
	
	OUT PORTB, R20 ;Вывод результата в прот B
	
	RJMP start