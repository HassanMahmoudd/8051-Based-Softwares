//Name: Mahmoud Gamal       ID:2640
//Name: Ahmed Oraby			ID:3121
//Name: Hassan Mahmoud		ID:2811
			 ORG		 0H			
			 MOV		 P1, #0FFH		
//HERE:		 JB			 P1.0, HERE
CO:			 JB	     	 P1.0,DO
			 MOV		 R7, #215
LOOP3:  	 DJNZ  	 	 R7, LOOP3
			 MOV		 R6,#06H
			 SJMP		 LOOP		
DO:			 JB	   		 P1.1,EO
			 MOV		 R7, #20
LOOP4:  	 DJNZ  	 	 R7, LOOP4
			 MOV		 R6,#06H
			 SJMP		 LOOP		
EO:			 JB	    	 P1.2,FO
			 MOV		 R7, #103
LOOP5:  	 DJNZ  	 	 R7, LOOP5
			 MOV		 R6,#05H
			 SJMP	   	 LOOP
FO:	   		 JB	   		 P1.3,GO
			 MOV		 R7, #21
LOOP6:  	 DJNZ  	 	 R7, LOOP6
			 MOV		 R6,#05H
			 SJMP		 LOOP
GO:			 JB	    	 P1.4,AO
			 MOV		 R7, #138
LOOP7:  	 DJNZ  	 	 R7, LOOP7
			 MOV		 R6,#04H
			 SJMP		 LOOP
AO:			 JB	    	 P1.5,BO
			 MOV		 R7, #9
LOOP8:  	 DJNZ  	 	 R7, LOOP8
			 MOV		 R6,#04H
			 SJMP		 LOOP
BO:			 JB	  		 P1.6,CO
			 MOV		 R7, #154
LOOP9:  	 DJNZ  	 	 R7, LOOP9
			 MOV		 R6,#03H			 
LOOP:		 CPL		 P2.0          	;1
			 ACALL 		 Delay_1_sec	;2
			 SJMP   	 CO			;2
			 
Delay_1_sec:

LOOP1:		 MOV		 R7, #255
LOOP2:  	 DJNZ  	 	 R7, LOOP2   ;inner loop
			 DJNZ   	 R6, LOOP1   ;outer loop
			 RET
			 END				;end of assembly code file