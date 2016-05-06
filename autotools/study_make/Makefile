# Default rule
rule1:
	echo "rule 1"
rule2:
	echo "rule 2"
rule3:
	echo "rule 3"

program:
	echo "in program"

#Multiple targets and multiple commands
program2 program3:
	echo "multiple rules"\
	echo "multiple rule line 2"

# Will print "different value now" even though the string appears after
myvar = "myvar"
testvar:
	echo $(myvar)
myvar = "different value now"

testvar2:
	@echo $(myvar)
