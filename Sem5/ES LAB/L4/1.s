	AREA    RESET, DATA, READONLY
    EXPORT  __Vectors

__Vectors 
	DCD  0x100000FF     ; stack pointer value when stack is empty
	DCD  Reset_Handler  ; reset vector
  
    	ALIGN

	AREA mycode, CODE, READONLY
	EXPORT Reset_Handler
	ENTRY
Reset_Handler
	LDR R0,=N1
	LDR R1,[R0]
	
	AND R2,R1,#0XFF
	CMP R2,#0X3A
	BLO DOWN1
	SUB R2,#7
DOWN1
	SUB R2,#0X30
	
	LSR R1,#8
	AND R3,R1,#0XFF
	CMP R3,#0X3A
	BLO DOWN2
	SUB R3,#7
DOWN2
	SUB R3,#0X30
	LSL R3,#4
	
	ADD R2,R2,R3
	LDR R0,=RES
	STRB R2,[R0]
	
STOP
	B STOP
N1 DCD 0X00003942
	AREA mydata, DATA, READWRITE
RES DCD 0
	END