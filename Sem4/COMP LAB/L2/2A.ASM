DATA SEGMENT
        A DW 1A10H, 2B20H, 3C30H, 4D40H, 5E50H, 2 DUP(?)
        N DW 5
        N_OVERLAP DW 3
        DATA ENDS

CODE SEGMENT
        ASSUME CS:CODE DS:DATA

START:MOV DX,DATA
      MOV DS,DX
      MOV SI,N
      DEC SI; SI=N-1
      MOV DI,SI
      ADD DI,N; DI=2*N-1
      SUB DI,N_OVERLAP
      MOV CX,N

BACK:MOV AX,[SI]
     MOV [DI],AX
     DEC SI
     DEC SI
     DEC DI
     DEC DI
     LOOP BACK

     MOV AH,4CH
     INT 21H

     CODE ENDS
     END START
        

