# The following two lines force the standard make to recognize the 
# Objective-C .m suffix.

CC=gcc
.SUFFIXES: .o .m
.m:
	$(CC) -o $@ $< $(CFLAGS) 

.PHONY: gui_apps

# check the "old fashion suffix rule"
#../.m: # this "../.m" won't work, because that will cause the $@ and $< automatic variable to have wrong value
#	$(CC) -o hello ../hello.m   $(CFLAGS)


# notice the end of the rule, which has a ; 

SRC_DIR=../


# better write this pattern rule, this is more explicit
echo SRC_DIR=$(SRC_DIR)
%: $(SRC_DIR)%.m
	$(CC) -o $@ $< $(CFLAGS)

SRC_DIR=../ClassObjectMethods/
%: $(SRC_DIR)%.m
	$(CC) -o $@ $< $(CFLAGS)

SRC_DIR=../DataTypesExpressions/
%: $(SRC_DIR)%.m
	$(CC) -o $@ $< $(CFLAGS)

SRC_DIR=../ProgramLoops/
%: $(SRC_DIR)%.m
	$(CC) -o $@ $< $(CFLAGS)

SRC_DIR=../MakingDecisions/
%: $(SRC_DIR)%.m
	$(CC) -o $@ $< $(CFLAGS)

SRC_DIR=../MoreOnClasses/
%: $(SRC_DIR)%.m
	$(CC) -o $@ $< $(CFLAGS)	

# additional prerequisite are useful only in the case of the rules (such as the pattern rule or suffix rule, where you can delare empty rules for certain target, which shall be used as additional prerequisite 
#SRC_DIR=../Inheritance/
#rectangle_main square_main:  $(SRC_DIR)Rectangle.m $(SRC_DIR)Rectangle.h
#	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS)	
#	
#rectangle_main: $(SRC_DIR)rectangle_main.m
#
#square_main: $(SRC_DIR)square_main.m $(SRC_DIR)Square.h $(SRC_DIR)Square.m
#	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS)		

#fraction: ../ClassObjectMethods/fraction.m
#	$(CC) -o $@ $< $(CFLAGS)

# since the multi-line support is not there in version make 3.81, we won't use the define as below. 
#define PROGRAM_template =
#hello: ../hello.m
#	$(CC) -o $@ $< $(CFLAGS)
#endef

#define hello_echo=
#echo hello world
#endef 
	
all: $(ALL_PROGS)
#	echo $(PROGRAM_template)
#	echo $(B)
#	$(hello_echo)


SRC_DIR=../Inheritance/
rectangle_main: $(SRC_DIR)Rectangle.m $(SRC_DIR)Rectangle.h
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS)
square_main: $(SRC_DIR)square_main.m $(SRC_DIR)Square.h $(SRC_DIR)Square.m $(SRC_DIR)Rectangle.h $(SRC_DIR)Rectangle.m
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS)
xyrectangle_main: $(SRC_DIR)xyrectangle_main.m $(SRC_DIR)XYPoint.h $(SRC_DIR)XYPoint.m $(SRC_DIR)XYRectangle.h $(SRC_DIR)XYRectangle.m
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS)	
xyrectangle2_main: $(SRC_DIR)xyrectangle2_main.m $(SRC_DIR)XYPoint2.h $(SRC_DIR)XYPoint2.m $(SRC_DIR)XYRectangle2.h $(SRC_DIR)XYRectangle2.m
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS)		

override_main: $(SRC_DIR)override_main.m
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS)

SRC_DIR=../PolyMorphismDynamicTypingBinding/
polymorphism_main: $(SRC_DIR)polymorphism_main.m $(SRC_DIR)Fraction.h $(SRC_DIR)Fraction.m $(SRC_DIR)Complex.h $(SRC_DIR)Complex.m
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS)
staticbinding_main: $(SRC_DIR)staticbinding_main.m $(SRC_DIR)Fraction.h $(SRC_DIR)Fraction.m $(SRC_DIR)Complex.h $(SRC_DIR)Complex.m
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS)	
askQuestionAboutClasses_main: $(SRC_DIR)askQuestionAboutClasses_main.m $(SRC_DIR)Square.h $(SRC_DIR)Square.m $(SRC_DIR)Rectangle.h $(SRC_DIR)Rectangle.m
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS)	
trycatchfinally_main: $(SRC_DIR)trycatchfinally_main.m $(SRC_DIR)Fraction.h $(SRC_DIR)Fraction.m
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS) -fobjc-exceptions
SRC_DIR=../MoreOnVariablesDataTypes/
designatedInitialized_main: $(SRC_DIR)designatedInitialized_main.m $(SRC_DIR)Fraction.h $(SRC_DIR)Fraction.m
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS) -fobjc-exceptions
gGlobal_main: $(SRC_DIR)gGlobal_main.m $(SRC_DIR)Foo.h $(SRC_DIR)Foo.m  
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS) -fobjc-exceptions			
gFractionStatic_main: $(SRC_DIR)gFractionStatic_main.m $(SRC_DIR)Fraction_staticv.h $(SRC_DIR)Fraction_staticv.m  
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS) -fobjc-exceptions		
enum_main: $(SRC_DIR)enum_main.m  
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS) -fobjc-exceptions		
bitoperation_main: $(SRC_DIR)bitoperation_main.m  
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS) -fobjc-exceptions			
SRC_DIR=../CategoriesProtocols/
fraction_categories_main: $(SRC_DIR)fraction_categories_main.m $(SRC_DIR)Fraction.h $(SRC_DIR)Fraction.m $(SRC_DIR)Fraction+MathOps.m $(SRC_DIR)Fraction+MathOps.h
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS) -fobjc-exceptions	

