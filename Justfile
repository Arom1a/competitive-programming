set shell := ["bash", "-c"]

cc := "g++"
# flags: [Catching silly mistakes with GCC](https://codeforces.com/blog/entry/15547)
flags := "-Wall -Wextra -O2 -pedantic -std=c++17 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector "
root_dir := justfile_directory()
build_dir := justfile_directory() + "/.build"
source_dir := invocation_directory()


alias t := template
template:
    #!/usr/bin/env zsh
    alacritty --working-directory "{{root_dir}}/templates" -e "nvim" "." &


alias n := new
new target:
    #!/usr/bin/env bash
    set -e

    FILENAME="{{target}}"
    NAME="${FILENAME%.cpp}"
    TEMPLATE_PATH="{{root_dir}}/templates/template.cpp"
    NEW_FILE="{{source_dir}}/$NAME.cpp"
    NEW_INPUT="{{source_dir}}/$NAME.in"

    # Check if already exists
    if [ -f "$NEW_FILE" ]; then
        echo -e "\033[1;31m[Error] File already exists: $NEW_FILE\033[0m"
        exit 1
    fi

    cp "$TEMPLATE_PATH" "$NEW_FILE"
    echo -e "\033[1;32m[Created] $NAME.cpp\033[0m"
    touch "$NEW_INPUT"


alias b := build
build target:
    #!/usr/bin/env bash
    set -e

    mkdir -p "{{build_dir}}"
    FILENAME="{{target}}"
    NAME="${FILENAME%.cpp}"
    SRC_PATH="{{source_dir}}/$NAME.cpp"
    PATH_MDSUM=`echo "$SRC_PATH" | md5sum | awk '{print $1}'`
    BIN_PATH="{{build_dir}}/${NAME}_${PATH_MDSUM}"

    # Smart Compile (Only if source is newer than binary)
    if [[ ! -f "$BIN_PATH" || "$SRC_PATH" -nt "$BIN_PATH" ]]; then
        echo -e "\033[1;34m[Building] Changes detected in $NAME.cpp...\033[0m"
        {{cc}} {{flags}} "$SRC_PATH" -o "$BIN_PATH"
    else
        echo -e "\033[1;32m[Skipped] No changes detected. Using existing binary.\033[0m"
    fi


alias r := run
run target: (build target)
    #!/usr/bin/env bash
    set -e

    FILENAME="{{target}}"
    NAME="${FILENAME%.cpp}"
    SRC_PATH="{{source_dir}}/$NAME.cpp"
    PATH_MDSUM=`echo "$SRC_PATH" | md5sum | awk '{print $1}'`
    BIN_PATH="{{build_dir}}/${NAME}_${PATH_MDSUM}"
    INPUT_PATH="{{source_dir}}/$FILENAME.in"

    echo -e "\033[1;32m[Running] $NAME...\033[0m"

    if [ -f "$INPUT_PATH" ]; then
        echo -e "\033[0;33m(Reading from $NAME.in)\033[0m"
        "$BIN_PATH" < "$INPUT_PATH"
    else
        echo -e "\033[0;33m(Reading from terminal)\033[0m"
        "$BIN_PATH"
    fi


clean:
    rm -rf "{{build_dir}}"
    echo "Build cache cleared."
