//azerty 						q 	b 	c 	d 	e 	f 	g 	h 	i 	j 	k 	l 	, 	n 	o 	p 	a 	r 	s 	t 	u 	v 	z 	x 	y 	w 	& 	é 	" 	' 	( 	- 	è 	_ 	ç 	à 			) 	= 	^ 	$ 	* 	No fr 	m 	ù 		² 			; 	: 	! 			<
//qwerty 						a 	b 	c 	d 	e 	f 	g 	h 	i 	j 	k 	l 	m 	n 	o 	p 	q 	r 	s 	t 	u 	v 	w 	x 	y 	z 	1 	2 	3 	4 	5 	6 	7 	8 	9 	0 			- 	= 	[ 	] 	\ 	No US 	; 	' 		` 			, 	. 	/ 		No US 					
//keycode 					4, 5, 6, 7, 8, 9, 10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39, 	45,46,47,48,49, 	50, 	51,52, 53, 	54,55,56, 	100}; 
uint8_t buf[8] = { 0 }; //Keyboard report buffer
//Keypad
const int btnPin = A0;
int btnState=false,oldState=true;
int btnCount=4; //Key code A-4 Z-29
void setup() {
 	Serial.begin(9600);
 	pinMode(btnPin,INPUT_PULLUP);
}
void loop() {
 	sendKey();
}
void sendKey() { /* function readAbtn */
 	//// Read button states from keypad
 	getBtn();
 	if (btnState!=oldState and btnState==true) {
 			buf[2] = btnCount++; // keycode
 			Serial.write(buf, 8); // Send keypress 
 			releaseKey();
 	}
 	if(btnCount>29) btnCount=4;
 	oldState=btnState;
}
void getBtn() { /* function getABtn */
 	//// Read button states from keypad
 	if (analogRead(btnPin) > 200) {
 			btnState=false;
 	} else {
     /**btnState = true; // ce bloclk est a tester, il censé envoier la lettre a 
    buf[2] = 4; // keycode for "a"
    Serial.write(buf, 8); // Send keypress
    releaseKey();**/
 			btnState=true;
 	}
 	delay(100); //anti-bounce delay
}
void releaseKey() {
 	buf[0] = 0;
 	buf[2] = 0;
 	Serial.write(buf, 8); // Send Release key
}