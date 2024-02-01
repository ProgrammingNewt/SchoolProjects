income_from_record:
#function to return numerical income from a specific record
#e.g. for record "Microsoft,34\r\n", income to return is 34(for which name is Microsoft)

#arguments:	a0 contains pointer to start of numerical income in record 

#function RETURNS income numerical value of the asci income in a0 (34 in our example)
	
# Start your coding from here!

   
    lwu a0,0(a0)    

    li t5, 13       
    li t4, 48      
    li t3, 10      
    li t6, 0        

next_char:
    lbu a1, 0(a0)   
    addi a0, a0, 1  

    beq a1, t5, end_loop  

    
    sub a1, a1, t4  
    mul t6, t6, t3  
    add t6, t6, a1  

    j next_char     
end_loop:
    mv a0, t6       
    ret          
	
#######################end of income_from_record###############################################	
