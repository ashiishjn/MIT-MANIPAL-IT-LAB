; FACTORIAL OF 5 = (120)D = (78)H RESULT IS IN R0
	AREA    RESET, DATA, READONLY
    EXPORT  __Vectors

__Vectors 
	DCD  0x10001000     ; stack pointer value when stack is empty
    DCD  Reset_Handler  ; reset vector
  
    ALIGN

	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
	
Reset_Handler
	ldr r0,=05
	bl factorial
stop b stop	
	
factorial
	push	{r4,lr}		
	;push	r4 and lr onto the top of the stack 
	;stack<=>sdmdb sp!,{r4,lr} 
	 
	mov	r4,r0			;//make a copy of r0 
 

 	cmp	r0,#0			;//compare r0 with 0 
 
 
	bne	not_zero		;//branch to not_zero if not equal	 
	mov	r0,#1			;//r0=1 
 	b	last
not_zero 
 	sub	r0,r0,#1		;//r0=r0-1 
 	bl	factorial		;//call recursively factorial 
 	mov	r1,r4		 
 	mul	r0,r0,r1		;//r0=r0*r1 
last
 	pop	{r4,lr}			;//pop	<=>	ldmia sp! {r4,lr} 
	bx	lr 
