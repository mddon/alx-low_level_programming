SECTION .data
msg:    db "Hello, Holberton", 0    ; This is the string containing the message
fmt:    db "%s", 10, 0              ; Format string "%s" and the newline character

	SECTION .text
	extern printf
	global main

main:
	mov esi, msg
	mov edi, fmt
	mov eax, 0
	call printf     ; Call the printf function

	mov eax, 0      ; Set the return value to 0
	ret             ; Return from the main function
