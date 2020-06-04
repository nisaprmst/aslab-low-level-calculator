if (reg3.bit1) { // karena reg3.bit1 udh ga kepake bisa dipake buat nyimpen angka kalo 1 + 1
					reg3.bit1 = reg2.bit1; // nyimpen / ga
					reg2.bit1 = ~reg2.bit1; //update reg2
				}
				if (reg3.bit2 != reg3.bit1)  {
					reg3.bit2 = reg2.bit2; // nyimpen / ga
					reg2.bit2 = ~reg2.bit2; //update reg2
				}
				if (reg3.bit3 != reg3.bit2)  {
					reg3.bit3 = reg2.bit3; // nyimpen / ga
					reg2.bit3 = ~reg2.bit3; //update reg2
				}
				if (reg3.bit4 != reg3.bit3)  {
					reg3.bit4 = reg2.bit4; // nyimpen / ga
					reg2.bit4 = ~reg2.bit4; //update reg2
				}
				if (reg3.bit5 != reg3.bit4)  {
					reg3.bit5 = reg2.bit5; // nyimpen / ga
					reg2.bit5 = ~reg2.bit5; //update reg2
				}
				if (reg3.bit6 != reg3.bit5)  {
					reg3.bit6 = reg2.bit6; // nyimpen / ga
					reg2.bit6 = ~reg2.bit6; //update reg2
				}
				if (reg3.bit7 != reg3.bit6)  {
					reg3.bit7 = reg2.bit7; // nyimpen / ga
					reg2.bit7 = ~reg2.bit7; //update reg2
				} 
				if (reg3.bit8 != reg3.bit7)  {
					reg3.bit8 = reg2.bit8; // nyimpen / ga
					reg2.bit8 = ~reg2.bit8; //update reg2
				}