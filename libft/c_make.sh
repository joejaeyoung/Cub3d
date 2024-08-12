#!/bin/bash

# 헬프 메시지 출력 함수
show_help() {
    echo "사용법: ft_make [옵션]"
    echo
    echo "옵션:"
    echo "  -g                컴파일된 객체 파일에 디버깅 심볼을 활성화합니다."
    echo "  --help            이 도움말 메시지를 표시하고 종료합니다."
    echo
    echo "이 스크립트는 C 프로젝트를 위한 Makefile을 생성합니다."
    echo
    echo "다음 정보를 입력하라는 메시지가 표시됩니다:"
    echo "  NAME              - 출력 실행 파일의 이름."
    echo "  SRC_DIR           - 소스 (.c) 파일이 있는 디렉토리."
    echo "  INC_DIR           - 헤더 (.h) 파일이 있는 디렉토리."
    echo "  LIBFT             - libft 라이브러리를 포함할지 여부 (y/n)."
    echo "  BONUS             - 보너스 파일을 포함할지 여부 (y/n)."
    echo
    echo "이 스크립트를 ~/.zshrc 파일에 alias로 추가하려면 다음 명령어를 사용하세요:"
    echo -e "  \033[1;33mecho 'alias ft_make=\"/path/to/ft_make\"' >> ~/.zshrc\033[0m"
    echo "그런 다음, 다음 명령어로 쉘 구성을 다시 로드하세요:"
    echo -e "  \033[1;33msource ~/.zshrc\033[0m"
    echo "여기서 /path/to/ft_make를 이 스크립트의 실제 경로로 바꿔주세요."
    exit 0
}

# --help 옵션 처리
if [ "$1" == "--help" ]; then
    show_help
fi

# 기본 CFLAGS 설정
CFLAGS="-Wall -Wextra -Werror"

# -g 옵션이 있는지 확인
if [ "$1" == "-g" ]; then
    CFLAGS="$CFLAGS -g"
fi

# 사용자 입력 받기
echo -n "NAME = "
read name

echo -n "SRC_DIR = "
read src_dir

echo -n "INC_DIR = "
read inc_dir

# LIBFT 입력 받기
while true; do
    echo -n "LIBFT? [y/n] "
    read libft
    case $libft in
        [Yy]* ) 
            echo -n "LIBFT_DIR = "
            read libft_dir
            break;;
        [Nn]* ) 
            libft="n"
            break;;
        * ) echo "y 또는 n으로 대답해 주세요.";;
    esac
done

# BONUS 입력 받기
while true; do
    echo -n "BONUS? [y/n] "
    read bonus
    case $bonus in
        [Yy]* ) 
            echo -n "BNS_NAME = "
            read bns_name

            echo -n "BNS_SRC_DIR = "
            read bns_src_dir

            echo -n "BNS_INC_DIR = "
            read bns_inc_dir
            break;;
        [Nn]* ) 
            bonus="n"
            break;;
        * ) echo "y 또는 n으로 대답해 주세요.";;
    esac
done

