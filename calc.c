#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned int bit1 : 1;
	unsigned int bit2 : 1;
	unsigned int bit3 : 1;
	unsigned int bit4 : 1;
	unsigned int bit5 : 1;
	unsigned int bit6 : 1;
	unsigned int bit7 : 1;
	unsigned int bit8 : 1;
} reg;

reg reg1;
reg reg2;
reg reg3;
reg reg4;

void reg2_minus_reg3() {
	// reg4.bit8 buat simpenan
	reg4.bit8 = 0;
	if (reg3.bit1) { // karena reg3.bit1 udh ga kepake bisa dipake buat nyimpen angka kalo 1 + 1
		reg4.bit8 = ~reg2.bit1; // nyimpen / ga
		reg2.bit1 = ~reg2.bit1; //update reg2
	}
	if (reg3.bit2 != reg4.bit8)  {
		reg4.bit8 = ~reg2.bit2; // nyimpen / ga
		reg2.bit2 = ~reg2.bit2; //update reg2
	}
	if (reg3.bit3 != reg4.bit8)  {
		reg4.bit8 = ~reg2.bit3; // nyimpen / ga
		reg2.bit3 = ~reg2.bit3; //update reg2
	}
	if (reg3.bit4 != reg4.bit8)  {
		reg4.bit8 = ~reg2.bit4; // nyimpen / ga
		reg2.bit4 = ~reg2.bit4; //update reg2
	}
	if (reg3.bit5 != reg4.bit8)  {
		reg4.bit8 = ~reg2.bit5; // nyimpen / ga
		reg2.bit5 = ~reg2.bit5; //update reg2
	}
	if (reg3.bit6 != reg4.bit8)  {
		reg4.bit8 = ~reg2.bit6; // nyimpen / ga
		reg2.bit6 = ~reg2.bit6; //update reg2
	}
	if (reg3.bit7 != reg4.bit8)  {
		reg4.bit8 = ~reg2.bit7; // nyimpen / ga
		reg2.bit7 = ~reg2.bit7; //update reg2
	} 
	if (reg3.bit8 != reg4.bit8)  {
		reg4.bit8 = ~reg2.bit8; // nyimpen / ga
		reg2.bit8 = ~reg2.bit8; //update reg2
	}
}

void reg2_plus_reg3() {
	// reg4.bit8 buat simpenan
	reg4.bit8 = 0;
	if (reg3.bit1) { // karena reg3.bit1 udh ga kepake bisa dipake buat nyimpen angka kalo 1 + 1
		reg4.bit8 = reg2.bit1; // nyimpen / ga
		reg2.bit1 = ~reg2.bit1; //update reg2
	}
	if (reg3.bit2 != reg4.bit8)  {
		reg4.bit8 = reg2.bit2; // nyimpen / ga
		reg2.bit2 = ~reg2.bit2; //update reg2
	}
	if (reg3.bit3 != reg4.bit8)  {
		reg4.bit8 = reg2.bit3; // nyimpen / ga
		reg2.bit3 = ~reg2.bit3; //update reg2
	}
	if (reg3.bit4 != reg4.bit8)  {
		reg4.bit8 = reg2.bit4; // nyimpen / ga
		reg2.bit4 = ~reg2.bit4; //update reg2
	}
	if (reg3.bit5 != reg4.bit8)  {
		reg4.bit8 = reg2.bit5; // nyimpen / ga
		reg2.bit5 = ~reg2.bit5; //update reg2
	}
	if (reg3.bit6 != reg4.bit8)  {
		reg4.bit8 = reg2.bit6; // nyimpen / ga
		reg2.bit6 = ~reg2.bit6; //update reg2
	}
	if (reg3.bit7 != reg4.bit8)  {
		reg4.bit8 = reg2.bit7; // nyimpen / ga
		reg2.bit7 = ~reg2.bit7; //update reg2
	} 
	if (reg3.bit8 != reg4.bit8)  {
		reg4.bit8 = reg2.bit8; // nyimpen / ga
		reg2.bit8 = ~reg2.bit8; //update reg2
	}
}

