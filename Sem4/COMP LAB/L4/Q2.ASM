DATA SEGMENT
        BCD DW 1111H
        TEMP DW 4 DUP (?)
        HEX DW ?
        DATA ENDS

CODE SEGMENT
        ASSUME CS:CODE, DS:DATA

START:MOV AX,DATA
      MOV DS,AX

      MOV BX,BCD
      MOV SI,0
      MOV CL,04H

      UP:MOV AX,BX
         AND AX,0FH
         MOV [SI+TEMP],AX
         INC SI
         INC SI
         SHR BX,CL
         CMP BX,0
         JNZ UP

     LEA SI,TEMP
     MOV BX,[SI]
     MOV DI,03H
     MOV CX,0AH

     BACK:INC SI
          INC SI
          MOV AX,[SI]
          MUL CX
          ADD BX,AX
          MOV AX,0AH
          MUL CX
          MOV CX,AX
          DEC DI
          JNZ BACK

     MOV HEX,BX

     MOV AH,4CH
     INT 21H

     CODE ENDS
     END START
