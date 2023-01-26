.586P
.MODEL FLAT, STDCALL

includelib kernel32.lib

ExitProcess			PROTO: DWORD
SetConsoleTitleA	PROTO: DWORD
GetStdHandle		PROTO: DWORD
WriteConsoleA		PROTO: DWORD, : DWORD, : DWORD, : DWORD, : DWORD
getmin				PROTO: DWORD, : DWORD
getmax				PROTO: DWORD, : DWORD

.STACK 4096

.CONST 
consoletitle	DB 'SE_asm01b', 0
Arr				DD 2, 6, -5, 9, 10, -1000, 21, 7, 98, 10

.DATA
result1			BYTE "getmax + getmin = ", 0
result			sdword 0
result2			BYTE 40 dup(0)
consolehandle	DD 0h

.CODE
main PROC

	invoke SetConsoleTitleA, offset consoletitle

	push -11
	call GetStdHandle
	mov consolehandle, eax

	invoke getmin, offset Arr, lengthof Arr

	mov result, eax

	invoke getmax, offset Arr, lengthof Arr

	add result, eax
	xor eax, eax

	push result
	push offset result2
	call tochar

	invoke WriteConsoleA, consolehandle, offset result1, sizeof result1, 0, 0
	invoke WriteConsoleA, consolehandle, offset result2, sizeof result2, 0, 0

	push 0
	call ExitProcess

main ENDP

tochar PROC uses eax ebx ecx edi esi, pstr : dword, intfield : sdword
	mov edi, pstr					; адрес результата -> edi
	mov esi, 0						; количество символов в результате
	mov eax, intfield				; число -> eax
	cdq								; знак распространили с eax на edx
	mov ebx, 10						; 10 c/c
	idiv ebx						; aex = aex/ebx, остаток -> edx
	test eax, 80000000h
	jz cycle
	neg eax
	neg edx
	mov cl, '-'
	mov [edi], cl
	inc edi
cycle:								; цикл разложения на степень 10
	push dx							; остаток -> стек
	inc esi
	test eax, eax					; eax = 0?
	jz fin
	cdq
	idiv ebx
	jmp cycle
fin:
	mov ecx, esi					; кол-во не 0вых остатков=кол-ву символов в результате
write: 
	pop bx							; остаток из стека
	add bl, '0'						; сформировали символ в bl
	mov[edi], bl
	inc edi
	loop write
	ret
tochar ENDP

END main
