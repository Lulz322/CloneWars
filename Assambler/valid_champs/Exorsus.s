.name "Exorsus"
.comment "bet you can't treat me"

; r1 - number of champ
; r2 - where to write
; r3 - size for copy label
; r4 - len for copy label
; r5 - space to free
# r6 - useless :D

prep:
		sti r1, %:copy, %1			; prepare2flex
		sti r1, %:live, %1
		ld %0, r6
		sti r6, %:prep, %0
		sti r6, %:prep, %3
		sti r6, %:prep, %7
		sti r6, %:prep, %10

core:								; runs the core program
		ld %0, r2
		ld %4, r3					; set copy size to 4
		ld %:finish, r4				; get the length of the data to copy
		ld %:core, r5
		sub r4, r5, r4
		and r4, %3, r5				; check 4 byte alignment
		zjmp %:copy
		add r4, r3, r4				; align length to 4
		and r4, %-4, r4

copy:
		live %1
		ldi %:core, r2, r5			; read 4 bytes
		sti r5, %:finish, r2		; write 4 bytes
		add r2, r3, r2				; increase current write position
		xor r4, r2, r5				; compare current write position with final position
		zjmp %:do_fork				; exit copy loop
		ld %0, r5					; trick to force zjmp <-> jmp
		zjmp %:copy					; copy until the core code has completed its copy cycle

live:
		live %1
		zjmp %:live

do_fork:
		fork %:live

finish:								; winner winner chicken dinner!
