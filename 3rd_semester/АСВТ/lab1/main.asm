start:
	;Настройка PORTA на вход
	LDI R16, 0
	OUT DDRA, R16
	;Настройка PORTB на выход
	LDI R16, 255
	OUT DDRB, R16

	IN R16, PINA	;Считывание PINA в R16
	SBRS R16, 7	;Если PINA.7 не установлен,
	RJMP metka1 ;переходим по метке metka1
	LDI R17, 1	;Иначе загружаем в R17 число 1
	SUB R16, R17	;Вычитаем из R16 R17
	OUT PORTB, R16	;Выводим на порт B R16
	RJMP start	;Переходим на метку start
metka1:
	NOP	;холостая команда
	RJMP start	;Переходим на метку start