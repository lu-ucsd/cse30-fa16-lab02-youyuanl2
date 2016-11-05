.syntax unified

.text

.align 8
.global insert_ARM
.func insert_ARM, insert_ARM
.type insert_ARM, %function

insert_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0, int val in r1)
    @-----------------------

    cmp r0, #0
    BEQ err   @ invalid input

    ldr r4, [r0]
    cmp r4, #0
    BEQ err   @ invalid input

    cmp r1, #0
    BLT err   @ invalid input

    ldr r5, [r0, #4]
    ldr r6, [r0, #8]
    cmp r5, r6
    BNE insert   @ when the list is no full
    
    push {r0-r3, r12}
    mov r0, r4
    mov r1, r6
    lsl r1, r1, #3
    BL realloc   @ try to resize the int list
    mov r4, r0
    pop {r0-r3, r12}

    cmp r4, #0
    BEQ err   @ resize unsuccessful

    @ update member variables
    str r4, [r0]
    lsl r6, r6, #1
    str r6, [r0, #8]

insert:
    mov r7, #0
@ use while loop to find the correct position for val
while:
    cmp r7, r5
    BGE endwhile
    ldr r8, [r4, r7, lsl #2]
    cmp r1, r8
    BLE endwhile
    add r7, r7, #1
    B while
endwhile:
    mov r9, r5
    sub r10, r9, #1
@ use for loop to make space for val
for:
    cmp r9, r7
    BLE endfor
    ldr r11, [r4, r10, lsl #2]
    str r11, [r4, r9, lsl #2]
    sub r9, #1
    sub r10, #1
    B for
endfor:
    str r1, [r4, r7, lsl #2]   @ insert val
    add r5, r5, #1
    str r5, [r0, #4]   @ update size
    B end

err:
    mvn r7, #0   @ return -1 for unsuccessful insert

end:
    mov r0, r7

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

