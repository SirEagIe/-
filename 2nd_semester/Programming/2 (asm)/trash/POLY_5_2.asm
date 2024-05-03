TITLE POLINOM
;�ணࠬ�� ���᫥��� �������� ���� Y=a1*X^n+a2*X^(n-1)+...+an*X+an+1
;�室�� ��ࠬ����:
;�����業�� �������� ai � ���ᨢ� MAS_A
;���冷� �������� N
;��㬥�� �������� X
;��室�� ��ࠬ����: 
;���᫥���� ���祭�� �������� Y
;ᮮ�饭�� MES_1, MES_2, MES_3, MES_Y
.MODEL SMALL	;������ ����� �������� ⨯�
.DATA	;������ ᥣ���� ������
	MAS_A DW -3, 9, 5, 1, 2	;�����業�� ��������
	N DW 4	;���冷� �������� ࠢ�� 4
	X DW 10	;��㬥�� �������� ࠢ�� 10
	Y DW (?)	;������� ���᫥��� ��������
	MES_1 DB 'Overflow', 13, 10, '$'	;����饭�� MES_1
	MES_2 DB 'Result minus', 13, 10, '$'	;����饭�� MES_2
	MES_3 DB 'Result plus', 13, 10, '$'	;����饭�� MES_3
	MES_Y DB 'Y=-3*10^4+9*10^3+5*10^2+1*10^1+2*10^0', 13, 10, '$'	;��ப� � ���������
.STACK 100h	;�⢥�� ��� �⥪ 256 ����
.Code	;������ ᥣ���� �����
Output PROC	;����� ��楤��� � ������ Output
	mov DX, BX	;�뢥�� �� �࠭
	mov AH, 09	;��ப�, ᬥ饭�� ���ன ��室���� � ॣ���� BX,
	int 21h	;� ������� DOS
	ret	;������ �� ��楤���
Output ENDP	;�������� ��楤��� � ������ Output

Start:
	mov AX, @DATA	;���樠���஢���
	mov DS, AX	;ᥣ����� ॣ���� DS
	lea SI, MAS_A	;����㧨�� � SI ��砫�� ���� ���ᨢ� MAS_A
	mov CX, N	;�������� � CX ���祭�� ��६����� N
	xor DX, DX	;������ ॣ���� DX
	mov AX, [SI]	;�������� � AX ���� ����� ����� ���ᨢ�
	mov BX, offset MES_1	;�������� � BX ᬥ饭�� ��ப� MES_2
M_1:
	imul X	;�������� ���祭�� � ॣ���� AX �� ���祭�� ��६����� X
	jo Result	;�� �᫮��� ��९������� ��३� � ��⪥ Result
	inc SI	;�����祭�� ������
	inc SI	;�� 2
	add AX, [SI]	;�������� � ���祭�� AX ����� ���ᨢ�
	jo Result	;�� �᫮��� ��९������� ��३� � ��⪥ Result
	loop M_1	;�������� ���祭�� CX �� 1, ��३� � ��⪥ M_1, �᫨ ���祭�� CX �� ࠢ�� 0
	mov Y, AX	;�������� ���祭�� AX � ��६����� Y
	cmp AX, 0	;�ࠢ���� AX � 0
	mov BX, offset MES_3	;�᫨ AX ����� ��� �������� � BX ᬥ饭�� ��ப� MES_3
	jge Result	;� ��३� � ��⪥ Result
	mov BX, offset MES_2	;���� - �������� � BX ᬥ饭�� ��ப� MES_2
	jmp Result	;� ��३� � ��⪥ Result
Result:
	call Output	;�맢��� ��楤��� Output
	mov BX, offset MES_Y	;�������� � BX ᬥ饭�� ��ப� MES_Y
	call Output	;�맢��� ��楤��� Output
	mov AL, 0	;��������
	mov AH, 4Ch	;�ணࠬ��
	int 21h	;� ������� DOS
END Start	;����� ��室���� �����