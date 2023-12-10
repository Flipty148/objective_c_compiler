@echo off
bison.exe -d %1
if exist %~n1_tab.cpp (
	del %~n1_tab.cpp
)
if exist %~n1_nab.h (
	del %~n1_nab.h
)
ren %~n1_tab.c %~n1_tab.cpp

copy %~n1_tab.cpp .\project_for_lex.yy.c
copy %~n1_tab.h .\project_for_lex.yy.c
:: copy classes_nodes.cpp .\project_for_lex.yy.c
:: copy classes_nodes.h .\project_for_lex.yy.c
