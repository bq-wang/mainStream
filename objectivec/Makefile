-include common.make 

OBJDIR=Debug

#all::
#	echo $(ALL_PROGS)

#all:: $(addprefix $(OBJDIR)/,$(ALL_PROGS)) # the double colon rule: 

#$(addprefix $(OBJDIR)/,$(ALL_PROGS)):
#$(addprefix $(OBJDIR)/,$(ALL_PROGS)): $(ALL_SOURCES) 
#	$(MAKE) -C $(@D) ALL_PROGS="$(ALL_PROGS)"
all:
	echo $(ALL_PROGS)
	make -C Debug ALL_PROGS="$(ALL_PROGS)" ALL_SOURCES="$(ALL_SOURCES)"