void loop_mult() {
	if (reg1.bit1 && !reg4.bit6) { // 10
		reg2_minus_reg3();
	} else if (!reg1.bit1 && reg4.bit6) { //01
		reg2_plus_reg3();
	}
	reg4.bit6 = reg1.bit1;
	reg1.bit1 = reg1.bit2;
	reg1.bit2 = reg1.bit3;
	reg1.bit3 = reg1.bit4;
	reg1.bit4 = reg1.bit5;
	reg1.bit5 = reg1.bit6;
	reg1.bit6 = reg1.bit7;
	reg1.bit7 = reg1.bit8;
	reg1.bit8 = reg2.bit1;
	reg2.bit1 = reg2.bit2;
	reg2.bit2 = reg2.bit3;
	reg2.bit3 = reg2.bit4;
	reg2.bit4 = reg2.bit5;
	reg2.bit5 = reg2.bit6;
	reg2.bit6 = reg2.bit7;
	reg2.bit7 = reg2.bit8;
	reg2.bit8 = 1;
}

void loop_div() {
	loop_division:
	reg2.bit8 = reg2.bit7;
	reg2.bit7 = reg2.bit6;
	reg2.bit6 = reg2.bit5;
	reg2.bit5 = reg2.bit4;
	reg2.bit4 = reg2.bit3;
	reg2.bit3 = reg2.bit2;
	reg2.bit2 = reg2.bit1;
	reg2.bit1 = reg1.bit8;
	reg1.bit8 = reg1.bit7;
	reg1.bit7 = reg1.bit6;
	reg1.bit6 = reg1.bit5;
	reg1.bit5 = reg1.bit4;
	reg1.bit4 = reg1.bit3;
	reg1.bit3 = reg1.bit2;
	reg1.bit2 = reg1.bit1;
	reg1.bit1 = 0;
	
	if (reg2.bit8) reg2_plus_reg3();
	else reg2_minus_reg3();
	reg1.bit1 = ~reg2.bit8;
}


