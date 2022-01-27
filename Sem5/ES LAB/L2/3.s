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
	SUBS R6,R1,R2
	LDR R0,=RES
	STR R6,[R0]
STOP
	B STOP
N1 DCD 0X741235FA
N2 DCD 0XA145ADFC
	AREA mydata, DATA, READWRITE
RES DCD 0
	END