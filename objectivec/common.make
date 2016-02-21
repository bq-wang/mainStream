MINGW_HOME=c:/MinGW/GNUstep
MSYS_HOME=$(MINGW_HOME)/msys/1.0
LIBRARIES_PATH=$(MINGW_HOME)/GNUstep/System/Library/Libraries
ADDITIONAL_INCLUDE_PATH = /mingw/include
INCLUDES_PATH=$(MINGW_HOME)/GNUstep/System/Library/Headers
CFLAGS=-fconstant-string-class=NSConstantString -L${LIBRARIES_PATH} -I${INCLUDES_PATH} -I${ADDITIONAL_INCLUDE_PATH}
CLIBS=-lobjc -lgnustep-base
CFLAGS += $(CLIBS)
#CC=gcc
CC=clang
# ALL_SOURCES=$(wildcard *.m)
# ALL_SOURCES+=$(wildcard ClassObjectMethods/*.m)
# ALL_PROGS=$(foreach f,$(ALL_SOURCES),$(basename $(lastword $(subst /, ,$(f)))))
ALL_PROGS += arrayInitializer multiArrayInitializer
# ALL_PROGS += blocks blocksApplicationEg1  
ALL_PROGS += structureEg1 structure_initializer
ALL_PROGS += pointerEg1
ALL_PROGS += compoundLiterals
ALL_PROGS += commandline_eg_lookup
ALL_PROGS += nsnumbers_eg
ALL_PROGS += nsstrings_eg fraction_description mutable_immutable basic_string_op_eg array_eg mutable_nsmutablearray
ALL_PROGS += addresscard_test1 addresscard_test2 addressbook_test1
# because we don't have the CoreGraphics/CoreGraphics.h, we cannot build the following code.
# 
# ALL_PROGS += nsvalue_eg
ALL_PROGS += dictionaries_eg dictionaries_eg2 nsset_eg
ALL_PROGS += nsfilemanager_eg
ALL_PROGS += nsfilemanager_readfile_eg
ALL_PROGS += nsfilemanager_dirs_eg nsfilemanager_dirs_enumerate nsfilemanager_dirs_toplevelenumerate nsfilemanager_nspathutilities

ALL_PROGS += paths_eg 
ALL_PROGS += copy_eg nsfilehandle_eg append_eg 

ALL_PROGS += nsurl_eg

#the Copying Object parts
ALL_PROGS += addressbook_nscopy_eg nscopyimpl_eg

# Memory management
ALL_PROGS += manual_release_eg

# archiving
ALL_PROGS += xmlproplists_eg xmlproplists_read_eg nskeyedarchive_write_eg nskeyedarchive_read_eg codec_encode_eg codec_decode_eg archiver_copyobj_eg

# we will handle the GUI apps generation to the underlying GUI libs
ALL_PROGS += gui_apps
