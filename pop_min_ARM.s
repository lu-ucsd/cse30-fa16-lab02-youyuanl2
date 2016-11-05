.syntax unified

.text

.align 8
.global pop_min_ARM
.func pop_min_ARM, pop_min_ARM
.type pop_min_ARM, %function

pop_min_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0)
    @-----------------------

    @ load member variables to registers
    ldr r4, [r0]
    ldr r5, [r0, #4]

    @ check if the int list is empty
    cmp r5, #0
    BEQ err

    ldr r7, [r4] @ get min

    mov r8, #1
    mov r9, #0
@ use for loop to remove min from the int list
for:
    cmp r8, r5
    BGE endfor
    ldr r10, [r4, r8, lsl #2]
    str r10, [r4, r9, lsl #2]
    add r8, r8, #1
    add r9, r9, #1
    B for
endfor:
    sub r5, r5, #1
    str r5, [r0, #4]
    B end

err:
    mvn r7, #0

end:
    mov r0, r7
    
    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

