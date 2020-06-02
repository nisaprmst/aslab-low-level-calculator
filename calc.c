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

int main(int argc, char* argv[]){
	
	FILE *file = fopen(argv[1], "r");
	char c;

	if (file == NULL) {
		printf("File not found!\n");
		exit(1);
	}

	// most significant bit = bit8
	// reg1 = retval / left operand
	// reg2 buat nyimpen nilai yang dibaca sekali
	// reg3 buat bantu reg2 nyimpen nilai yg dibaca
	// reg4 = prev state
	while ((c = fgetc(file)) != EOF) {
		// kalo angka, simpan di reg2
		if (c >= 48 && c <= 57) {
			// simpan nilai lama reg2 dikali 2 ke reg3
			// reg3 = reg2 + reg2
			// ingat reg3 ga bersih jd harus ditangani semua kondisi
			reg3_=_reg2_x_2:
				reg2.bit1 = 0;
				if (reg2.bit1 == 1) reg3.bit2 = 1;
				else reg3.bit2 = 0;
				if (reg2.bit2 == 1) reg3.bit3 = 1;
				else reg3.bit3 = 0;
				if (reg2.bit3 == 1) reg3.bit4 = 1;
				else reg3.bit4 = 0;
				if (reg2.bit4 == 1) reg3.bit5 = 1;
				else reg3.bit5 = 0;
				if (reg2.bit5 == 1) reg3.bit6 = 1;
				else reg3.bit6 = 0;
				if (reg2.bit6 == 1) reg3.bit7 = 1;
				else reg3.bit7 = 0;
				if (reg2.bit7 == 1) reg3.bit8 = 1;
				else reg3.bit8 = 0;
			
			// kalo reg2 bukan digit pertama / tidak semuanya = 0
			if (!(reg2.bit1 == 0 && reg2.bit1 == 0
				&& reg2.bit1 == 0 && reg2.bit1 == 0
				&& reg2.bit1 == 0 && reg2.bit1 == 0
				&& reg2.bit1 == 0 && reg2.bit1 == 0 )) {
					goto update_reg2;
				}
			reg3_=_c:
				// update reg3 = c
				if (c == 49) { // 1
					reg3.bit1 = 1;
				} else if (c == 50) { // 2
					reg3.bit2 = 1;
				} else if (c == 51) { // 3
					reg3.bit1 = 1;
					reg3.bit2 = 1;
				} else if (c == 52) { // 4
					reg3.bit3 = 1;
				} else if (c == 53) { // 5
					reg3.bit3 = 1;
					reg3.bit1 = 1
				} else if (c == 54) { // 6
					reg3.bit2 = 1;
					reg3.bit3 = 1;
				} else if (c == 55) { // 7
					reg3.bit1 = 1;
					reg3.bit2 = 1;
					reg3.bit3 = 1;
				} else if (c == 56) { // 8
					reg3.bit4 = 1;
				} else if (c == 57) { // 9
					reg3.bit4 = 1;
					reg3.bit1 = 1;
				}
				goto reg2_=_reg2_+_reg3;
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
			reg2_=_reg2_+_reg3:
				// reg2 += reg3
				if (reg3.bit1 == 1) {
					// karena reg3.bit1 udh ga kepake bisa dipake buat nyimpen angka kalo 1 + 1
					if (reg2.bit1 == 0) {
						reg2.bit1 == 1; // update reg2
						reg3.bit1 = 0; // ga nyimpen
					} else {
						reg2.bit1 == 0; // nyimpen di reg3.bit1 = 1
					}
				}
				if (reg3.bit2 == 1) {
					// karena reg3.bit1 udh ga kepake bisa dipake buat nyimpen angka kalo 1 + 1
					if (reg2.bit2 == 0) {
						// cek nyimpen apa ga, kalo nyimpen biarin 
						// krn reg3.bit2 udh bener isinya 1 (nyimpen) terus reg2.bit2 udh bener isinya 0
						// kalo ga nyimpen brrti update
						if (reg3.bit1 == 0) {
							reg2.bit2 == 1; // update reg2
							reg3.bit2 = 0; // ga nyimpen
						}
					} else { // reg2.bit2 == 1
						// cek nyimpen apa ga, kalo ga brrti kyk biasa
						if (reg3.bit1 == 0) {
							reg2.bit2 == 0; // nyimpen di reg3
						}
						// kalo nyimpen brrti gaada yg diupdate krn reg3 udh bener nyimpen
						// terus reg2 udh bener yaitu nilainya 1
					}
				}
				if (reg3.bit3 == 1) {
					if (reg2.bit3 == 0) {
						if (reg3.bit2 == 0) {
							reg2.bit3 == 1; // update reg2
							reg3.bit3 = 0; // ga nyimpen
						}
					} else {
						if (reg3.bit2 == 0) {
							reg2.bit3 == 0; // nyimpen di reg3
						}
					}
				}
				if (reg3.bit4 == 1) {
					if (reg2.bit4 == 0) {
						if (reg3.bit3 == 0) {
							reg2.bit4 == 1; // update reg2
							reg3.bit4 = 0; // ga nyimpen
						}
					} else { 
						if (reg3.bit3 == 0) {
							reg2.bit4 == 0; // nyimpen di reg3
						}
					}
				}
				if (reg3.bit5 == 1) {
					if (reg2.bit5 == 0) {
						if (reg3.bit4 == 0) {
							reg2.bit5 == 1; // update reg2
							reg3.bit5 = 0; // ga nyimpen
						}
					} else {
						if (reg3.bit4 == 0) {
							reg2.bit5 == 0; // nyimpen di reg3
						}
					}
				}
				if (reg3.bit6 == 1) {
					if (reg2.bit6 == 0) {
						if (reg3.bit5 == 0) {
							reg2.bit6 == 1; // update reg2
							reg3.bit6 = 0; // ga nyimpen
						}
					} else {
						if (reg3.bit5 == 0) {
							reg2.bit6 == 0; // nyimpen di reg3
						}
					}
				}
				if (reg3.bit7 == 1) {
					if (reg2.bit7 == 0) {
						if (reg3.bit6 == 0) {
							reg2.bit7 == 1; // update reg2
							reg3.bit7 = 0; // ga nyimpen
						}
					} else {
						if (reg3.bit6 == 0) {
							reg2.bit7 == 0; // nyimpen di reg3
						}
					}
				}
				if (reg3.bit8 == 1) {
					if (reg2.bit8 == 0) {
						if (reg3.bit7 == 0) {
							reg2.bit8 == 1; // update reg2
							reg3.bit8 = 0; // ga nyimpen
						}
					} else {
						if (reg3.bit7 == 0) {
							reg2.bit8 == 0; // nyimpen di reg3
						}
					}
				}
			if (!(reg2.bit1 == 0 && reg2.bit1 == 0
				&& reg2.bit1 == 0 && reg2.bit1 == 0
				&& reg2.bit1 == 0 && reg2.bit1 == 0
				&& reg2.bit1 == 0 && reg2.bit1 == 0 )) {
					goto reg3_=_c;
				}
		}
			
	}
	
    return 0;
}
