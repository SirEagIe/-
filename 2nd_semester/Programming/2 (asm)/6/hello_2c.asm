.MODEL TINY					;Модель памяти ближнего типа
.Code						;Открыть сегмент кодов
ORG 100h					;Отвести 256 байт под PSP
Begin: jmp Start			;Безусловный переход на первую команду
	Greet DB 'Hello, My friends!', 13, 10, '$'	;Определить строку символов с именем Greet
	MyName DB 'My name is Egor', 13, 10, '$'	;Определить строку символов с именем MyName
	MyGroup DB 'My group is KB-91', 13, 10, '$'	;Определить строку символов с именем MyGroup
Start:
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
END Begin					;Конец исходного модуля