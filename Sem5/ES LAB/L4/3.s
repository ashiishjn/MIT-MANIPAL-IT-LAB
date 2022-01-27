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
	AND R2,R1,#0X0F
	AND R3,R1,#0XF0
	LSR R3,#4
	MOV R5,#10
	MLA R3,R3,R5,R2
	LDR R0,=RES
	STR R3,[R0]
	
STOP
	B STOP
N1 DCD 0X79
	AREA mydata, DATA, READWRITE
RES DCD 0
	END