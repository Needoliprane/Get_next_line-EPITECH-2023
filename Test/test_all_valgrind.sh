./compiler_script.sh

echo "compilation done

"
echo "---TEST 1---"
echo "gnl : 
"
valgrind ./read_fd test_file/test1 | cat -e
echo "
cat : 
"
cat -e test_file/test1
echo "
---TEST 2---"
echo "gnl : 
"
valgrind ./read_fd test_file/test2 | cat -e
echo "
cat : 
"
cat -e test_file/test2
echo "
---TEST 3---"
echo "gnl : 
"
valgrind ./read_fd test_file/test3 | cat -e
echo "cat : 
"
cat -e test_file/test3