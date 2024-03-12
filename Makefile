NAME=scop
CC=g++

SDLINCLUDE=-I ./lib/SDL2/2.30.1/include
SDLLIB=-L ./lib/SDL2/2.30.1/lib -lSDL2
SDLFLAGS=$(SDLINCLUDE) $(SDLLIB)

VULKANINCLUDE=-I ./lib/Vulkan/1.3.280/include

SRC = $(shell find src -name "*.cpp")
SRCDIR = $(sort $(dir $(SRC)))
SRCFLS = $(notdir $(SRC))

OUTPREFIX = builds/
OBJ = $(addprefix $(OUTPREFIX), $(SRCFLS:.cpp=.o))

vpath %.cpp $(SRCDIR)
$(OUTPREFIX)%.o: %.cpp
	@$(CC) $(SDLINCLUDE) $(VULKANINCLUDE) -c $< -o $@

all: outfolder $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(SDLFLAGS)  $(VULKANINCLUDE)

re: fclean all

outfolder:
	@mkdir -p $(OUTPREFIX)

clean:
	@rm -rf $(OUTPREFIX)

fclean: clean
	@rm -f $(NAME)
