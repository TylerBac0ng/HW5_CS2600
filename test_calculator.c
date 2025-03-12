#include "unity.h"
#include "calculator.h"
#include "limits.h"

// Optional but needs to be defined(runs BEFORE each test)
void setUp(void) {
// Initialize any resources needed for your tests here
// For example, you might reset a global value, dynamically allocate memory, etc.
// In this example, we do not need anything here.
}

// Optional but needs to be defined(runs AFTER each test)
void tearDown(void) {
// Clean up resources after each test
// For example, free dynamically allocated memory, reset global values, etc.
// In this example, we do not need anything here.
}

void test_add_positive_numbers(void) {
	TEST_ASSERT_EQUAL(5, add(2, 3)); // We expect 2 + 3 to be 5
}

void test_add_positive_and_negative_numbers(void) {
	TEST_ASSERT_EQUAL(1, add(5, -4));  // Expect 5 + (-4) = 1
 }
 
void test_add_negative_numbers(void) {
	TEST_ASSERT_EQUAL(-7, add(-3, -4)); // Expect -3 + -4 = -7
}
 
void test_add_zero(void) {
	TEST_ASSERT_EQUAL(10, add(10, 0));  // Expect 10 + 0 = 10
	TEST_ASSERT_EQUAL(0, add(0, 0));    // Expect 0 + 0 = 0
}

void test_subtract_positive_numbers(void) {
	TEST_ASSERT_EQUAL(1, subtract(3, 2)); // We expect 3 - 2 to be 1
}

void test_subtract_positive_and_negative_numbers(void) {
	TEST_ASSERT_EQUAL(9, subtract(5, -4));  // Expect 5 - (-4) = 9
 }
 
void test_subtract_negative_numbers(void) {
	TEST_ASSERT_EQUAL(1, subtract(-3, -4)); // Expect -3 - -4 = 1
}
 
void test_subtract_zero(void) {
	TEST_ASSERT_EQUAL(10, subtract(10, 0));  // Expect 10 - 0 = 10
	TEST_ASSERT_EQUAL(0, subtract(0, 0));    // Expect 0 - 0 = 0
}

void test_multiply_positive_numbers(void) {
	TEST_ASSERT_EQUAL(6, multiply(3, 2)); // We expect 3 * 2 to be 6
}

void test_multiply_positive_and_negative_numbers(void) {
	TEST_ASSERT_EQUAL(-20, multiply(5, -4));  // Expect 5 * (-4) = -20
 }
 
void test_multiply_negative_numbers(void) {
	TEST_ASSERT_EQUAL(12, multiply(-3, -4)); // Expect -3 * -4 = 12
}
 
void test_multiply_zero(void) {
	TEST_ASSERT_EQUAL(0, multiply(10, 0));  // Expect 10 * 0 = 0
	TEST_ASSERT_EQUAL(0, multiply(0, 0));    // Expect 0 * 0 = 0
}
 
void test_divide_positive_numbers(void) {
	TEST_ASSERT_EQUAL(2, divide(6, 3));    // 6 / 3 = 2
}

void test_divide_positive_and_negative_numbers(void) {
	TEST_ASSERT_EQUAL(-5, divide(10, -2));  // Expect 10 * (-2) = -5
}
 
void test_divide_negative_numbers(void) {
	TEST_ASSERT_EQUAL(5, divide(-10, -2)); // Expect -10 / -2 = 5
}

void test_divide_by_zero(void) {
	TEST_ASSERT_EQUAL(0, divide(5, 0));    // Define behavior for division by zero
}

// Test integer overflow
void test_add_overflow(void) {
	int result = add(INT_MAX, 1); // Should wrap around or cause undefined behavior
	TEST_ASSERT_TRUE(result < 0); // This checks if overflow occurred
}
 
// Test integer underflow
void test_add_underflow(void) {
	int result = add(INT_MIN, -1);
	TEST_ASSERT_TRUE(result > 0); // This checks if underflow occurred
}
 
// Test integer overflow in subtraction
void test_subtract_overflow(void) {
	int result = subtract(INT_MAX, -1); // MAX - (-1) = MAX + 1 should overflow
	TEST_ASSERT_TRUE(result < 0); // This checks if overflow occurred
}
 
// Test integer underflow in subtraction
void test_subtract_underflow(void) {
	int result = subtract(INT_MIN, 1); // MIN - 1 should underflow
	TEST_ASSERT_TRUE(result > 0); // This checks if underflow occurred
}
 
// Test integer overflow in multiplication
void test_multiply_overflow(void) {
	int result = multiply(INT_MAX, 2); // Should overflow
	TEST_ASSERT_TRUE(result < 0); // This checks if overflow occurred
}
 
// Test integer underflow in multiplication
void test_multiply_underflow(void) {
	int result = multiply(INT_MIN, 2); // Will overflow in most implementations
	// The result is typically 0 or a negative number, not positive
	TEST_ASSERT_TRUE(result <= 0); // Adjusted expectation
}
 
// Test integer overflow in division
void test_divide_overflow(void) {
	// Only INT_MIN / -1 can overflow on two's complement machines
	int result = divide(INT_MIN, -1);
	TEST_ASSERT_TRUE(result <= 0); // Either overflow or implementation-defined
}
 
// Test integer underflow in division
void test_divide_underflow(void) {
	// Division doesn't typically underflow, but we can test edge cases
	int result = divide(INT_MIN, 1);
	TEST_ASSERT_EQUAL(INT_MIN, result); // Should remain INT_MIN
}
 
int main(void) {
	UNITY_BEGIN();

	RUN_TEST(test_add_positive_numbers);
	RUN_TEST(test_add_positive_and_negative_numbers);
	RUN_TEST(test_add_negative_numbers);
	RUN_TEST(test_add_zero);
	RUN_TEST(test_add_overflow);
	RUN_TEST(test_add_underflow);

	RUN_TEST(test_subtract_positive_numbers);
	RUN_TEST(test_subtract_positive_and_negative_numbers);
	RUN_TEST(test_subtract_negative_numbers);
	RUN_TEST(test_subtract_zero);
	RUN_TEST(test_subtract_overflow);
	RUN_TEST(test_subtract_underflow);

	RUN_TEST(test_multiply_positive_numbers);
	RUN_TEST(test_multiply_positive_and_negative_numbers);
	RUN_TEST(test_multiply_negative_numbers);
	RUN_TEST(test_multiply_zero);
	RUN_TEST(test_multiply_overflow);
	RUN_TEST(test_multiply_underflow);

	RUN_TEST(test_divide_positive_numbers);
	RUN_TEST(test_divide_positive_and_negative_numbers);
	RUN_TEST(test_divide_negative_numbers);
	RUN_TEST(test_divide_by_zero);
	RUN_TEST(test_divide_overflow);
	RUN_TEST(test_divide_underflow);

	return UNITY_END();
}
 
