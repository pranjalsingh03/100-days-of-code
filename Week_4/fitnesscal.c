#include <stdio.h>
void vo2max_calculations(char, int, int, float, float);
void details(char[50], int, char, float, float);
int main()
{
    char name[50], gender;
    int age, maximum_heart_rate, i = 16, j = 3, l = 236, m = 233, n = 175, o = 253; /// i,j,l,m,n & o for ASCI characters
    float bmi, weight, height, minimum_heart_rate, vo2max;

    printf("  =================================================================== %c Fitness Calculator %c ===============================================================\n", j, j);
    printf("  \n============================================================================================================================================================");
    printf("\t\t\t\t\t\t\t\t  * Details/Credentials for Registration *\n");

    printf("\n%c Enter your name                                            : ", i);
    gets(name);
    printf("\n%c Enter your age (In years)                                  : ", i);
    scanf("%d", &age);
    printf("\n%c Enter your gender (Enter 'M' for male and 'F' for female)  : ", i);
    gender = getche();
    printf("\n\n%c Enter your weight (In Kg only)                             : ", i);
    scanf("%f", &weight);
    printf("\n%c Enter your height (In m only)                              : ", i);
    scanf("%f", &height);
    maximum_heart_rate = (220 - age);

    printf("\n%c To measure your minimum heart rate/pulse at your wrist, place 2 fingers between the bone and the tendon over your radial artery which is located on the thumb side of your wrist. When you feel your pulse, count the number of beats in 15 seconds. Multiply this number by 4 to calculate your beats per minute.", l);
    printf("\n\n%c NOTE: The average minimum heart rate of a human being is in range of b/w: 60-100 beats per minute.", m);
    printf("\n\n%c Enter your minimum heart rate: ", i);
    scanf("%f", &minimum_heart_rate);
    printf("============================================================================================================================================================\n");

    bmi = ((weight) / (height * height)); // BMI formula

    vo2max = (15 * ((maximum_heart_rate / minimum_heart_rate))); // VO2max formula
    if (age <= 1)
    {
        printf("\nBMI value cannot be concluded for an individual having age of 1 year or less");
    }

    if (age >= 2 && age < 20)
    {

        if (bmi < 5)
        {
            details(name, age, gender, weight, height);
            printf("\n%c BMI           : %.2f kg/m%c", n, bmi, o);
            printf("\n%c Weight Status : Underweight", n);
            vo2max_calculations(gender, age, maximum_heart_rate, minimum_heart_rate, vo2max); // Function call for displaying VO2max related information
        }
        if (bmi >= 5 && bmi <= 85)
        {
            details(name, age, gender, weight, height);
            printf("\n%c BMI           : %.2f kg/m%c", n, bmi, o);
            printf("\n%c Weight Status : Healthy Weight", n);
            vo2max_calculations(gender, age, maximum_heart_rate, minimum_heart_rate, vo2max); // Function call for displaying VO2max related information
        }
        if (bmi >= 85 && bmi <= 95)
        {
            details(name, age, gender, weight, height);
            printf("\n%c BMI           : %.2f kg/m%c", n, bmi, o);
            printf("\n%c Weight Status : At risk of overweight", n);
            vo2max_calculations(gender, age, maximum_heart_rate, minimum_heart_rate, vo2max); // Function call for displaying VO2max related information
        }
        if (bmi > 95)
        {
            details(name, age, gender, weight, height);
            printf("\n%c BMI           : %.2f kg/m%c", n, bmi, o);
            printf("\n%c Weight Status : Overweight", n);
            vo2max_calculations(gender, age, maximum_heart_rate, minimum_heart_rate, vo2max); // Function call for displaying VO2max related information
        }
    }

    ///--------------------------------------------====================================================================--------------------------------------------///
    ///--------------------------------------------End of Conditions for different BMI values for age group of 1 & 2-20--------------------------------------------///
    ///--------------------------------------------====================================================================--------------------------------------------///

    ///--------------------------------------------=================================================================--------------------------------------------///
    ///--------------------------------------------Conditions for different BMI values for age group of 20 & greater--------------------------------------------///
    ///--------------------------------------------=================================================================--------------------------------------------///
    if (age >= 20)
    {

        if (bmi < 18.5)
        {
            details(name, age, gender, weight, height);
            printf("\n%c BMI           : %.2f kg/m%c", n, bmi, o);
            printf("\n%c Weight Status : Underweight", n);
            vo2max_calculations(gender, age, maximum_heart_rate, minimum_heart_rate, vo2max); // Function call for displaying VO2max related information
        }
        if (bmi >= 18.5 && bmi <= 24.9)
        {
            details(name, age, gender, weight, height);
            printf("\n%c BMI           : %.2f kg/m%c", n, bmi, o);
            printf("\n%c Weight Status : Healthy weight", n);
            vo2max_calculations(gender, age, maximum_heart_rate, minimum_heart_rate, vo2max); // Function call for displaying VO2max related information
        }
        if (bmi >= 25 && bmi <= 29.9)
        {
            details(name, age, gender, weight, height);
            printf("\n%c BMI           : %.2f kg/m%c", n, bmi, o);
            printf("\n%c Weight Status : Overweight", n);
            vo2max_calculations(gender, age, maximum_heart_rate, minimum_heart_rate, vo2max); // Function call for displaying VO2max related information
        }
        if (bmi >= 30)
        {
            details(name, age, gender, weight, height);
            printf("\n%c BMI           : %.2f kg/m%c", n, bmi, o);
            printf("\n%c Weight Status : Obesity", n);
            vo2max_calculations(gender, age, maximum_heart_rate, minimum_heart_rate, vo2max); // Function call for displaying VO2max related information
        }
    }
}

///--------------------------------------------========================================================================--------------------------------------------///
///--------------------------------------------End of Conditions for different BMI values for age group of 20 & greater--------------------------------------------///
///--------------------------------------------========================================================================--------------------------------------------///

///--------------------------------------------==================================--------------------------------------------///
///--------------------------------------------<<<End of Body of main function>>>--------------------------------------------///
///--------------------------------------------==================================--------------------------------------------///

///--------------------------------------------========================================================================--------------------------------------------///
///--------------------------------------------Function for calculation of VO2max and displaying VO2max related details--------------------------------------------///
///--------------------------------------------========================================================================--------------------------------------------///

void vo2max_calculations(char sex, int age, int max_heart_rate, float min_heart_rate, float vo2max)
{

    ///--------------------------------------------==================================================--------------------------------------------///
    ///--------------------------------------------Conditions for different VO2max levels for females--------------------------------------------///
    ///--------------------------------------------==================================================--------------------------------------------///
