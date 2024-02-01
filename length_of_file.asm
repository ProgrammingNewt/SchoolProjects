
length_of_file:
#function to find length of data read from file
#arguments: a1=bufferAdress holding file data
#return file length in a0
	
#Start your coding here

    li t5, 0
    mv t0, a1  
    li a0, 0   

   
count_loop:

    lbu t1, 0(t0)  
    
    beq t1, t5, end_cnt  #
    
    addi t0, t0, 1  
    
    addi a0, a0, 1  

    
    
    j count_loop      

end_cnt:
    ret 

#if no student code provided, this function just returns 0 in a0

#End your coding here

#######################end of length_of_file###############################################	
