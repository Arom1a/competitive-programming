cc := "g++"
flags := "-std=c++17 -Wall -Wextra -O2 -fsanitize=address,undefined -DLOCAL"

build_dir := justfile_directory() + "/.build"
source_dir := invocation_directory()


run target:
    #!/usr/bin/env bash
    mkdir -p "{{build_dir}}"

    FILENAME="{{target}}"
    NAME="${FILENAME%.cpp}"

    echo -e "\033[1;34m[Building] $NAME.cpp from {{source_dir}}...\033[0m"

    {{cc}} {{flags}} "{{source_dir}}/$NAME.cpp" -o "{{build_dir}}/$NAME"

    if [ $? -ne 0 ]; then
        echo -e "\033[1;31m[Error] Compilation Failed\033[0m"
        exit 1
    fi

    echo -e "\033[1;32m[Running] $NAME...\033[0m"
    "{{build_dir}}/$NAME"
