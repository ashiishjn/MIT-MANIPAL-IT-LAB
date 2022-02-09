DATA SEGMENT
        H DB 0B2H
        TEMP DB 0,0,0
        BCD DW ?
        DATA ENDS

CODE SEGMENT
        ASSUME CS:CODE, DS:DATA

START:MOV AX,DATA
      MOV DS,AX

      MOV AL,H
      MOV CL,0AH
      LEA SI,TEMP

      BACK:MOV AH,0
           DIV CL
           MOV [SI],AH
           INC SI
           CMP AL,0
           JNZ BACK

      LEA SI,TEMP
      MOV CL,04
      MOV AL,[SI+1]
      ROR AL,CL
      ADD AL,[SI]
      MOV AH,2[SI]
      MOV BCD,AX

      MOV AH,4CH
      INT 21H

      CODE ENDS
      END START
                
