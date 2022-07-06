clang -o aff_a aff_a.c -Wall -Werror -Wextra
echo "$(./aff_a "abc" | cat -e)"
echo "$(./aff_a "dubO a POIL" | cat -e)"
echo "$(./aff_a "zz sent le poney" | cat -e)"
echo "$(./aff_a | cat -e)"

