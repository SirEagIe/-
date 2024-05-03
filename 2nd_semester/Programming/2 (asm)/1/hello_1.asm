code SEGMENT					;Открыть сегмент кодов
	ASSUME CS:code, DS: data	;Назначить сегментные регистры
begin:
	mov AX, data			;Инициализировать
	mov DS, AX				;сегментный регистр DS
	mov AH, 09h				;Вывести строку Greet
	mov DX, OFFSET Greet	;на экран с помощью
	int 21h					;DOS
	mov AH, 4Ch				;Завершить программу
	mov AL, 0				;с помощью
	int 21h					;DOS
code ENDS					;Закрыть сегмент кодов

data SEGMENT				;Открыть сегмент данных
	Greet DB 'Hello, My friends!', 13, 10, '$'	;Определить строку символов с именем Greet
data ENDS					;Закрыть сегмент данных

stk	 SEGMENT stack			;Открыть сегмент стека
	DB 100h DUP(?)			;Отвести под стек 256 байт
stk	ENDS					;Закрыть сегмент стека
END begin					;Конец исходного модуля