SRC_DIR=../CLanguageFeatures/Misc/
blocks_main: $(SRC_DIR)blocks_main.m
	clang -o $@ $(filter %.m,$^) $(shell gnustep-config --objc-flags) $(shell gnustep-config --base-libs) -fblocks
SRC_DIR=../Foundations/AddressBooks/
addresscard_eg: $(SRC_DIR)addresscard_eg.m $(SRC_DIR)AddressCard.h $(SRC_DIR)AddressCard.m
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS) -fobjc-exceptions	
addresscard_eg2 addresscard_eg3 addressbook_eg: $(SRC_DIR)addresscard_eg.m $(SRC_DIR)AddressCard_SynthProps.h $(SRC_DIR)AddressCard_SynthProps.m
	$(CC) -o $@ $(filter %.m,$^) $(CFLAGS) -fobjc-exceptions
# this is ia very advance itps on how to use the use the empty rule without recipe for target which alreay have a recipe (the target should appear in another recipe as one of the multiple targets)	
addressbook_eg:  $(SRC_DIR)AddressBook.m  $(SRC_DIR)AddressBook.m

CC=clang
SRC_DIR=../MemoryManagementRefCount/
strongvar_eg: $(SRC_DIR)strongvar_eg.m $(SRC_DIR)Fraction.h $(SRC_DIR)Fraction.m
	clang -o $@ $(filter %.m,$^) $(shell gnustep-config --objc-flags) $(shell gnustep-config --base-libs)
SRC_DIR=../CopyingObjects/
mutablecopy_eg: $(SRC_DIR)mutablecopy_eg.m
	clang -o $@ $(filter %.m,$^) $(shell gnustep-config --objc-flags) $(shell gnustep-config --base-libs)
shallowcopy_eg: $(SRC_DIR)shallowcopy_eg.m
	clang -o $@ $(filter %.m,$^) $(shell gnustep-config --objc-flags) $(shell gnustep-config --base-libs)

SRC_DIR=../Archiving/
foo_decode_eg: $(SRC_DIR)foo_decode_eg.m $(SRC_DIR)Foo.h $(SRC_DIR)Foo.m
	clang -o $@ $(filter %.m,$^) $(shell gnustep-config --objc-flags) $(shell gnustep-config --base-libs)
SRC_DIR=../Archiving/customArchiveWithNSData/
nsdata_archive_eg: $(SRC_DIR)nsdata_archive_eg.m $(SRC_DIR)Foo.h $(SRC_DIR)Foo.m $(SRC_DIR)AddressBook.h $(SRC_DIR)AddressBook.m $(SRC_DIR)AddressCard_SynthProps.h $(SRC_DIR)AddressCard_SynthProps.m
	clang -o $@ $(filter %.m,$^) $(shell gnustep-config --objc-flags) $(shell gnustep-config --base-libs)

GUI_SRC_DIR=../iOSApplications/FirstApplication/

gui_apps: $(GUI_SRC_DIR)NSWindowNSButton.app/NSWindowNSButton  $(GUI_SRC_DIR)NSMenuItem.app/NSMenuItem

$(GUI_SRC_DIR)NSMenuItem.app/NSMenuItem: $(GUI_SRC_DIR)NSMenuItem.m
	make -C $(GUI_SRC_DIR)

$(GUI_SRC_DIR)NSWindowNSButton.app/NSWindowNSButton: $(GUI_SRC_DIR)NSWindowNSButton.m
	make -C $(GUI_SRC_DIR)

#$(ALL_PROGS): $(addprefix ../, $(addsuffix .m, $(ALL_PROGS))) 
#$(ALL_PROGS):  $(addsuffix .m, $(ALL_PROGS)) #; you cannot have the extra ; which means this is an empty rule 

# eval function to create 
# rule of something like below. 
#  hello: hello.m
#  world: world.m
#  ...

# $(foreach prog,$(ALL_PROGS),$(eval $(call PROGRAM_template,$(prog))))

#$(eval $(PROGRAM_template))
