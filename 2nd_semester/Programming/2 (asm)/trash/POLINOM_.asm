TITLE POLINOM
;�ணࠬ�� ���᫥��� �������� ���� Y=a1*X^n+a2*X^(n-1)+...+an*X+an+1
;�室�� ��ࠬ����:
;�����業�� �������� ai � ���ᨢ� MAS_A
;���冷� �������� N
;��㬥�� �������� X
;��室�� ��ࠬ����: 
;���᫥���� ���祭�� �������� Y
;ᮮ�饭�� MES_1, MES_2, MES_3
.MODEL SMALL	;������ ����� �������� ⨯�
.DATA	;������ ᥣ���� ������
	MAS_A DW -3, 3, -6, 9, -20	;�����業�� ��������
	N DW 4	;���冷� �������� ࠢ�� 4
	X DW 10	;��㬥�� �������� ࠢ�� 10
	Y DW (?)	;������� ���᫥��� ��������
	MES_1 DB 'Overflow', 13, 10, '$'	;����饭�� MES_1
	MES_2 DB 'Result minus', 13, 10, '$'	;����饭�� MES_2
	MES_3 DB 'Result plus', 13, 10, '$'	;����饭�� MES_3
.STACK 100h	;�⢥�� ��� �⥪ 256 ����
.Code	;������ ᥣ���� �����
Start:
	mov AX, @DATA	;���樠���஢���
	mov DS, AX	;ᥣ����� ॣ���� DS
	lea SI, MAS_A	;����㧨�� � SI ��砫�� ���� ���ᨢ� MAS_A
	mov CX, N	;�������� � CX ���祭�� ��६����� N
	xor DX, DX	;������ ॣ���� DX
	mov AX, [SI]	;�������� � AX ���� ����� ����� ���ᨢ�
M_1:
	imul X	;�������� ���祭�� � ॣ���� AX �� ���祭�� ��६����� X
	jo mes1	;�� �᫮��� ��९������� ��३� � ��⪥ mes1
	inc SI	;�����祭�� ������
	inc SI	;�� 2
	add AX, [SI]	;�������� � ���祭�� AX ����� ���ᨢ�
	jo mes1	;�� �᫮��� ��९������� ��३� � ��⪥ mes1
	loop M_1	;�������� ���祭�� CX �� 1, ��३� � ��⪥ M_1, �᫨ ���祭�� CX �� ࠢ�� 0
	mov Y, AX	;�������� ���祭�� AX � ��६����� Y
	cmp AX, 0	;�ࠢ���� AX � 0
	jge mes3	;�᫨ AX ����� ��� ��३� � mes3
	mov DX, offset MES_2	;�뢥�� �� �࠭
	mov AH, 09	;ᮮ�饭�� MES_2
	int 21h	;� ������� DOS
Exit:
	mov AL, 0	;��������
	mov AH, 4Ch	;�ணࠬ��
	int 21h	;� ������� DOS
mes1:
	mov DX, offset MES_1	;�뢥�� �� �࠭
	mov AH, 09	;ᮮ�饭�� MES_1
	int 21h	;� ������� DOS
	jmp Exit	;��३� � ��⪥ Exit
mes3:
	mov DX, offset MES_3	;�뢥�� �� �࠭
	mov AH, 09	;ᮮ�饭�� MES_3
	int 21h	;� ������� DOS
	jmp Exit	;��३� � ��⪥ Exit
END Start	;����� ��室���� �����