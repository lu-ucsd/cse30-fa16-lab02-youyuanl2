.syntax unified

.text

.align 8
.global print_ARM
.func print_ARM, print_ARM
.type print_ARM, %function

print_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0)
    @-----------------------

    @ load member variables to registers
    ldr r4, [r0]
    ldr r5, [r0, #4]
    
    mov r7, #0
@ use for loop to print all elements
for:
    cmp r7, r5
    BGE end
    push {r0-r3, r12}
    ldr r0,=str1
    ldr r1, [r4, r7, lsl #2]
    BL printf
    pop {r0-r3, r12}
    add r7, r7, #1
    B for

end:
    push {r0-r3, r12}
    ldr r0,=str2
    BL printf
    pop {r0-r3, r12}

@ create two format strings
.data
str1:
    .asciz "%d "
str2:
    .asciz "\n"

.text

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

