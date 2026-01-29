cc := "g++"
# flags: [Catching silly mistakes with GCC](https://codeforces.com/blog/entry/15547)
flags := "-Wall -Wextra -O2 -pedantic -std=c++17 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector "

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
