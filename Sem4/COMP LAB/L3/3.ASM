DATA SEGMENT
        NUM1 DD 254DC584H
        NUM2 DD 985ACD21H
        SUM DD ?
        CARRY DB 0
        DATA ENDS

CODE SEGMENT
        ASSUME CS:CODE DS:DATA

START:MOV AX,DATA
      MOV DS,AX

      MOV SI,0
      MOV DI,4
      MOV BX,8
      MOV AX,[SI]
      ADD AX,[DI]
      MOV [BX],AX
      INC SI
      INC SI
      INC DI
      INC DI
      INC BX
      INC BX
      MOV AX,[SI]
      ADC AX,[DI]
      MOV [BX],AX
      ADC CARRY,0

      MOV AH,4CH
      INT 21H

      CODE ENDS
      END START
