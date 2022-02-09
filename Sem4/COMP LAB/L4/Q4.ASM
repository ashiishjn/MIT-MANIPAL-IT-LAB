DATA SEGMENT
        H DW 0BD54H
        TEMP DB 0,0,0,0,0
        BCD DD ?
        DATA ENDS

CODE SEGMENT
        ASSUME CS:CODE, DS:DATA

START:MOV AX,DATA
      MOV DS,AX
      MOV AX,H
      MOV CX,0AH
      LEA SI,TEMP

      BACK:MOV DX,0
           DIV CX
           MOV [SI],DL
           INC SI
           CMP AX,0
           JNZ BACK

      LEA SI,TEMP
      MOV CL,04
      MOV AL,[SI+1]
      ROR AL,CL
      ADD AL,[SI]
      MOV AH,[SI+3]
      ROR AH,CL
      ADD AH,[SI+2]
      MOV BL,[SI+4]
      LEA SI,BCD
      MOV [SI],AX
      MOV [SI+2],BL

      MOV AH,4CH
      INT 21H

      CODE ENDS
      END START

