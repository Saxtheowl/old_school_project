NAME    = 	bomber

DIR	=	src_bomber/

SRCS    =       $(DIR)main.cpp \
		$(DIR)GameMain.cpp \
		$(DIR)Map.cpp \
		$(DIR)Case.cpp \
		$(DIR)Floor.cpp \
		$(DIR)Bomb.cpp \
		$(DIR)AObject.cpp \
		$(DIR)Cube.cpp \
		$(DIR)Mod.cpp \
		$(DIR)Player.cpp \
		$(DIR)Block.cpp \
		$(DIR)Bonus.cpp \
		$(DIR)Wall.cpp \
		$(DIR)Graphic.cpp \
		$(DIR)PInput.cpp

OBJS    = $(SRCS:.cpp=.o)

CC      = clang++

RM      = rm -f

CXXFLAGS += -Wall -Wextra -ansi -g3 -I includes/

LDFLAGS  += -Llibs/ -lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -Wl,-rpath=./libs/ -ldl

all     : $(NAME)

$(NAME) : $(OBJS)
	        $(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
clean   :
	$(RM) $(OBJS)

fclean  : clean
	$(RM) $(NAME)

re      : fclean all
