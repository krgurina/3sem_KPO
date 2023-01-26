.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA

	; Template data
OK			EQU	0
T_MES		DB "Template!", 0
MES			DB "Is template of Assembler programm!"
HW			DD ?

	; Import string data
FILESTR		DB "Hello", 0							; Example (Max size of str 127)

	; Import integer data
FILEINT		DD 15000								; Example

INTSTR		DB "The int number = ", 10 dup(0)		; dup ����� ���-�� ��������

STROFF		EQU 17
INTSIZE		EQU 4									; ����� ���-�� �������� ����� ����� 1

.CODE

main PROC
	
; Template output

	push OK
	push offset T_MES
	push offset MES
	push HW
	call MessageBoxA

; Import-string output

	push OK
	push offset T_MES
	push offset FILESTR
	push HW
	call MessageBoxA

; Import-int output
	
	mov ebx, 10

	mov ecx, INTSIZE
	mov edx, 0
	mov eax, FILEINT	

	.WHILE eax > 0

		mov esi, offset INTSTR
		add esi, STROFF
		add esi, ecx

		div ebx

		mov [esi], dl
		add BYTE ptr [esi], 30h

		mov edx, 0

		dec ecx

	.ENDW

	push OK
	push offset T_MES
	push offset INTSTR
	push HW
	call MessageBoxA

	push - 1

	call ExitProcess
main ENDP

end main