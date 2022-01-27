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
LOOP
	CMP R1,R2
	BEQ QUIT
	SUBHI R1,R2
	SUBLO R2,R1
	B LOOP
QUIT
	LDR R2,=GCD
	STR R1,[R2]
STOP
	B STOP
N1 DCD 0X18
N2 DCD 0X7
	AREA mydata, DATA, READWRITE
GCD DCD 0
	END