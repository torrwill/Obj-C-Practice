// Insert standard libraries
#include <stdio.h>

// Define constants
#define CONVERSION_FAHRENHEIT 32.0
#define CONVERSION_KELVIN 273.15

//Initialize variables
float temp, Fahrenheit, Celsius, Kelvin;
char typeOfTemp;

/*
 * Converts the user inputted Fahrenheit value into Celsius
 * Parameters: User inputted Fahrenheit
 * Preconditions: Inputted value is in Fahrenheit
 * Return: The converted temperature in Celsius
 */
float fahrenheitToCelsius(float temp) {
    Celsius = (temp - CONVERSION_FAHRENHEIT) / 1.8;
    return Celsius;
}

/*
 * Converts the user inputted Fahrenheit value into Kelvin
 * Parameters: Fahrenheit value converted to Celsius
 * Preconditions: Inputted value is Fahrenheit
 * Return: The converted temperature in Kelvin
 */
float fahrenheitToKelvin(float temp) {
    float Celsius = fahrenheitToCelsius(temp);
    Kelvin = Celsius + CONVERSION_KELVIN;
    return Kelvin;
}

/*
 * Converts user inputted Celsius into Fahrenheit
 * Parameters: User inputted Celsius
 * Preconditions: Inputted value is Celsius
 * Return: The converted temperature in Fahrenheit
 */
float celsiusToFahrenheit(float temp) {
    Fahrenheit = (temp * 1.8) + CONVERSION_FAHRENHEIT;
    return Fahrenheit;
}

/*
 * Converts user inputted Celsius into Kelvin
 * Parameters: User inputted Celsius
 * Preconditions: Inputted value is Celsius
 * Return: The converted temperature in Kelvin
 */
float celsiusToKelvin(float temp) {
    Kelvin = temp + CONVERSION_KELVIN;
    return Kelvin;
}

/*
 * Converts user inputted Kelvin to Fahrenheit
 * Parameters: User inputted Kelvin
 * Preconditions: Inputted value is Kelvin
 * Return: The converted temperature in Fahrenheit
 */
float kelvinToFahrenheit(float temp) {
    Fahrenheit = (temp - CONVERSION_KELVIN) * 1.8 + 32;
    return Fahrenheit;
}

/*
 * Converts the user inputted Kelvin to Celsius
 * Parameters: User inputted Kelvin
 * Preconditions: Inputted value is Kelvin
 * Return: The converted temperature in Celsius
 */
float kelvinToCelsius(float temp) {
    Celsius = (temp - CONVERSION_KELVIN);
    return Celsius;
}
// Clears user input if an EOF value or a newline character is recieved
void clearKeyboardBuffer() {
  char ch;
  while ((ch = getchar() != '\n') && (ch != EOF));
}

// Start main
int main(void) {

  // Loop infinitely until the user input is correct
  // and the temperature conversions can be made
  while (1) {

    // Read the amount of degrees and type of temperature from user
    // While validating that the user inputted the correct value
    printf("Enter input temperature: ");
    if (scanf("%f %c", &temp, &typeOfTemp) != 2) {
        fprintf(stderr, "Invalid Temperature Scale.\n\n");
        clearKeyboardBuffer();

    // Convert and print based on Fahrenheit
    } else if(typeOfTemp == 'f' || typeOfTemp == 'F') {

        Celsius = fahrenheitToCelsius(temp);
        Kelvin = fahrenheitToKelvin(temp);

        // Is result invalid?
        if(temp < 0) {
          return 1;
        }

        printf("%0.2f Fahrenheit converts to: \n"
            "\t%0.2f C \n"
            "\t%0.2f K", temp, Celsius, Kelvin);
        
        return 0;

    // Convert and print based on Celsius
    } else if (typeOfTemp == 'c' || typeOfTemp == 'C') {

        Fahrenheit = celsiusToFahrenheit(temp);
        Kelvin = celsiusToKelvin(temp);

        // Is result invalid?
        if(temp < 0) {
          return 1;
        }

        printf("%0.2f Celsius converts to: \n"
            "\t%0.2f F \n"
            "\t%0.2f K", temp, Fahrenheit, Kelvin);
        
        return 0;

    // Convert and print based on Kelvin
    } else if(typeOfTemp == 'k' || typeOfTemp == 'K') {

        Fahrenheit = kelvinToFahrenheit(temp);
        Celsius = kelvinToCelsius(temp);

        // Is result invalid?
        if(temp < 0) {
          return 1;
        }

        printf("%0.2f Kelvin converts to: \n"
            "\t%0.2f C \n"
            "\t%0.2f F", temp, Celsius, Fahrenheit);
        
        return 0;

    } // End Conditionals

  } // End while

} // End main