APP     = peter-game
CC      = g++
RM      = rm
SRCDIR  = src
SRCEXT  = cpp
OBJDIR  = obj
LIBDIR  = -L./lib
LIB     = -lpdcurses
 
SRCS    := $(shell find $(SRCDIR) -name '*.$(SRCEXT)')
SRCDIRS := $(shell find . -name '*.$(SRCEXT)' -exec dirname {} \; | uniq)
OBJS    := $(patsubst %.$(SRCEXT),$(OBJDIR)/%.o,$(SRCS))

INCLUDE = -I./include
CFLAGS  = -Wall -Werror -std=c++11 -c -O3 $(INCLUDE)

all: $(APP)
 
$(APP): buildrepo $(OBJS)
	$(CC) $(OBJS) $(LIBDIR) -o $@ $(LIB)
	strip *.exe
 
$(OBJDIR)/%.o: %.$(SRCEXT)
	$(CC) $(CFLAGS) $< -o $@ 
 
clean:
	$(RM) -r $(OBJDIR)
 
buildrepo:
	$(call make-repo)
 
define make-repo  
	@for dir in $(SRCDIRS); do mkdir -p $(OBJDIR)/$$dir; done ||:
endef