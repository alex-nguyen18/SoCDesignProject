#include<stdio.h>
#include<stdlib.h>
#include "fixed_point.h"

fixed float_to_fixed(float value, int decimals){
	fixed fixed_out;
	fixed_out.value = (int64_t)(value*((float)(1<<decimals)));
}

fixed convert_and_multiply(float a, float b, int integers, int decimals){
	fixed fixed_a, fixed_b, fixed_out;
	
	fixed_a = float_to_fixed(a, decimals);
	fixed_b = float_to_fixed(b, decimals);

	fixed_out.value = fixed_a.value * fixed_b.value;

	return fixed_out;
}


fixed add_fixed(fixed mul_result, fixed c){
	fixed fixed_out;

	fixed_out.value = mul_result.value + c.value;

	return fixed_out;
}

float fixed_to_float(fixed a, int decimals){
	float float_out, temp;
	int mask;
	temp = 0;

	float_out = (a.value >> decimals);
	mask = (1<<decimals)-1;
	temp = (float)(a.value&mask) / (float)(1<<(decimals));

	float_out += temp;

	return float_out;

}
