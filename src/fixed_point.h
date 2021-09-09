#ifndef FIXED_POINT_H
#define FIXED_POINT_H

typedef struct fixed_point{
    int64_t value;
	 //int integer_bits;
	 //int decimal_bits;
}fixed ;

fixed float_to_fixed(float value, int decimals);

fixed convert_and_multiply(float a, float b, int integers, int decimals);

fixed add_fixed(fixed mul_result, fixed c);

float fixed_to_float(fixed a, int decimals);
