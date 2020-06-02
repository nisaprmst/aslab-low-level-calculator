// reg1 += reg2
				if (reg2.bit1 == 1) {
					// karena reg2.bit1 udh ga kepake bisa dipake buat nyimpen angka kalo 1 + 1
					if (reg1.bit1 == 0) {
						reg1.bit1 == 1; // update reg1
						reg2.bit1 = 0; // ga nyimpen
					} else {
						reg1.bit1 == 0; // nyimpen di reg2.bit1 = 1
					}
				}
				if (reg2.bit2 == 1) {
					// karena reg2.bit1 udh ga kepake bisa dipake buat nyimpen angka kalo 1 + 1
					if (reg1.bit2 == 0) {
						// cek nyimpen apa ga, kalo nyimpen biarin 
						// krn reg2.bit2 udh bener isinya 1 (nyimpen) terus reg1.bit2 udh bener isinya 0
						// kalo ga nyimpen brrti update
						if (reg2.bit1 == 0) {
							reg1.bit2 == 1; // update reg1
							reg2.bit2 = 0; // ga nyimpen
						}
					} else { // reg1.bit2 == 1
						// cek nyimpen apa ga, kalo ga brrti kyk biasa
						if (reg2.bit1 == 0) {
							reg1.bit2 == 0; // nyimpen di reg2
						}
						// kalo nyimpen brrti gaada yg diupdate krn reg2 udh bener nyimpen
						// terus reg1 udh bener yaitu nilainya 1
					}
				}
				if (reg2.bit3 == 1) {
					if (reg1.bit3 == 0) {
						if (reg2.bit2 == 0) {
							reg1.bit3 == 1; // update reg1
							reg2.bit3 = 0; // ga nyimpen
						}
					} else {
						if (reg2.bit2 == 0) {
							reg1.bit3 == 0; // nyimpen di reg2
						}
					}
				}
				if (reg2.bit4 == 1) {
					if (reg1.bit4 == 0) {
						if (reg2.bit3 == 0) {
							reg1.bit4 == 1; // update reg1
							reg2.bit4 = 0; // ga nyimpen
						}
					} else { 
						if (reg2.bit3 == 0) {
							reg1.bit4 == 0; // nyimpen di reg2
						}
					}
				}
				if (reg2.bit5 == 1) {
					if (reg1.bit5 == 0) {
						if (reg2.bit4 == 0) {
							reg1.bit5 == 1; // update reg1
							reg2.bit5 = 0; // ga nyimpen
						}
					} else {
						if (reg2.bit4 == 0) {
							reg1.bit5 == 0; // nyimpen di reg2
						}
					}
				}
				if (reg2.bit6 == 1) {
					if (reg1.bit6 == 0) {
						if (reg2.bit5 == 0) {
							reg1.bit6 == 1; // update reg1
							reg2.bit6 = 0; // ga nyimpen
						}
					} else {
						if (reg2.bit5 == 0) {
							reg1.bit6 == 0; // nyimpen di reg2
						}
					}
				}
				if (reg2.bit7 == 1) {
					if (reg1.bit7 == 0) {
						if (reg2.bit6 == 0) {
							reg1.bit7 == 1; // update reg1
							reg2.bit7 = 0; // ga nyimpen
						}
					} else {
						if (reg2.bit6 == 0) {
							reg1.bit7 == 0; // nyimpen di reg2
						}
					}
				}
				if (reg2.bit8 == 1) {
					if (reg1.bit8 == 0) {
						if (reg2.bit7 == 0) {
							reg1.bit8 == 1; // update reg1
							reg2.bit8 = 0; // ga nyimpen
						}
					} else {
						if (reg2.bit7 == 0) {
							reg1.bit8 == 0; // nyimpen di reg2
						}
					}
				}