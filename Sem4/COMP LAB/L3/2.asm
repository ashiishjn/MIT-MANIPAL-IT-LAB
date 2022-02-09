;Program to add two 8-bit decimal numbers from DS to DS
Code Segment
num1 dB 25H
num2 dB 25H
sum dB 0H
carry dB 0H
Code ends

Data Segment
Assume CS:Code, DS:Data
Start:

MOV AX,Data
MOV DS,AX

MOV AL, num1
MOV BL, num2

CLC
ADC AL, BL
DAA
MOV sum, AL
ADC carry, 0

MOV AH, 4CH
INT 21H

Code ends
End Start