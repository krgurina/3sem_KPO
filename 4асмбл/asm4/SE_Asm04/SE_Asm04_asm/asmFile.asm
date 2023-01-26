.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA

OK			EQU	0
TEXT_MESSAGE		DB "SE_Asm04", 0
HW			DD ?

FILEINT DD 1, 1, 1
INTSTR DB "int:    ", 0

FILEUINT32 DD 1, 1, 5
UINT32STR DB "uint32:     ", 0

.CODE

main PROC



mov eax, FILEINT 
add eax, 30h
mov INTSTR +8, al


mov eax, FILEINT  + type FILEINT
add eax, 30h
mov INTSTR +9, al


mov eax, FILEINT  + type FILEINT + type FILEINT
add eax, 30h
mov INTSTR +10, al
invoke MessageBoxA, 0, offset INTSTR, ADDR TEXT_MESSAGE, OK


mov eax, FILEUINT32 
add eax, 30h
mov UINT32STR + 10, al


mov eax, FILEUINT32  + type FILEUINT32
add eax, 30h
mov UINT32STR + 11, al


mov eax, FILEUINT32  + type FILEUINT32 + type FILEUINT32
add eax, 30h
mov UINT32STR + 12, al
invoke MessageBoxA, 0, offset UINT32STR, ADDR TEXT_MESSAGE, OK
push - 1
call ExitProcess
main ENDP
end main
