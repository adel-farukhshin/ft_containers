project					:= project

inc_dir					:= ./inc
includes				:= ${inc_dir}/*

src_dir					:= ./src
sources					:= $(wildcard ${src_dir}/*.cpp)

build_dir				:= ./build
obj_dir					:= ${build_dir}/obj
bin_dir					:= ${build_dir}/bin
build_dirs				:= ${obj_dir} ${bin_dir}
executable				:= ${bin_dir}/${project}
objects					:= $(subst .cpp,.o,$(subst ${src_dir},${obj_dir},${sources}))

dirs					:= ${inc_dir} ${src_dir} ${build_dirs}
build_dirs				:= ${obj_dir} ${bin_dir}

CC						:= c++
CPPFLAGS				:= -Wall -Wextra -Werror  -I${inc_dir} -std=c++98 -g

.PHONY: all  clean fclean re run 

all: ${executable}

setup:
	mkdir -p ${dirs}

run: ${executable} 
	@${^} ${ARGS}

${executable}: ${objects} ${includes} | ${bin_dir}
	${CC} ${CPPFLAGS} -I ${inc_dir} -o ${@} ${^}

${obj_dir}/%.o: ${src_dir}/%.cpp | ${obj_dir}
	${CC} ${CPPFLAGS} -I ${inc_dir} -c -o ${@} ${<}

${build_dirs}:
	mkdir -p ${@}

clean:
	rm -f ${objects}

fclean: clean
	rm -f ${executable}

re: fclean all
