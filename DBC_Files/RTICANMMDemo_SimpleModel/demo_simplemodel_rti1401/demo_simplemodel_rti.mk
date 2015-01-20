# =============================================================================
#  Make include file demo_simplemodel_rti.mk:
#
#   RTI1401 7.2 (02-May-2014)
#   Tue Jan 13 20:10:56 2015
#
#   Copyright (c) 1999-2002 dSPACE GmbH, GERMANY
# =============================================================================

# Initialize variables used in blockset makefiles -----------------------------

BLOCKSET_LIBS     :=
BLOCKSET_SRCS     :=
BLOCKSET_INCLUDES :=

# Default rules for additional blocksets --------------------------------------

blockset_init          :
blockset_clean         :
blockset_deps          :
blockset_after_linkage :

# Includes for additional blocksets -------------------------------------------



# Model-specific options ------------------------------------------------------

# Additional C source files declared by the model
MDL_CUSTOM_C_SRCS = rti_assert.c

# Additional assembler source files declared by the model
MDL_CUSTOM_ASM_SRCS =

# Additional libraries declared by the model
MDL_CUSTOM_LIBS = \
  "$(DSPACE_ROOT)\DS1401\RTPython\dsrtt1401.lib"

# Additional objects declared by the model
MDL_CUSTOM_OBJS =

# Directories where additional C and assembler source files are stored
MDL_CUSTOM_SRCS_DIR =

# Directories where additional header files are stored
MDL_CUSTOM_INCLUDES_PATH = \
  "$(DSPACE_ROOT)\DS1401\RTPython"


# Define build type information
BUILDTYPE = RTI


# EOF -------------------------------------------------------------------------
