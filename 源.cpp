#include <stdio.h>

float ohm_law(float U, float R) {
	return U / R;
}
float series(float R1, float R2) {
	return R1 + R2;
}
float parallel(float R1, float R2) {
	return R1 * R2 / (R1 + R2);
}
float total(float I1, float I2, float I3) {
	return (I1 + I2 + I3) * 1000;
}
void p(float I) {
	printf("The overall current in this circuit is %.1fmA.\n", I);
}
int main() {
	int R1 = 123, R2 = 234, R3 = 345, R4 = 456, R5 = 567, R6 = 678, R7 = 789;
	float Ra = series(R1, R2);//left line R
	float Rb = parallel(R3, R4);//middle line R
	float Rc = parallel(R6, R7);
	float Rd = series(R5, Rc);//right line R
	float I1 = ohm_law(12, Ra);//left line I
	float I2 = ohm_law(12, Rb);//middle line I
	float I3 = ohm_law(12, Rd);//right line I
	float I = total(I1, I2, I3);
	p(I);
	getchar();
}