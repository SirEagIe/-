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
	
	;Сравниваем R16 и R17
	CP R16, R17
	BRPL more
	BRMI less
	;Если R16 больше, чем R17
more:
	SUB R16, R17	;Выводим в порт B
	OUT PORTB, R16	;разность R16 и R17
	RJMP start
	;Если R16 меньше, чем R17
less:
	NOP	;Ничего не делаем
	RJMP start