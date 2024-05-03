/**************************************************
                   Vector table
**************************************************/
.org 0x0000			rjmp Reset
.org INT0addr		RETI
.org INT1addr		RETI
.org OC2addr		RETI
.org OVF2addr		RETI
.org ICP1addr		RETI
.org OC1Aaddr		RETI
.org OC1Baddr		RETI
.org OVF1addr		RETI
.org OVF0addr		RETI
.org SPIaddr		RETI	
.org URXCaddr		RETI
.org UDREaddr		RETI
.org UTXCaddr		RETI
.org ADCCaddr		RETI
.org ERDYaddr		RETI
.org ACIaddr		RETI
.org TWIaddr		RETI
.org INT2addr		RETI
.org OC0addr		rjmp Timer0_int_handl
.org SPMRaddr		RETI

Reset:
	;Инициализация стека
	LDI R18, low(RAMEND)
	OUT SPL, R18
	LDI R19, high(RAMEND)
	OUT SPH, R19
	;Настройка порта B на выход
	LDI R16, 255
	OUT DDRB, R16
	;Разрешить прерывания локально от таймера/счётчика T0 по сравнению 
	LDI R18, 0b00000010
	OUT TIMSK, R18
	;Настройка предделителя на каждый 64й сигнал
	LDI R18, 0b00000011
	OUT TCCR0, R18
	;Загрузка в регистр сравнения 211
	LDI R19, 211
	OUT OCR0, R19
	;Разрешить глобально прерывания
	SEI

	LDI R20, 0		;Загрузить в R20 число 0 (счётчик количества выведенных букв)
	LDI R21, 0		;Загрузить в R21 число 0 (счётчик количества миганий)
	LDI R17, 255	;Загрузить в R17 число 255 (то, при помощи чего будет происходить инверсия)

start:
	CPI R21, 6	;Если произошло 6 инверсий
	BRNE start
	LDI R21, 0	;Сбросить регистр R21
	INC R20		;Увеличить количество выведенных букв на 1
	CPI R20, 3	;Если букв выведено 3
	BREQ metka	;Не изменяем настройки и переходим к метке metka
	IN R18, TCCR0	;Изменение настройки предделителя
	LDI R19, 0b00000110	;Если настроен на каждый 64й сигнал,
	EOR R18, R19	;изменить на каждый 1024й сигнал
	OUT TCCR0, R18	;и наоборот
	RJMP start
metka:
	LDI R20, 0	;Очистить регистр R20
	RJMP start	;Перейти к метке start

Timer0_int_handl:
	IN R16, PORTB
	EOR R16, R17	;Инвентировать R16
	OUT PORTB, R16	;Вывести R16 в порт B
	INC R21	;Увеличить R21 на 1
	RETI