int main(int argc, char* argv[]){
	int res;
	
	FILE *file = fopen(argv[1], "r");
	char c;

	if (file == NULL) {
		printf("File not found!\n");
		exit(1);
	}

	// most significant bit = bit8
	// reg1 = retval / left operand
	// reg2 right operand, temp reg
	// reg3 buat bantu reg2 nyimpen nilai yg dibaca
	// reg4 operator
	printf("isi file = ");
	while ((c = fgetc(file)) != EOF) {
		printf("%c", c);
		// print coba
		// convert ke dec
		// kalo angka simpan di reg1
		if (c >= 48 && c <= 57) {
			// simpan nilai lama reg2 dikali 2 ke reg3
			// reg3 = reg2 + reg2
			// ingat reg3 ga bersih jd harus ditangani semua kondisi
			reg3.bit1 = 0;
			reg3.bit2 = reg2.bit1;
			reg3.bit3 = reg2.bit2;
			reg3.bit4 = reg2.bit3;
			reg3.bit5 = reg2.bit4;
			reg3.bit6 = reg2.bit5;
			reg3.bit7 = reg2.bit6;
			reg3.bit8 = reg2.bit7;
			// kalo c bukan digit pertama / tidak semuanya = 0
			if (!(reg2.bit1 == 0 && reg2.bit2 == 0
				&& reg2.bit3 == 0 && reg2.bit4 == 0
				&& reg2.bit5 == 0 && reg2.bit6 == 0
				&& reg2.bit7 == 0 && reg2.bit8 == 0 )) {
					// brrti 
					reg4.bit5 = 1;
					goto update_reg2;
				}
			update_reg3:
				// update reg3 = c
				reg3.bit1 = 0;
				reg3.bit2 = 0;
				reg3.bit3 = 0;
				reg3.bit4 = 0;
				reg3.bit5 = 0;
				reg3.bit6 = 0;
				reg3.bit7 = 0;
				reg3.bit8 = 0;
				if (c == '1') { // 1
					reg3.bit1 = 1;
				} else if (c == '2') { // 2
					reg3.bit2 = 1;
				} else if (c == '3') { // 3
					reg3.bit1 = 1;
					reg3.bit2 = 1;
				} else if (c == '4') { // 4
					reg3.bit3 = 1;
				} else if (c == '5') { // 5
					reg3.bit3 = 1;
					reg3.bit1 = 1;
				} else if (c == '6') { // 6
					reg3.bit2 = 1;
					reg3.bit3 = 1;
				} else if (c == '7') { // 7
					reg3.bit1 = 1;
					reg3.bit2 = 1;
					reg3.bit3 = 1;
				} else if (c == '8') { // 8
					reg3.bit4 = 1;
				} else if (c == '9') { // 9
					reg3.bit4 = 1;
					reg3.bit1 = 1;
				}
				goto fix_reg2;
			update_reg2:
				// shift kiri 3
				reg2.bit8 = reg2.bit5;
				reg2.bit7 = reg2.bit4;
				reg2.bit6 = reg2.bit3;
				reg2.bit5 = reg2.bit2;
				reg2.bit4 = reg2.bit1;
				reg2.bit3 = 0;
				reg2.bit2 = 0;
				reg2.bit1 = 0;
				// tambah reg3
			fix_reg2:
				reg2_plus_reg3();
				
			if (reg4.bit5 == 1) {
				reg4.bit5 = 0;
				goto update_reg3;
			}
			// kalo gaada operan sebelumnya brrti pindahin ke reg1
			if (reg4.bit1 == 0 && reg4.bit2 == 0 && reg4.bit3 == 0 && reg4.bit4 == 0) {
				reg1.bit1 = reg2.bit1;
				reg1.bit2 = reg2.bit2;
				reg1.bit3 = reg2.bit3;
				reg1.bit4 = reg2.bit4;
				reg1.bit5 = reg2.bit5;
				reg1.bit6 = reg2.bit6;
				reg1.bit7 = reg2.bit7;
				reg1.bit8 = reg2.bit8;
			}
			
		} else { // kalo baca operator
			itung_operator:
			if (reg4.bit1 == 1) { //operasi +
				// reg1 += reg2
				tambah:
				reg4.bit8 = 0;
				// reg4.bit8 buat simpenan
				if (reg2.bit1) { // karena reg2.bit1 udh ga kepake bisa dipake buat nyimpen angka kalo 1 + 1
					reg4.bit8 = reg1.bit1; // nyimpen / ga
					reg1.bit1 = ~reg1.bit1; //update reg1
				}
				if (reg2.bit2 != reg4.bit8)  {
					reg4.bit8 = reg1.bit2; // nyimpen / ga
					reg1.bit2 = ~reg1.bit2; //update reg1
				}
				if (reg2.bit3 != reg4.bit8)  {
					reg4.bit8 = reg1.bit3; // nyimpen / ga
					reg1.bit3 = ~reg1.bit3; //update reg1
				}
				if (reg2.bit4 != reg4.bit8)  {
					reg4.bit8 = reg1.bit4; // nyimpen / ga
					reg1.bit4 = ~reg1.bit4; //update reg1
				}
				if (reg2.bit5 != reg4.bit8)  {
					reg4.bit8 = reg1.bit5; // nyimpen / ga
					reg1.bit5 = ~reg1.bit5; //update reg1
				}
				if (reg2.bit6 != reg4.bit8)  {
					reg4.bit8 = reg1.bit6; // nyimpen / ga
					reg1.bit6 = ~reg1.bit6; //update reg1
				}
				if (reg2.bit7 != reg4.bit8)  {
					reg4.bit8 = reg1.bit7; // nyimpen / ga
					reg1.bit7 = ~reg1.bit7; //update reg1
				} 
				if (reg2.bit8 != reg4.bit8)  {
					reg4.bit8 = reg1.bit8; // nyimpen / ga
					reg1.bit8 = ~reg1.bit8; //update reg1
				}
			} else if (reg4.bit2 == 1) { //operasi -
				kurang:
				if (reg2.bit1) { // karena reg2.bit1 udh ga kepake bisa dipake buat nyimpen angka kalo 1 + 1
					reg2.bit1 = ~reg1.bit1; // nyimpen / ga
					reg1.bit1 = ~reg1.bit1; //update reg1
				}
				if (reg2.bit2 != reg2.bit1)  {
					reg2.bit2 = ~reg1.bit2; // nyimpen / ga
					reg1.bit2 = ~reg1.bit2; //update reg1
				}
				if (reg2.bit3 != reg2.bit2)  {
					reg2.bit3 = ~reg1.bit3; // nyimpen / ga
					reg1.bit3 = ~reg1.bit3; //update reg1
				}
				if (reg2.bit4 != reg2.bit3)  {
					reg2.bit4 = ~reg1.bit4; // nyimpen / ga
					reg1.bit4 = ~reg1.bit4; //update reg1
				}
				if (reg2.bit5 != reg2.bit4)  {
					reg2.bit5 = ~reg1.bit5; // nyimpen / ga
					reg1.bit5 = ~reg1.bit5; //update reg1
				}
				if (reg2.bit6 != reg2.bit5)  {
					reg2.bit6 = ~reg1.bit6; // nyimpen / ga
					reg1.bit6 = ~reg1.bit6; //update reg1
				}
				if (reg2.bit7 != reg2.bit6)  {
					reg2.bit7 = ~reg1.bit7; // nyimpen / ga
					reg1.bit7 = ~reg1.bit7; //update reg1
				} 
				if (reg2.bit8 != reg2.bit7)  {
					reg2.bit8 = ~reg1.bit8; // nyimpen / ga
					reg1.bit8 = ~reg1.bit8; //update reg1
				}
			} else if (reg4.bit3 == 1) { //operasi *
				kali:
				// reg1 = B
				// reg2 = A
				// reg3 = M
				// reg4.bit6 = Q(-1)
				reg3.bit1 = reg2.bit1; reg2.bit1 = 0;
				reg3.bit2 = reg2.bit2; reg2.bit2 = 0;
				reg3.bit3 = reg2.bit3; reg2.bit3 = 0;
				reg3.bit4 = reg2.bit4; reg2.bit4 = 0;
				reg3.bit5 = reg2.bit5; reg2.bit5 = 0;
				reg3.bit6 = reg2.bit6; reg2.bit6 = 0;
				reg3.bit7 = reg2.bit7; reg2.bit7 = 0;
				reg3.bit8 = reg2.bit8; reg2.bit8 = 0;
				reg4.bit6 = 0; //pembantu
				reg4.bit7 = 1; // nandain masuk ke perkalian
				loop_mult();loop_mult();
				loop_mult();loop_mult();
				loop_mult();loop_mult();
				loop_mult();loop_mult();

			} else if (reg4.bit4 == 1) { //operasi *
				bagi:
				// reg1 = Q / divident
				// reg2 = A
				// reg3 = M / divisor
				// reg4.bit6 = Q(-1)
				reg3.bit1 = reg2.bit1; reg2.bit1 = 0;
				reg3.bit2 = reg2.bit2; reg2.bit2 = 0;
				reg3.bit3 = reg2.bit3; reg2.bit3 = 0;
				reg3.bit4 = reg2.bit4; reg2.bit4 = 0;
				reg3.bit5 = reg2.bit5; reg2.bit5 = 0;
				reg3.bit6 = reg2.bit6; reg2.bit6 = 0;
				reg3.bit7 = reg2.bit7; reg2.bit7 = 0;
				reg3.bit8 = reg2.bit8; reg2.bit8 = 0;
				reg4.bit6 = 0; //pembantu
				reg4.bit7 = 1; // nandain masuk ke perkalian
				loop_div();loop_div();
				loop_div();loop_div();
				loop_div();loop_div();
				loop_div();loop_div();
				if (reg2.bit8) reg2_plus_reg3();
			}
			// + bit1, - bit2, * bit3, / bit4
			if (c == '+') {
				reg4.bit1 = 1;
				reg4.bit2 = 0;
				reg4.bit3 = 0;
				reg4.bit4 = 0;
			} else if (c == '-') {
				reg4.bit1 = 0;
				reg4.bit2 = 1;
				reg4.bit3 = 0;
				reg4.bit4 = 0;
			} else if (c == '*') {
				reg4.bit1 = 0;
				reg4.bit2 = 0;
				reg4.bit3 = 1;
				reg4.bit4 = 0;
			} else if (c == '/') {
				reg4.bit1 = 0;
				reg4.bit2 = 0;
				reg4.bit3 = 0;
				reg4.bit4 = 1;
			}
			// update reg2
			reg2.bit1 = 0;
			reg2.bit2 = 0;
			reg2.bit3 = 0;
			reg2.bit4 = 0;
			reg2.bit5 = 0;
			reg2.bit6 = 0;
			reg2.bit7 = 0;
			reg2.bit8 = 0;
			if (c == EOF) {
				goto end;
			}
		}
	}
	goto itung_operator;
	// print coba
	// convert ke dec

	end:
		res = 0;
		res += reg1.bit1;
		res += reg1.bit2 * 2;
		res += reg1.bit3 * 4;
		res += reg1.bit4 * 8;
		res += reg1.bit5 * 16;
		res += reg1.bit6 * 32;
		res += reg1.bit7 * 64;
		res += reg1.bit8 * 128;
		printf("\nhasil = %d\n", res);
	
    return 0;
}
