@echo off
project_for_lex.yy.c.exe %1
dot -Tsvg dot.dot > out.svg