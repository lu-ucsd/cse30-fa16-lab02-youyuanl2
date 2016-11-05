.syntax unified

.text

.align 8
.global createlist_ARM
.func createlist_ARM, createlist_ARM
.type createlist_ARM, %function

createlist_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (int maxElements is in r0)
    @-----------------------

    push {r0-r3, r12}
    mov r0, #12
    BL malloc     @ try to malloc a list
    mov r4, r0     @ store the address of the list in r4
    pop {r0-r3, r12}

    cmp r4, #0
    BEQ return   @ malloc unsuccessful
    
    push {r0-r3, r12}
    lsl r0, r0, #2
    BL malloc   @ try to malloc an int list
    mov r5, r0   @ store the address of the int list in r5
    pop {r0-r3, r12}

    cmp r5, #0
    BEQ freelist   @ malloc unsuccessful

    @ initialize member variables of the list
    str r5, [r4]
    mov r6, #0
    str r6, [r4, #4]
    str r0, [r4, #8]
    B end

freelist:
    push {r0-r3, r12}
    mov r0, r4
    BL free   @ free the list 
    pop {r0-r3, r12}

return:
    mov r4, #0   @ avoid dangling pointer

end :
    mov r0, r4

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

