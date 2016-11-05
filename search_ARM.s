.syntax unified

.text

.align 8
.global search_ARM
.func search_ARM, search_ARM
.type search_ARM, %function

search_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0, int val is in r1)
    @-----------------------

    @ load member variables to registers
    ldr r4, [r0]
    ldr r5, [r0, #4]

    mov r7, #0
@ use while loop to find the first occurence of val in the int list
while:
    cmp r7, r5
    BGE if
    ldr r8, [r4, r7, lsl #2]
    cmp r1, r8
    BEQ if
    add r7, r7, #1
    B while

@ check if val is in the int list
if:
    cmp r7, r5
    MVNEQ r7, #0

    mov r0, r7

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

