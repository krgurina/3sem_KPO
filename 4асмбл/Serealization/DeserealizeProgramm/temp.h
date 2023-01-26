#pragma once

#include "stdafx.h"

#define ASMHEADER \
\
<< ".586P" << endl \
<< ".MODEL FLAT, STDCALL" << endl \
<< "includelib kernel32.lib\n" << endl \
<< "ExitProcess PROTO : DWORD" << endl \
<< ".STACK 4096\n" << endl \
<< ".CONST\n" << endl 

#define DATA \
<< ".DATA\n" << endl 

#define ASMFOOTER \
\
<< ".CODE\n" << endl \
<< "main PROC\n" << endl \
<< "push - 1\n" << endl \
<< "call ExitProcess" << endl \
<< "main ENDP\n" << endl \
<< "end main" << endl			