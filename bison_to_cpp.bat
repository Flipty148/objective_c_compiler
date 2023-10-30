@echo off
bison.exe -d %1
if exist %~n1_tab.cpp (
	del %~n1_tab.cpp
)
if exist %~n1_nab.h (
	del %~n1_nab.h
)
ren %~n1_tab.c %~n1_tab.cpp
>$ (echo #include "classes_nodes.h"& type "%~n1_tab.h")& >nul move $ "%~n1_tab.h"