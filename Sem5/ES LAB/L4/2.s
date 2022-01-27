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
	LDR R0,=NUM
	LDR R1,[R0],#4
	MOV R5,#04
	
LOOP
	AND R2,R1,#0X0F
	ADD R3,R2
	ROR R3,#4
	LSR R1,#08
	SUBS R5,#1
	BNE LOOP
	
	MOV R5,#04
	LDR R1,[R0]
	
LOOP2
	AND R2,R1,#0X0F
	ADD R3,R2
	ROR R3,#4
	LSR R1,#08
	SUBS R5,#1
	BNE LOOP2
	
	LDR R0,=RES
	STR R3,[R0]
	
STOP
	B STOP

NUM DCD 0X0A010208, 0X090B0C06
	AREA mydata, DATA, READWRITE
RES DCD 0
	END