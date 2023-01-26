.586P													;������� ������ (��������� Pentium)
.MODEL FLAT, STDCALL									;������ ������, ���������� � �������
includelib kernel32.lib									;������������: ����������� � kernel32

ExitProcess PROTO : DWORD								;�������� ������� ��� ���������� �������� Windows
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD	;�������� API-������� MessageBoxA (����� � ����)

.STACK 4096												;��������� ����� ������� 4 ���������

.DATA													;������� ������
		x dd 1										
		y dd 6
		str1 db "������������", 0								
		str2 db "x + y =  ", 0
		res db 1


.CODE													;������� ����
main PROC												;����� ����� main
start:													;�����
		mov eax, x
		add eax, y
		add al, 30h

		
		mov str2+8, al								;������� �������� �����������
		
		invoke MessageBoxA, 0, offset str2, offset str1, 0

		push 0											;��� �������� �������� Windows (�������� ExitProcess)
		call ExitProcess								;��� ����������� ����� ������� Windows

main ENDP;											;����� ���������

end main;					