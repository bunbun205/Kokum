global kokum_vec2f_add
global kokum_vec2f_sub
global kokum_vec2f_mul
global kokum_vec2f_div
global kokum_vec2f_scalar_mul
global kokum_vec2f_scalar_div
global kokum_vec2f_dot
global kokum_vec2f_negate
global kokum_vec2f_abs
global kokum_vec2f_min
global kokum_vec2f_max
global kokum_vec2f_norm

section .rodata align=32
mask_abs: dd 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0, 0, 0, 0

section .text

kokum_vec2f_add:
    vmovups ymm0, [rdi]
    vmovups ymm1, [rsi]
    vaddps ymm0, ymm0, ymm1
    vmovups [rdx], ymm0
    ret

kokum_vec2f_sub:
    vmovups ymm0, [rdi]
    vmovups ymm1, [rsi]
    vsubps ymm0, ymm0, ymm1
    vmovups [rdx], ymm0
    ret

kokum_vec2f_mul:
    vmovups ymm0, [rdi]
    vmovups ymm1, [rsi]
    vmulps ymm0, ymm0, ymm1
    vmovups [rdx], ymm0
    ret

kokum_vec2f_div:
    vmovups ymm0, [rdi]
    vmovups ymm1, [rsi]
    vdivps ymm0, ymm0, ymm1
    vmovups [rdx], ymm0
    ret

kokum_vec2f_scalar_mul:
    vbroadcastss ymm1, [rsi]
    vmovups ymm0, [rdi]
    vmulps ymm0, ymm0, ymm1
    vmovups [rdx], ymm0
    ret

kokum_vec2f_scalar_div:
    vbroadcastss ymm1, [rsi]
    vmovups ymm0, [rdi]
    vdivps ymm0, ymm0, ymm1
    vmovups [rdx], ymm0
    ret

kokum_vec2f_dot:
    vmovups ymm0, [rdi]
    vmovups ymm1, [rsi]
    vdpps ymm0, ymm0, ymm1, 0x31
    vmovss [rdx], xmm0
    ret

kokum_vec2f_negate:
    vxorps ymm1, ymm1, ymm1
    vmovups ymm0, [rdi]
    vsubps ymm0, ymm1, ymm0
    vmovups [rdx], ymm0
    ret

kokum_vec2f_abs:
    vmovups ymm0, [rdi]
    vandps ymm0, ymm0, [rel mask_abs]
    vmovups [rdx], ymm0
    ret

kokum_vec2f_min:
    vmovups ymm0, [rdi]
    vmovups ymm1, [rsi]
    vminps ymm0, ymm0, ymm1
    vmovups [rdx], ymm0
    ret

kokum_vec2f_max:
    vmovups ymm0, [rdi]
    vmovups ymm1, [rsi]
    vmaxps ymm0, ymm0, ymm1
    vmovups [rdx], ymm0
    ret

kokum_vec2f_norm:
    vmovups ymm0, [rdi]
    vmulps ymm1, ymm0, ymm0
    vhaddps ymm1, ymm1, ymm1
    vsqrtps ymm1, ymm1
    vdivps ymm0, ymm0, ymm1
    vmovups [rdx], ymm0
    ret
