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
	LDR R0, =N2
	LDR R2,[R0]
LOOP
	ADDS R3,R1
	ADCS R4,#0
	SUBS R2,#1
	BNE LOOP
	LDR R0,=RES
	STR R3,[R0],#4
	STR R4,[R0]
STOP
	B STOP
N1 DCD 0X78459845
N2 DCD 0X00000006
	AREA mydata, DATA, READWRITE
RES DCD 0
	END
