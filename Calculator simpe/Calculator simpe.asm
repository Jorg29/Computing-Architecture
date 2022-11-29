.data
		value: .word 0, 0, 0, 0
		msg1:  .asciiz "Sum = "
		msg2:  .asciiz "Pro = "
		msg4:  .asciiz " Choose,Exit->0(3>=EXIT),Sum->1,Pro->2,type here: "
	.text		# Μέρος text προγράμματος
	.globl main # Κύριο πρόγραμμα

main:
	
	skip:
	skip1:
	la $t9, value
	addi $t7, $t7, 0			# Αρχικοποίηση i (:t7) με 0		
	addi $s8, $s8, 0			# Αρχικοποίηση $s8 με 0
	
	li $v0, 4   				# Άμεση φόρτωση στο καταχωρητή $v0 την τιμή 4 (syscall για print_string)
	la $a0, msg4  				# Φόρτωση της διέυθυνσης του msg4 στο καταχωρητή $a0 (argument to print_string call)
	syscall  					# Κλήση syscall
	
	li $v0, 5	  				# Άμεση φόρτωση στο καταχωρητή $v0 την τιμή 5 (syscall για read_int)
	syscall		  				# Κλήση syscall
	sw $v0, 0($t9)				# Αποθήκευση του περιεχομένου του καταχωρητή $v0 στην θέση 0 του καταχωρητή $t9
	lw $t7, 0($t9)  

	beq $t7,0,EXIT           # if(input==0)||(input=>3) {goto EXIT}
	beq $t7,1,SUM 		 # if(input==1) {goto SUM}
	beq $t7,2,PRO		 # if(input==2) {goto PRO}
	
	#EΧΙΤ μεταβλητή 
EXIT:
   li  $v0, 10 # Άμεση φόρτωση στο καταχωρητή $v0 την τιμή 10 (syscall για exit)
   syscall	 # Κλήση syscall

	SUM:
	la $t0, value # Φόρτωση διεύθυνσης του value για αρχικοποίηση των καταχωρητών

	li $v0, 5	  # Άμεση φόρτωση στο καταχωρητή $v0 την τιμή 5 (syscall για read_int)
	syscall		  # Κλήση syscall
	sw $v0, 0($t0)	# Αποθήκευση του περιεχομένου του καταχωρητή $v0 στην θέση 0 του καταχωρητή $t0

# Σε αυτό το σημείο έχουμε διαβάσει την πρώτη τιμή

	li $v0, 5	  # Άμεση φόρτωση στο καταχωρητή $v0 την τιμή 5 (syscall για read_int)
	syscall		  # Κλήση syscall
	sw $v0, 4($t0)     # Αποθήκευση του περιεχομένου του καταχωρητή $v0 στην θέση 4 του καταχωρητή $t0
	
# TIP: αποθηκεύουμε +4 θέσεις επειδή η μνήμη μας είναι οργανωμένη σε byte
# Σε αυτό το σημείο έχουμε διαβάσει την δεύτερη τιμή
# Τώρα αρκεί να φορτώσουμε τα δεδομένα μας για να κάνουμε την πρόσθεση

	lw $t1, 0($t0)  # Φόρτωση των δεδομένων απο την θέση 0 του καταχωρητή $t0 και αποθήκευση αυτου στον καταχωρητή $t1
	lw $t2, 4($t0)	# Φόρτωση των δεδομένων απο την θέση 4 του καταχωρητή $t0 και αποθήκευση αυτου στον καταχωρητή $t2
	add $t3, $t1, $t2 # Πρόσθεση των τιμών των καταχωρητών $t1 και $t2 και αποθήκευση αυτου στο καταχωρητή $t3
	sw $t3, 8($t0)  # Αποθήκευση του περιεχομένου του καταχωρητή $t3 στην θέση 8 του καταχωρητή $t0

