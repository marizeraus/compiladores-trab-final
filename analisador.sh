#! /bin/sh
gcc analizador_cminus.c -o analisadorcminus  
./analisadorcminus teste.c
python3 converTokens.py
gcc analisadorSintatico.c -o analisadorSintatico
./analisadorSintatico