# SRC_DIR과 INC_DIR에서 파일 목록 가져오기
src_files=$(ls $src_dir/*.c 2> /dev/null | xargs -n 1 basename | tr '\n' ' ')

# Makefile 내용 작성
makefile_content="BLUE := \033[0;36m
RESET := \033[0m

RED_START := 255
GREEN_START := 0
RED_END := 0
GREEN_END := 255

PROGRESS = 0
COUNT = \$(words \$(SRCS))
DONE = 0
BAR_FILLED = 0
BAR_EMPTY = 60

CC := cc
CFLAGS := $CFLAGS
RM := rm -f

# MANDATORY PART
NAME := $name

SRC_DIR := $src_dir
INC_DIR := $inc_dir"
if [ "$libft" == "y" ]; then
    makefile_content="$makefile_content
LIBFT_DIR := $libft_dir
LIBFT := \$(LIBFT_DIR)/libft.a
"
fi

makefile_content="$makefile_content
SRCS := $src_files
OBJS := \$(SRCS:.c=.o)

.PHONY : all start clean fclean re

all : \$(NAME)

\$(NAME) : "
if [ "$libft" == "y" ]; then
    makefile_content="$makefile_content
	@make -C \$(LIBFT_DIR) all --no-print-directory
	@echo
	@echo"
fi
makefile_content="$makefile_content
	@make start --no-print-directory
	@\$(CC) \$(CFLAGS) \$(OBJS) "
if [ "$libft" == "y" ]; then
    makefile_content="$makefile_content\$(LIBFT) "
fi
makefile_content="$makefile_content-iquote \$(INC_DIR) -o \$(NAME)
	@echo \"  Completed! \"
	
start : \$(OBJS)

%.o : \$(SRC_DIR)/%.c
	@\$(CC) \$(CFLAGS) -c \$< -o \$@
	@\$(eval DONE := \$(shell echo \$\$((\$(DONE) + 1))))
	@\$(eval PROGRESS := \$(shell echo \$\$((\$(DONE) * 100 / \$(COUNT)))))
	@RED=\$\$((\$(RED_START) + \$(PROGRESS) * (\$(RED_END) - \$(RED_START)) / 100)); \\
	GREEN=\$\$((\$(GREEN_START) + \$(PROGRESS) * (\$(GREEN_END) - \$(GREEN_START)) / 100)); \\
	COLOR=\"\033[38;2;\$\$RED;\$\$GREEN;0m\"; \\
	printf \"\033[2A\033[K  Currently working on: \$(BLUE)\$<\$(RESET)\n\"; \\
	printf \"\$\$COLOR\033[K    %3d\$(RESET)%%│\$\$COLOR\" \$(PROGRESS); \\
	BAR_FILLED=\$\$((\$(PROGRESS) / 5 * 3)); \\
	BAR_EMPTY=\$\$((60 - \$\$BAR_FILLED)); \\
	for i in \$\$(seq 1 \$\$BAR_FILLED); do \\
		printf \"█\"; \\
	done; \\
	for i in \$\$(seq 1 \$\$BAR_EMPTY); do \\
		printf \" \"; \\
	done; \\
	printf \"\$(RESET)│\n\"

clean :"
if [ "$libft" == "y" ]; then
    makefile_content="$makefile_content
	@make -C \$(LIBFT_DIR) clean --no-print-directory"
fi
makefile_content="$makefile_content
	@\$(RM) \$(OBJS)"
if [ "$bonus" == "y" ]; then
    makefile_content="$makefile_content
	@\$(RM) \$(BNS_OBJS)"
fi

makefile_content="$makefile_content
	@echo \"  All object files are deleted.\"

fclean :"
if [ "$libft" == "y" ]; then
    makefile_content="$makefile_content
	@make -C \$(LIBFT_DIR) fclean --no-print-directory"
fi
makefile_content="$makefile_content
	@\$(RM) \$(OBJS)
	@\$(RM) \$(NAME)"
if [ "$bonus" == "y" ]; then
    makefile_content="$makefile_content
	@\$(RM) \$(BNS_OBJS)
	@\$(RM) \$(BNS_NAME)"
fi

if [ "$bonus" == "y" ]; then
	makefile_content="$makefile_content
	@echo \"  All object files, \$(BLUE)\$(NAME)\$(RESET), and \$(VIOLET)\$(BNS_NAME)\$(RESET) are deleted.\""
fi
if [ "$bonus" == "n" ]; then
	makefile_content="$makefile_content
	@echo \"  All object files and \$(BLUE)\$(NAME)\$(RESET) are deleted.\""
fi

makefile_content="$makefile_content
re :
	@make fclean --no-print-directory
	@echo
	@make all --no-print-directory
"

# 보너스 디렉토리 및 파일 추가
if [ "$bonus" == "y" ]; then
    bns_src_files=$(ls $bns_src_dir/*.c 2> /dev/null | xargs -n 1 basename | tr '\n' ' ')
    
    makefile_content="$makefile_content

# BONUS PART
BNS_NAME := $bns_name

BNS_SRC_DIR := $bns_src_dir
BNS_INC_DIR := $bns_inc_dir

BNS_SRCS := $bns_src_files
BNS_OBJS := \$(BNS_SRCS:.c=.o)

VIOLET := \033[0;35m
BNS_COUNT = \$(words \$(BNS_SRCS))

.PHONY : bonus bonus_start

bonus : \$(BNS_NAME)

\$(BNS_NAME) : "
if [ "$libft" == "y" ]; then
    makefile_content="$makefile_content
	@make -C \$(LIBFT_DIR) all --no-print-directory
	@echo
	@echo"
fi
makefile_content="$makefile_content
	@make bonus_start --no-print-directory
	@\$(CC) \$(CFLAGS) \$(BNS_OBJS) "
if [ "$libft" == "y" ]; then
    makefile_content="$makefile_content\$(LIBFT) "
fi
makefile_content="$makefile_content-iquote \$(BNS_INC_DIR) -o \$(BNS_NAME)
	@echo \"  Completed! \"
	
bonus_start : \$(BNS_OBJS)

%.o : \$(BNS_SRC_DIR)/%.c
	@\$(CC) \$(CFLAGS) -c \$< -o \$@
	@\$(eval DONE := \$(shell echo \$\$((\$(DONE) + 1))))
	@\$(eval PROGRESS := \$(shell echo \$\$((\$(DONE) * 100 / \$(BNS_COUNT)))))
	@RED=\$\$((\$(RED_START) + \$(PROGRESS) * (\$(RED_END) - \$(RED_START)) / 100)); \\
	GREEN=\$\$((\$(GREEN_START) + \$(PROGRESS) * (\$(GREEN_END) - \$(GREEN_START)) / 100)); \\
	COLOR=\"\033[38;2;\$\$RED;\$\$GREEN;0m\"; \\
	printf \"\033[2A\033[K  Currently working on: \$(VIOLET)\$<\$(RESET)\n\"; \\
	printf \"\$\$COLOR\033[K    %3d\$(RESET)%%│\$\$COLOR\" \$(PROGRESS); \\
	BAR_FILLED=\$\$((\$(PROGRESS) / 5 * 3)); \\
	BAR_EMPTY=\$\$((60 - \$\$BAR_FILLED)); \\
	for i in \$\$(seq 1 \$\$BAR_FILLED); do \\
		printf \"█\"; \\
	done; \\
	for i in \$\$(seq 1 \$\$BAR_EMPTY); do \\
		printf \" \"; \\
	done; \\
	printf \"\$(RESET)│\n\""
fi

# Makefile 생성
echo "$makefile_content" > Makefile
echo "Makefile이 생성되었습니다."

