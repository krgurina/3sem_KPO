.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
.STACK 4096

.CONST

FILEUINT	 DD 15

.DATA

FILEINT	 DD 14

.CODE

main PROC

push - 1

call ExitProcess
main ENDP

end main
