echo "
By default the read size is 1, but with that said you can change it in get_next_line.h (#define SIZE ...)"

gcc -Wall -Wextra -Werror ../get_next_line.c main_read_fd.c -o read_fd -g3

echo "
read_fd usage : ./read_fd file

"

gcc -Wall -Wextra -Werror ../get_next_line.c main_read_standart_input.c -o read_standard_input -g3 

echo "read_standart_input usage : ./read_standart_input
Then write whatever you want, and press enter.
To stop Ctrl + c
"

echo "
La doc, c'est comme le PQ: ça sert à se démerder tout seul


By Needoliprane"
