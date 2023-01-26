.586P													;система команд (процессор Pentium)
.MODEL FLAT, STDCALL									;модель памяти, соглашение о вызовах
includelib kernel32.lib									;компановщику: компоновать с kernel32

ExitProcess PROTO : DWORD								;прототип функции для завершения процесса Windows
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD	;прототип API-функции MessageBoxA (вывод в окно)

.STACK 4096												;выделение стека объемом 4 мегабайта

.DATA													;сегмент данных
		x dd 1										
		y dd 6
		str1 db "Суммирование", 0								
		str2 db "x + y = ", 0


.CODE													;сегмент кода
main PROC												;точка входа main
start:													;метка
		mov eax, x
		add eax, y
		add al, 30h

		
		mov str2+8, al								;младшая половина подрегистра
		
		invoke MessageBoxA, 0, offset str2, offset str1, 0

		push 0											;код возврата процесса Windows (параметр ExitProcess)
		call ExitProcess								;так завершается любой процесс Windows

main ENDP;											;конец процедуры

end main;					