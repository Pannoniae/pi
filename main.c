#include <stdio.h>
#include <gmp.h>

void calcpi(mpf_t base, int prec) {

	// 3
	mpf_set_si(base, 3);
	for (int i = 0; i < prec; ++i) {

		mpf_t term;
		mpf_init_set_ui(term, 0);
		mpf_t sign;
		mpf_init_set_d(sign, (i % 2 == 0 ? 1 : -1));
		mpf_t num;
		mpf_init_set_ui(num, 4);
		mpf_t denom;
		mpf_init_set_ui(denom, 0);
		// add 2xi
		mpf_add_ui(denom, denom, 2*i+2);
		// multiply by 2xi+1 and 2xi+2
		mpf_mul_ui(denom, denom, 2*i+3);
		mpf_mul_ui(denom, denom, 2*i+4);
		mpf_div(term, num, denom);

		// multiply by sign
		mpf_mul(term, term, sign);
		// add new term to number
		mpf_add(base, base, term);
		mpf_clear(term);
		mpf_clear(num);
		mpf_clear(denom);
		mpf_clear(sign);
	}
}

int main() {

	int prec = 1;

	printf("Hello, World!\n");

	while (1) {

		// set precision to whatever
		mpf_set_default_prec(69);

		mpf_t base;
		mpf_init(base);
		calcpi(base, prec);
		gmp_printf("PI:%.Ff\n", base);
		mpf_clear(base);
		prec++;
		//break;
	}
	// cleanup
	return 0;
}