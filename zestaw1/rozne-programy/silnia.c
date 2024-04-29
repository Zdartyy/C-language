#include <stdio.h>

int silnia(int n) {
    /* rekurencja polega na wywoływaniu funkcji wewnątrz 'samej siebie'
     * przykłady tego mogą być bardziej skomplikowane, jak np. skakanie
     * pomiędzy kilkoma funkcjami.
     * żeby program nam działał poprawnie, należy pamiętać o warunku 'indukcyjnym'
     * czyli wracającym o krok wcześniej; oraz o warunku brzegowym do którego
     * redukuje się problem */
     
	if (n == 0)  
		return 1; 
	else
		return silnia(n-1) * n;
}

int silnia_iteracja(int n) {
    /* czasem łatwiej jest iteracyjnie! */
    int silnia = 1, i;
    for(i = 1; i <= n; i++){
        /* korzystamy ze skrótowej formy zapisania mnożenia, tak samo można zapisywać np dodawanie bądź odejmowanie */
        silnia *= i;
    }
    return silnia;
}

int main(void) {

	printf("5! rekurencyjnie: %d\n", silnia(5));
	printf("5! iteracyjnie: %d\n", silnia_iteracja(5));
 	
	return 0;
}
