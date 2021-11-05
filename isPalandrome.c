#include <stdio.h> // Insert standard library

int largestPalindrome(int n) { 
    
    // Initialize the upper limit value
    int upperLimit = 0;
  
    // Loop calculates the upper limit,
    // Or the largest number within n digits
    for (int i = 1; i <= n; i++) {
        upperLimit *= 10;
        upperLimit += 9;
    } // End for loop
  
    // Initialize the lower limit by adding one and dividing that value by 10
    int lowerLimit = 1 + upperLimit / 10; 
  
    // Initialize the maximum product value
    int max_product = 0;

    // Outer and Inner for loop will take the variables, i and j,
    // then decrease the upper limit by one value as long as it doesn't
    // become lower than the lower limit

    // Start outer for loop 
    for (int i = upperLimit; i >= lowerLimit; i--) {
        // Start inner for loop 
        for (int j = i; j >= lowerLimit; j--) { 
            
            // Product will calculate the product of the two n-digit numbers 
            int product = i * j; 
           
            // End the for loop if the product is less than the maximum product
            if (product < max_product) 
                break; 
           
            // Variables used to test if product is a palindrome
            int number = product;
            int reverse = 0;

            // Reverse the product to determine if palindrome
            while (number != 0) { 
                reverse = reverse * 10 + number % 10; 
                number /= 10; 
            } // End while loop
  
            // If a new maximum product exists, update the product variable  
            if (product == reverse && product > max_product) { 
                max_product = product; 
            } // End if statement
    
        } // End inner for loop
    
    } // End outer for loop

    // Prints formatted text
    printf("%d\n", max_product);

    // If everything went well, return the value of 'max_product'
    return max_product; 

} // End largestPalindrome

int main () {

    // Determine the largest palindrome for two 3 digit numbers
    largestPalindrome(3);    
    
    // If everything went well, return 0
    return 0;

} // end main