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
	MAS_A DW -3, 9, 5, 1, 2	;�����業�� ��������
	N DW 4	;���冷� �������� ࠢ�� 4
	X DW 10	;��㬥�� �������� ࠢ�� 10
	Y DW (?)	;������� ���᫥��� ��������
	MES_1 DB 'Overflow', 13, 10, '$'	;����饭�� MES_1
	MES_2 DB 'Result minus', 13, 10, '$'	;����饭�� MES_2
	MES_3 DB 'Result plus', 13, 10, '$'	;����饭�� MES_3
	MES_Y DB 'Y=-3*10^4+9*10^3+5*10^2+1*10^1+2*10^0 = $'	;��ப� � ���������
	Sign DB (?)	;��६����� ��� �࠭���� ����� �᫠
	Y_ASCII DB 7 DUP(?)	;��६����� ��� �࠭���� ᨬ����� ASCII
.STACK 100h	;�⢥�� ��� �⥪ 256 ����
.CODE	;������ ᥣ���� �����
Preobr PROC	;����� ��楤��� � ������ Preobr
	mov AX, BX	;��६����� � AX ���筨� BX
	mov Sign, ' '	;�������� � ��६����� ����� ᨬ��� �஡��� (���� +)
	cmp AX, 0	;�ࠢ���� �᫮ � ���
	jns M_1	;�᫨ ����� ��� ࠢ�� 0, ��३� �� ���� M_1
	mov Sign, '-'	;���� �������� � ��६����� ����� ᨬ��� ����� (���� -)
	neg AX	;�८�ࠧ����� � ��אַ� ���
M_1:
	xor CX, CX	;������ CX
	mov BX, 10	;�������� � BX ����⥫� ࠢ�� 10
M_2:
	xor DX, DX	;������ DX
	div BX	;��������� �᫮ �� 10
	push DX	;���࠭��� ���⮪ � �⥪�
	inc CX	;�������� ���祭�� CX �� �������
	cmp AX, 0	;�ࠢ���� �᫮ � ���
	jne M_2	;�᫨ ����� ��� ࠢ�� 0, ������� �������
	xor SI, SI	;������ SI
	mov AL, Sign	;����㧨�� � AL ���� �᫠
	mov Y_ASCII[SI], AL	;���᫠�� ���� � Y_ASCII
	inc SI	;�������� SI �� �������
M_3:
	pop AX	;������� ᮤ�ন��� �⥪� � AX
	add AL, 30h	;���᫨�� ASCII ��� ��� ����
	mov Y_ASCII[SI], AL	;���᫥��� ASCII ��� � Y_ASCII
	inc SI	;�������� SI �� �������
	loop M_3	;�᫨ ᮤ�ন��� CX �� 0, ������� 横�
	mov Y_ASCII[SI], '$'	;�������� ᨬ��� ���� ��ப� � Y_ASCII
	ret	;������ �� ��楤���
Preobr ENDP	;�������� ��楤��� � ������ Preobr

Output PROC	;����� ��楤��� � ������ Output
	mov DX, BX	;�뢥�� �� �࠭
	mov AH, 09	;��ப�, ᬥ饭�� ���ன ��室���� � ॣ���� BX,
	int 21h	;� ������� DOS
	ret	;������ �� ��楤���
Output ENDP	;�������� ��楤��� � ������ Output

Polinom PROC	;����� ��楤��� � ������ Polinom
	lea SI, MAS_A	;����㧨�� � SI ��砫�� ���� ���ᨢ� MAS_A
	mov CX, N	;�������� � CX ���祭�� ��६����� N
	xor DX, DX	;������ ॣ���� DX
	mov AX, [SI]	;�������� � AX ���� ����� ����� ���ᨢ�
	mov BX, offset MES_1	;�������� � BX ᬥ饭�� ��ப� MES_2
M:
	imul X	;�������� ���祭�� � ॣ���� AX �� ���祭�� ��६����� X
	jo Result	;�� �᫮��� ��९������� ��३� � ��⪥ Result
	inc SI	;�����祭�� ������
	inc SI	;�� 2
	add AX, [SI]	;�������� � ���祭�� AX ����� ���ᨢ�
	jo Result	;�� �᫮��� ��९������� ��३� � ��⪥ Result
	loop M	;�������� ���祭�� CX �� 1, ��३� � ��⪥ M, �᫨ ���祭�� CX �� ࠢ�� 0
	mov Y, AX	;�������� ���祭�� AX � ��६����� Y
	cmp AX, 0	;�ࠢ���� AX � 0
	mov BX, offset MES_3	;�᫨ AX ����� ��� �������� � BX ᬥ饭�� ��ப� MES_3
	jge Result	;� ��३� � ��⪥ Result
	mov BX, offset MES_2	;���� - �������� � BX ᬥ饭�� ��ப� MES_2
	jmp Result	;� ��३� � ��⪥ Result
Result:
	ret
Polinom ENDP	;�������� ��楤��� � ������ Polinom

Start:
	mov AX, @DATA	;���樠���஢���
	mov DS, AX	;ᥣ����� ॣ���� DS
	call Polinom	;�맢��� ��楤��� Polinom
	call Output	;�맢��� ��楤��� Output
	mov BX, offset MES_Y	;�������� � BX ᬥ饭�� ��ப� MES_Y
	call Output	;�맢��� ��楤��� Output
	mov BX, Y	;�������� � BX ���祭�� ��६����� Y
	call Preobr	;�맢��� �㭪�� �८�ࠧ������ �᫠ � BX � ᨬ����� ���
	mov BX, offset Y_ASCII	;�������� � BX ᬥ饭�� ��ப� Y_ASCII
	call Output	;�맢��� ��楤��� Output
	mov AL, 0	;��������
	mov AH, 4Ch	;�ணࠬ��
	int 21h	;� ������� DOS
END Start	;����� ��室���� �����