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
	LDR R0,=N2
	LDR R2,[R0]
	CMP R1,R2
	BHI LOOP1
	MOV R3,R1
	MOV R1,R2
	MOV R2,R3
LOOP1
	UDIV R5,R1,R2
	MUL R3,R2,R5
	SUBS R0,R1,R3
	BEQ EXIT
	ADD R1,R1
	B LOOP1
EXIT
	LDR R0, =LCM
	STR R1,[R0]
STOP
	B STOP
N1 DCD 0XC
N2 DCD 0X12
	AREA mydata, DATA, READWRITE
LCM DCD 0
	END