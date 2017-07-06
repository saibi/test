#
# c test code makefile
# 
#
UNAME=$(shell uname -s)
OS=$(shell uname -o)

ifeq ($(UNAME),Linux)
CPPCHECK=/usr/bin/cppcheck
NSIQ=/opt/nsiqcollector/nsiqcollector
else
CPPCHECK=
NSIQ=
endif

ifdef A20
CC=arm-linux-gnueabihf-gcc
LD=arm-linux-gnueabihf-ld
AR=arm-linux-gnueabihf-ar
AR=arm-linux-gnueabihf-ar
OC=arm-linux-gnueabihf-objcopy
else
CC=gcc
LD=ld
AR=ar
AR=ar
OC=objcopy
endif

ifdef V
ifeq ("$(origin V)", "command line")
	VERBOSE = $(V)
endif
endif
ifndef VERBOSE
	VERBOSE = 0
endif

ifeq ($(VERBOSE),1)
	Q =
	SOPTION =
else
	Q = @
	SOPTION=-s
endif


date_str=$(shell date +%Y%m%d)
build_count_str=$(shell touch build_count.txt;cat build_count.txt)
version_str=$(shell cat version.txt | awk '{print $1;}' )

DEFS=-DZERO_ARRAY_IDX=0 -DVERSION_STR=\"$(version_str)\" -DDATE_STR=\"$(date_str)\" -DBUILD_COUNT_STR=\"$(build_count_str)\"

INC=-I.

COPTS=-Wstrict-prototypes -Wno-trigraphs 
COPTS+=-fno-strict-aliasing -fno-common -pipe
COPTS+=-Wmissing-declarations -Winline -Wshadow -Wreturn-type -Wundef -Wpointer-arith -Wbad-function-cast
COPTS+=-Wcast-align -Wsign-compare -Wunused-function
COPTS+=-Wall -std=gnu99 -ffunction-sections

CFLAGS=$(DEFS) $(INC) $(COPTS)

PRJ=serial
OBJS=serial.o

$(PRJ): $(OBJS)
	$(Q)$(CC) $(LDFLAGS) -o $(PRJ) $(OBJS) $(LIBS) 
ifeq ($(A),1)
	$(Q)rm -f a.out
endif 

.s.o:
	$(Q)echo "assemble $<"
	$(Q)$(CC) -x assembler-with-cpp $(CFLAGS) -c $< -o $@

.c.o:
	$(Q)echo "compile $<"
	$(Q)$(CC) $(CFLAGS) -c $< -o $@
ifeq ($(A),1)
	$(Q)$(CC) $(CFLAGS) -S -fverbose-asm $< -o $(<:%.c=%.asm)
	$(Q)$(AS) -alhnd $(<:%.c=%.asm) > $(<:%.c=%.casm)
endif

clean:
	rm -f $(OBJS)

