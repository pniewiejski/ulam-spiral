set -x
for DIR in ./src ./include ./test
do
    find $DIR -regex '.*\.[ch]p*' -exec clang-format -style=file -output-replacements-xml {} \; |
    grep -c "<replacement " > /dev/null
    if [ $? -ne 1 ]; then 
        echo "Commit did not match clang-format"
        exit 1
    fi
done 
