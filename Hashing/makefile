#Author: Jayden Vinson 

CFLAGS= -std=c99 -pedantic -Wformat -Wreturn-type
LDFLAGS= -L. 
LIBS= -lmc -lncursesw  -lm

all: tags headers lab2 

lab2.zip: makefile *.c *.h *.sh *.awk README_LAB2 
	# in the rule below, $^ can save you - why?
	zip $@ $^
	# self test is required: first remove old install folder 
	rm -rf install 
	# create the install folder 
	mkdir install 
	# unzip to the install folder 
	unzip lab2.zip -d install 
	# make ONLY the lab1 target, not lab1.zip 
	make -r lab2
	# make all other things that get graded too (never the zip!)
	
	# the above means things like stuff and all prototypes
	# LOOK FOR ERRORS BELOW here
	make -C install -r lab2
	
	#LOOK FOR BUILD ERRORS ABOVE here
	#coelinux has a race condition so we call sleep to fix that
	sleep 2
	# Finally: remove install folder so we don't accidentally use it 
	rm -rf install  

headers: *.c tags
	./headers.sh

tags: *.c
	ctags -R .

lab2: lab2.o bits.o sim.o input.o aimpoints.o missiles.o output.o text.o graphics.o
	gcc -g -o $@ $^  $(LDFLAGS) $(LIBS)

# this is our master compiler rule to generate .o files.
# It needs all 4 warnings
# lab2.o bits.o sim.o input.o aimpoints.o missiles.o output.o text.o graphics.o

%.o:%.c *.h
	gcc $(CFLAGS) -g -c $< -o $@