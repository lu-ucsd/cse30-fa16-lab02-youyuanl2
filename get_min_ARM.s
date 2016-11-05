.syntax unified

.text

.align 8
.global get_min_ARM
.func get_min_ARM, get_min_ARM
.type get_min_ARM, %function

get_min_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0)
    @-----------------------

    @ load member variables to registers
    ldr r4, [r0]
    ldr r5, [r0, #4]

    @ check if the int list is empty
    cmp r5, #0
    MVNEQ r7, #0
    BEQ end

    ldr r7, [r4]   @ get min

end:
    mov r0, r7

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

