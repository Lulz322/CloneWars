.name "Іван"
.comment "Героям Слава!"

ld %71, r1		# G
ld %101, r2		# e
ld %114, r3		# r
ld %111, r4		# o
ld %121, r5		# y
ld %97, r6		# a
ld %109, r7		# m
ld %83, r8		# S
ld %108, r9		# l
ld %118, r10	# v
ld %33, r11		# !

ld %0, r12

geroyam_slava:
aff r1
aff r2
aff r3
aff r4
aff r5
aff r6
aff r7
aff r8
aff r9
aff r6
aff r10
aff r6
aff r11

zjmp %:geroyam_slava
