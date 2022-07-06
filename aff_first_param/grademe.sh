clang -o aff_first_param aff_first_param.c -Wall -Werror -Wextra
echo "$(./aff_first_param vincent mit "l'ane" dans un pre et "s'en" vint | cat -e)"
echo "$(./aff_first_param "j'aime le fromage de chevre" | cat -e)"
echo "$(./aff_first_param)"
