.name "Андрій"
.comment "Слава Україні!"

ld %83, r1		# S
ld %108, r2		# l
ld %97, r3		# a
ld %118, r4		# v
ld %85, r5		# U
ld %107, r6		# k
ld %114, r7		# r
ld %105, r8		# i
ld %110, r9		# n
ld %33, r10		# !

ld %0, r11

slava_ukraini:
aff r1
aff r2
aff r3
aff r4
aff r3
aff r5
aff r6
aff r7
aff r3
aff r8
aff r9
aff r8
aff r10

zjmp %:slava_ukraini