# Σε αυτο το σημείο έχει ολοκληρωθεί η πρόσθεση
# Εμφάνιση αποτελέσματος:

   li $v0, 4   # Άμεση φόρτωση στο καταχωρητή $v0 την τιμή 4 (syscall για print_string)
   la $a0, msg1 # Φόρτωση της διέυθυνσης του msg1 στο καταχωρητή $a0 (argument to print_string call)
   syscall  # Κλήση syscall



# Μέχρι εδώ έχουμε εμφανίσει το μήνυμα Sum=

   li $v0, 1   # Άμεση φόρτωση στο καταχωρητή $v0 την τιμή 1 (syscall για print_int)
   move $a0, $t3 # Φόρτωση στο καταχωρητή $a0 το περιεχόμενο του $t3
   syscall     # Κλήση syscall


	j skip
	li  $v0, 10 # Άμεση φόρτωση στο καταχωρητή $v0 την τιμή 10 (syscall για exit)
   	syscall	 # Κλήση syscall	
		

PRO:
	la $t0, value # Φόρτωση διεύθυνσης του value για αρχικοποίηση των καταχωρητών
	
	li $v0, 5	  # Άμεση φόρτωση στο καταχωρητή $v0 την τιμή 5 (syscall για read_int)
	syscall		  # Κλήση syscall
	sw $v0, 0($t0)	# Αποθήκευση του περιεχομένου του καταχωρητή $v0 στην θέση 0 του καταχωρητή $t0

# Σε αυτό το σημείο έχουμε διαβάσει την πρώτη τιμή

	li $v0, 5	  # Άμεση φόρτωση στο καταχωρητή $v0 την τιμή 5 (syscall για read_int)
	syscall		  # Κλήση syscall
	sw $v0, 4($t0)     # Αποθήκευση του περιεχομένου του καταχωρητή $v0 στην θέση 4 του καταχωρητή $t0
	
# TIP: αποθηκεύουμε +4 θέσεις επειδή η μνήμη μας είναι οργανωμένη σε byte
# Σε αυτό το σημείο έχουμε διαβάσει την δεύτερη τιμή
# Τώρα αρκεί να φορτώσουμε τα δεδομένα μας για να κάνουμε την πρόσθεση

	lw $t1, 0($t0)  # Φόρτωση των δεδομένων απο την θέση 0 του καταχωρητή $t0 και αποθήκευση αυτου στον καταχωρητή $t1
	lw $t2, 4($t0)	# Φόρτωση των δεδομένων απο την θέση 4 του καταχωρητή $t0 και αποθήκευση αυτου στον καταχωρητή $t2
	mul $t3, $t1, $t2	# Πολλαπλασιαμο των τιμών των καταχωρητών $t1 και $t2 και αποθήκευση αυτου στο καταχωρητή $t3
	sw $t3, 8($t0)  # Αποθήκευση του περιεχομένου του καταχωρητή $t3 στην θέση 8 του καταχωρητή $t0

# Σε αυτο το σημείο έχει ολοκληρωθεί η πολλαπλασιασμός
# Εμφάνιση αποτελέσματος:

   li $v0, 4   # Άμεση φόρτωση στο καταχωρητή $v0 την τιμή 4 (syscall για print_string)
   la $a0, msg2  # Φόρτωση της διέυθυνσης του msg1 στο καταχωρητή $a0 (argument to print_string call)
   syscall  # Κλήση syscall

# Μέχρι εδώ έχουμε εμφανίσει το μήνυμα Pro=

   li $v0, 1   # Άμεση φόρτωση στο καταχωρητή $v0 την τιμή 1 (syscall για print_int)
   move $a0, $t3 # Φόρτωση στο καταχωρητή $a0 το περιεχόμενο του $t3
   syscall     # Κλήση syscall
	j skip1

   li  $v0, 10 # Άμεση φόρτωση στο καταχωρητή $v0 την τιμή 10 (syscall για exit)
   syscall	 # Κλήση syscall

 