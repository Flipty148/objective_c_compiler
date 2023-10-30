@echo off

flex.exe %1
if exist "lex.yy.cpp" (
	del "lex.yy.cpp"
)
ren "lex.yy.c" "lex.yy.cpp"

>$ (type "lex.yy.cpp" | findstr /v /c:"#include <unistd\.h>")& >nul move $ "lex.yy.cpp"

copy lex.yy.cpp .\project_for_lex.yy.c
