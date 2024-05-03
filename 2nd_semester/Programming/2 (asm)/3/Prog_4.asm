;Prog_4 - ��䬥��᪨� ����樨, ��ਠ�� 5
Code SEGMENT			;������ ᥣ���� �����
ASSUME CS: Code, DS: Data, SS: Outstack	;�������� ᥣ����� ॣ�����
Start:
	MOV AX, Data		;���樠����஢���
	MOV DS, AX			;�������� ॣ���� DS
	XOR AX, AX			;������ ॣ���� AX
	MOV AL, A			;������� ���祭�� ��६������ A � ����訩 ���� ॣ���� AX
	MOV AH, 03h			;������� ���祭�� 03h � ���訩 ���� ॣ���� AX
	IMUL AH				;������� � AX १���� 㬭������ ���祭�� � AL � � AH (AX := (AL) * (AH))
	ADD AX, 48			;������� � AX १���� ᫮����� ���祭�� � AX � 48 (AX := (AX) + 48)
	MOV BX, AX			;������� ���祭�� AX (48+3*A) � BX
	MOV AH, 0			;������� � ���訩 ���� AX 00h
	MOV AL, B			;������� � ����訩 ���� AX ���祭�� ��६����� B
	MOV CL, C			;������� � ����訩 ���� CX ���祭�� ��६����� C
	IDIV CL				;������� � AL १���� ������� ���祭�� � AX � � CL (AL := quot((AX)/(CL)))
	MOV CL, D			;������� � ����訩 ���� CX ���祭�� ��६����� D
	IMUL CL				;������� � AX १���� 㬭������ ���祭�� � AL � � CL (AX := (AL) * (CL))
	SUB BX, AX			;������� � BX १���� ���⠭�� �� ���祭�� � BX ���祭�� � AX (BX := (BX)-(AX))
	MOV X, BX			;������� � ��६����� X ���祭�� BX
	MOV AX, 4C00h		;�������� �ணࠬ��
	INT 21h				;� ������� DOS
Code ENDS				;������� ᥣ���� �����

Data SEGMENT			;������ ᥣ���� ������
	A DB 5Ah			;���樠����஢���
	B DB 55h			;��६���� A, B, C, D, X
	C DB 11h
	D DB 2
	X DW ?
Data ENDS				;������� ᥣ���� ������

Outstack SEGMENT Stack	;������ ᥣ���� �⥪�
	DB 100h DUP(?)		;�⢥�� ��� �⥪ 256 ����
Outstack ENDS			;������� ᥣ���� �⥪�

END Start				;����� ��室���� �����