.syntax unified

.text

.align 8
.global get_max_ARM
.func get_max_ARM, get_max_ARM
.type get_max_ARM, %function

get_max_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0)
    @-----------------------

    @ load member varialbes to registers
    ldr r4, [r0]
    ldr r5, [r0, #4]

    @ check if the int list empty
    cmp r5, #0
    MVNEQ r7, #0
    BEQ end

    sub r5, r5, #1
    ldr r7, [r4, r5, lsl #2]   @ get max

end:
    mov r0, r7

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

