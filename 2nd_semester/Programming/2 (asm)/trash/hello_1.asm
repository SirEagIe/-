;ProgramHello_1 - ��� ��ࢠ� �ணࠬ��
ASSUME CS:Code, DS:Data, SS:Ourstack	;�������� ᥣ����� ॣ�����

Code SEGMENT	;������ ᥣ���� �����
Start:
	mov AX, Data	;���樠����஢���
	mov DS, AX	;ᥣ����� ॣ���� DS
	mov AH, 09h	;�뢥�� ��ப� Greet
	mov DX, OFFSET Greet	;�� �࠭ ᯮ�����
	int 21h	;DOS
	mov AL, 0	;�������� �ணࠬ��
	mov AH, 4Ch	;� �������
	int 21h	;DOS
Code ENDS	;������� ᥣ���� �����

Data SEGMENT	;������ ᥣ���� ������
	Greet DB 'Hello, My friends!', 13, 10, '$'	;��।����� ��ப� ᨬ����� � ������ Greet
Data ENDS	;������� ᥣ���� ������

Ourstack SEGMENT Stack	;������ ᥣ���� �⥪�
	DB 100h DUP (?)	;�⢥�� ��� �⥪ 256 ����
Ourstack ENDS	;������� ᥣ���� �⥪�

END Start	;����� ��室���� �����