.syntax unified

.text

.align 8
.global remove_val_ARM
.func remove_val_ARM, remove_val_ARM
.type remove_val_ARM, %function

remove_val_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0, int val is in r1)
    @-----------------------

    @ load member variables into registers
    ldr r4, [r0]
    ldr r5, [r0, #4]

    mov r7, #0
@ use while loop to search for the first occurence of val in the int list
while:
    cmp r7, r5
    BGE if
    ldr r8, [r4, r7, lsl #2]
    cmp r1, r8
    BEQ if
    add r7, r7, #1
    B while

if:
    cmp r7, r5
    BEQ err   @ when val is not in the int list
    add r7, r7, #1
    mov r11, #1

@use while loop to find all occurence of val in the int list
while2:
    cmp r7, r5
    BGE for
    ldr r8, [r4, r7, lsl #2]
    cmp r1, r8
    BNE for
    add r7, r7, #1
    add r11, r11, #1
    B while2

@ use for loop to remove all occurence of val in the int list
    sub r8, r7, r11
for:
    cmp r7, r5
    BGE end
    ldr r9, [r4, r7, lsl #2]
    str r9, [r4, r8, lsl #2]
    add r7, r7, #1
    add r8, r8, #1
    B for

err:
    mov r11, #0

end:
    sub r5, r5, r11
    str r5, [r0, #4]
    mov r0, r11

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

