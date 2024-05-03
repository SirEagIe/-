code SEGMENT					;Открыть сегмент кодов
	ASSUME CS:code, DS: data	;Назначить сегментные регистры
begin:
	mov AX, data			;Инициализировать
	mov DS, AX				;сегментный регистр DS
	mov AH, 09h				;Вывести строку Greet
	mov DX, OFFSET Greet	;на экран с помощью
	int 21h					;DOS
	mov DX, OFFSET MyName	;строку MyName
	int 21h					;на экран с помощью DOS
	mov DX, OFFSET MyGroup	;строку MyGroup
	int 21h					;на экран с помощью DOS
	mov AH, 4Ch				;Завершить программу
	mov AL, 0				;с помощью
	int 21h					;DOS
code ENDS					;Закрыть сегмент кодов

data SEGMENT				;Открыть сегмент данных
	Greet DB 'Hello, My friends!', 13, 10, '$'	;Определить строку символов с именем Greet
	MyName DB 'My name is Egor', 13, 10, '$'	;Определить строку символов с именем MyName
	MyGroup DB 'My group is KB-91', 13, 10, '$'	;Определить строку символов с именем MyGroup
data ENDS					;Закрыть сегмент данных

stk	 SEGMENT stack			;Открыть сегмент стека
	DB 100h DUP(?)			;Отвести под стек 256 байт
stk	ENDS					;Закрыть сегмент стека
END begin					;Конец исходного модуля