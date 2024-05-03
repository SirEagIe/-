.MODEL SMALL				;Модель памяти ближнего типа
.CODE						;Открыть сегмент кодов
begin:
	mov AX, @DATA			;Инициализировать
	mov DS, AX				;сегментный регистр DS
	mov AH, 09h				;Вывести строку Greet
	mov DX, OFFSET Greet	;на экран с помощью
	int 21h					;DOS
	mov AH, 00h				;Пауза до
	int 16h					;нажатия клавиши
	mov AH, 09h				;Вывести строку MyName
	mov DX, OFFSET MyName	;на экран с помощью
	int 21h					;DOS
	mov AH, 00h				;Пауза до
	int 16h					;нажатия клавиши
	mov AH, 09h				;Вывести строку MyGroup
	mov DX, OFFSET MyGroup	;на экран с помощью
	int 21h					;DOS
	mov AH, 00h				;Пауза до
	int 16h					;нажатия клавиши
	mov AH, 4Ch				;Завершить программу
	mov AL, 0				;с помощью
	int 21h					;DOS
.DATA						;Открыть сегмент данных
	Greet DB 'Hello, My friends!', 13, 10, '$'	;Определить строку символов с именем Greet
	MyName DB 'My name is Egor', 13, 10, '$'	;Определить строку символов с именем MyName
	MyGroup DB 'My group is KB-91', 13, 10, '$'	;Определить строку символов с именем MyGroup
.STACK 100h					;Определить стек размером 100h
END begin					;Конец исходного модуля