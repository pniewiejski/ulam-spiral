set -xe
for DIR in ./src ./include ./test
do
    find $DIR -regex '.*\.[ch]p*' -exec clang-format -style=file -i {} \;
done 
