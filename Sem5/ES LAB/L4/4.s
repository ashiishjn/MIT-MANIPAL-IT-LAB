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
	LDR R1,[R0]
	MOV R2,#10
	MOV R4,#8
LOOP
	UDIV R3,R1,R2
	MLS R5,R2,R3,R1
	ADD R6,R5
	ROR R6,#4
	MOV R1,R3
	SUBS R4,#1
	BNE LOOP
	LDR R0,=RES
	STR R6,[R0]
STOP
	B STOP
NUM DCD 0XAC
	AREA mydata, DATA,READWRITE
RES DCD 0
	END