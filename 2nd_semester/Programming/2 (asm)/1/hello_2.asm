code SEGMENT					;������� ������� �����
	ASSUME CS:code, DS: data	;��������� ���������� ��������
begin:
	mov AX, data			;����������������
	mov DS, AX				;���������� ������� DS
	mov AH, 09h				;������� ������ Greet
	mov DX, OFFSET Greet	;�� ����� � �������
	int 21h					;DOS
	mov DX, OFFSET MyName	;������ MyName
	int 21h					;�� ����� � ������� DOS
	mov DX, OFFSET MyGroup	;������ MyGroup
	int 21h					;�� ����� � ������� DOS
	mov AH, 4Ch				;��������� ���������
	mov AL, 0				;� �������
	int 21h					;DOS
code ENDS					;������� ������� �����

data SEGMENT				;������� ������� ������
	Greet DB 'Hello, My friends!', 13, 10, '$'	;���������� ������ �������� � ������ Greet
	MyName DB 'My name is Egor', 13, 10, '$'	;���������� ������ �������� � ������ MyName
	MyGroup DB 'My group is KB-91', 13, 10, '$'	;���������� ������ �������� � ������ MyGroup
data ENDS					;������� ������� ������

stk	 SEGMENT stack			;������� ������� �����
	DB 100h DUP(?)			;������� ��� ���� 256 ����
stk	ENDS					;������� ������� �����
END begin					;����� ��������� ������