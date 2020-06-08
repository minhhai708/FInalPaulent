segment .data
	__msg_error_division	db "****Error de ejecuccion: Division por cero.", 0
	__msg_error_indice_vector	db "****Error de ejecuccion: Indice es fuera de rango.", 0
	__msg_debug	db "****RUN HERE.", 0
segment .bss
	__esp resd 1
	_y resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float

	;DECLARAR FUNCION nombre_funcion=prueba,num_var_loc=1
_prueba:
	push ebp
	mov ebp, esp
	sub esp, 4

	;Apilar la constante 100
	push dword 100

	;ESCRIBIR VARIABLE LOCAL
	lea eax, [ebp - 4]
	push eax

	;Escribe output
	call print_int
	add esp, 4
	call print_endofline

	;Apilar la constante 0
	push dword 0

	;RETORNAR FUNCION
	mov esp, ebp
	pop ebp
	ret
main:
	mov dword [__esp] , esp

	;Asignar valor
	pop dword eax
	mov dword [_y], eax

	;Final of Progrma
	jmp near fin
fin_error_division:
	push dword __msg_error_division
	call print_string
	add esp, 4
	call print_endofline
	jmp near fin
fin_indice_fuera_rango:
	push dword __msg_error_indice_vector
	call print_string
	add esp, 4
	call print_endofline
	jmp near fin
fin:
	mov dword esp, [__esp]
	ret
