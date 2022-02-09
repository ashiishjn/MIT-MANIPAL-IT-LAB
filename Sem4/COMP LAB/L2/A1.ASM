;Program to reverse an array
Data Segment
Array1 dW 1111H, 2222H, 3333H, 4444H, 5555H , 6666H, 7777H, 8888H, 9999H, 0AAAAH
COUNT dB 05H
Data ends

Code Segment
Assume CS:Code, DS: Data
Start:
MOV AX, Data
MOV DS, AX

LEA SI, Array1
MOV CH, 00H
MOV CL, COUNT

MOV DI, SI
ADD SI, 18

NEXT:
MOV AX, [DI]
MOV BX, [SI]
MOV [SI], AX
MOV [DI], BX
ADD DI,2
SUB SI,2
LOOP NEXT

MOV AH,4CH
INT 21H

Code ends
end start
 