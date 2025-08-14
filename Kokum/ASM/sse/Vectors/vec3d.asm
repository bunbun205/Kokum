global kokum_vec3d_add
global kokum_vec3d_sub
global kokum_vec3d_mul
global kokum_vec3d_div
global kokum_vec3d_scalar_mul
global kokum_vec3d_scalar_div
global kokum_vec3d_dot
global kokum_vec3d_negate
global kokum_vec3d_abs
global kokum_vec3d_min
global kokum_vec3d_max
global kokum_vec3d_norm

section .rodata align=16
mask_abs: dq 0x7FFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF

section .text

kokum_vec3d_add:
    movapd xmm0, [rdi]         ; Load X,Y
    movapd xmm1, [rsi]
    addpd xmm0, xmm1
    movapd [rdx], xmm0
    movsd xmm0, [rdi + 16]     ; Load Z
    movsd xmm1, [rsi + 16]
    addsd xmm0, xmm1
    movsd [rdx + 16], xmm0
    ret

kokum_vec3d_sub:
    movapd xmm0, [rdi]
    movapd xmm1, [rsi]
    subpd xmm0, xmm1
    movapd [rdx], xmm0
    movsd xmm0, [rdi + 16]
    movsd xmm1, [rsi + 16]
    subsd xmm0, xmm1
    movsd [rdx + 16], xmm0
    ret

kokum_vec3d_mul:
    movapd xmm0, [rdi]
    movapd xmm1, [rsi]
    mulpd xmm0, xmm1
    movapd [rdx], xmm0
    movsd xmm0, [rdi + 16]
    movsd xmm1, [rsi + 16]
    mulsd xmm0, xmm1
    movsd [rdx + 16], xmm0
    ret

kokum_vec3d_div:
    movapd xmm0, [rdi]
    movapd xmm1, [rsi]
    divpd xmm0, xmm1
    movapd [rdx], xmm0
    movsd xmm0, [rdi + 16]
    movsd xmm1, [rsi + 16]
    divsd xmm0, xmm1
    movsd [rdx + 16], xmm0
    ret

kokum_vec3d_scalar_mul:
    movsd xmm1, [rsi]
    movddup xmm1, xmm1         ; Duplicate scalar into both lanes
    movapd xmm0, [rdi]
    mulpd xmm0, xmm1
    movapd [rdx], xmm0
    movsd xmm0, [rdi + 16]
    mulsd xmm0, [rsi]
    movsd [rdx + 16], xmm0
    ret

kokum_vec3d_scalar_div:
    movsd xmm1, [rsi]
    movddup xmm1, xmm1
    movapd xmm0, [rdi]
    divpd xmm0, xmm1
    movapd [rdx], xmm0
    movsd xmm0, [rdi + 16]
    divsd xmm0, [rsi]
    movsd [rdx + 16], xmm0
    ret

kokum_vec3d_dot:
    movapd xmm0, [rdi]
    movapd xmm1, [rsi]
    mulpd xmm0, xmm1
    movhlps xmm2, xmm0
    addsd xmm0, xmm2           ; sum X+Y
    movsd xmm1, [rdi + 16]
    mulsd xmm1, [rsi + 16]
    addsd xmm0, xmm1           ; +Z
    movsd [rdx], xmm0
    ret

kokum_vec3d_negate:
    xorpd xmm1, xmm1
    movapd xmm0, [rdi]
    subpd xmm1, xmm0
    movapd [rdx], xmm1
    movsd xmm0, [rdi + 16]
    xorpd xmm1, xmm1
    subsd xmm1, xmm0
    movsd [rdx + 16], xmm1
    ret

kokum_vec3d_abs:
    movapd xmm0, [rdi]
    andpd xmm0, [rel mask_abs]
    movapd [rdx], xmm0
    movsd xmm0, [rdi + 16]
    andpd xmm0, [rel mask_abs]
    movsd [rdx + 16], xmm0
    ret

kokum_vec3d_min:
    movapd xmm0, [rdi]
    movapd xmm1, [rsi]
    minpd xmm0, xmm1
    movapd [rdx], xmm0
    movsd xmm0, [rdi + 16]
    minsd xmm0, [rsi + 16]
    movsd [rdx + 16], xmm0
    ret

kokum_vec3d_max:
    movapd xmm0, [rdi]
    movapd xmm1, [rsi]
    maxpd xmm0, xmm1
    movapd [rdx], xmm0
    movsd xmm0, [rdi + 16]
    maxsd xmm0, [rsi + 16]
    movsd [rdx + 16], xmm0
    ret

kokum_vec3d_norm:
    ; Load
    movapd xmm0, [rdi]
    movapd xmm1, xmm0
    mulpd xmm1, xmm1
    movhlps xmm2, xmm1
    addsd xmm1, xmm2           ; X*X + Y*Y in xmm1 low
    movsd xmm2, [rdi + 16]
    mulsd xmm2, xmm2
    addsd xmm1, xmm2           ; + Z*Z
    sqrtsd xmm1, xmm1          ; sqrt
    movddup xmm1, xmm1
    divpd xmm0, xmm1
    movapd [rdx], xmm0
    movsd xmm0, [rdi + 16]
    divsd xmm0, xmm1
    movsd [rdx + 16], xmm0
    ret
