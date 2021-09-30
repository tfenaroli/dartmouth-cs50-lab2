#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// Calculates wind chill based on temp and wind velocity
double calculateWindChill(double temp, double windVelocity) {
  double result = 35.74 + 0.6215*temp - 35.75*pow(windVelocity,0.16) + 0.4275*temp*pow(windVelocity,0.16);
  return result;
}

// main function
int main( int argc, char *argv[] ) {

  // ensures proper number of arguments
  if (0<argc && argc <4) {

    // if arg count is 1
    if (argc==1) {

      printf("  Temp   Wind  Chill\n");
      printf("  ----   ----   ----\n");

      double temps[6] = {-10.0, 0.0, 10.0, 20.0, 30.0, 40.0};
      double winds[3] = {5.0, 10.0, 15.0};
      for (int i=0; i<6; i++) {
        for (int j=0; j<3; j++) {
          double chill = calculateWindChill(temps[i], winds[j]);
          printf("%6.1f %6.1f %6.1f\n", temps[i], winds[j], chill);
        }
      }
    }

    // if arg count is 2
    else if (argc==2) {

      double temp = strtod(argv[1], NULL);
      
      // ensures valid temp
      if (temp <= -99.0 || temp >= 50.0) {
        printf("Temperature must be between -99 and 50 degrees!\n");
        return 1;
      }

      printf("  Temp   Wind  Chill\n");
      printf("  ----   ----   ----\n");

      double winds[3] = {5.0, 10.0, 15.0};
      for (int i=0; i<3; i++) {
          double chill = calculateWindChill(temp, winds[i]);
          printf("%6.1f %6.1f %6.1f\n", temp, winds[i], chill);
        }
    }

    // if arg count is not 1 or 2
    else {

      double temp = strtod(argv[1], NULL);
      double wind = strtod(argv[2], NULL);

      // ensures valid temp and wind velocity
      if ((temp <= -99.0 || temp >= 50.0) || (wind < 0.5)) {
        printf("Temperature must be between -99 and 50 degrees and wind velocity must be greater than 0.5 mph!\n");
        return 1;
      }

      printf("  Temp   Wind  Chill\n");
      printf("  ----   ----   ----\n");

      double chill = calculateWindChill(temp, wind);
      printf("%6.1f %6.1f %6.1f\n", temp, wind, chill);
    }
  }

  else {
    printf("Improper number of arguments!");
  }
  
  return 0;
}
