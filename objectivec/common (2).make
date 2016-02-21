CFLAGS=-fconstant-string-class=NSConstantString -lobjc -lgnustep-base
MINGW_HOME=c:/ProgramFiles/GNUstep
INCLUDES_PATH=$(MINGW_HOME)/GNUstep/System/Library/Headers
LIBRARIES_PATH=$(MINGW_HOME)/GNUstep/System/Library/Libraries
ALL_SOURCES=$(wildcard *.m)
#ALL_SOURCES+=$(foreach file,$(wildcard ClassObjectMethods/*.m), $(lastword $(subst /, ,$(file))))
#ALL_SOURCES+=$(foreach file,$(wildcard DataTypesExpressions/*.m), $(basename $(notdir $(file))))
#ALL_SOURCES+=$(foreach file,$(wildcard ProgramLoops/*.m), $(basename $(notdir $(file))))
#ALL_SOURCES+=$(foreach file,$(wildcard MakingDecisions/*.m), $(basename $(notdir $(file))))
#ALL_SOURCES+=$(foreach file,$(wildcard MoreOnClasses/*.m), $(basename $(notdir $(file))))
ALL_SOURCES+=rectangle_main.m square_main.m xyrectangle_main.m xyrectangle2_main.m override_main.m
ALL_SOURCES+=polymorphism_main.m staticbinding_main.m askQuestionAboutClasses_main.m
ALL_SOURCES+=trycatchfinally_main.m
ALL_SOURCES+=designatedInitialized_main.m gGlobal_main.m gFractionStatic_main.m enum_main.m bitoperation_main.m
ALL_SOURCES+=fraction_categories_main.m
ALL_PROGS=$(subst .m,,$(ALL_SOURCES))
ALL_PROGS += blocks_main


# addressbook_eg is temporarily disabled
#ALL_PROGS += addresscard_eg addresscard_eg2 addresscard_eg3 addressbook_eg
ALL_PROGS += addresscard_eg addresscard_eg2 addresscard_eg3 

# Memory Management and Reference counting 
ALL_PROGS += strongvar_eg

# copying object
ALL_PROGS += mutablecopy_eg shallowcopy_eg


# archiving
ALL_PROGS += foo_decode_eg nsdata_archive_eg

# gui
ALL_PROGS += gui_apps

CFLAGS += -L${LIBRARIES_PATH} -I${INCLUDES_PATH}
# if your code has the @try-@catch-@finally clause in the code, you might as well include the -fobjc-exceptions in the command line options.
CFLAGS += -fobjc-exceptions
CONFIGURATION=Debug
OBJDIR=$(CONFIGURATION)

