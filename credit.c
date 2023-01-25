#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //get card number
    long n = get_long("Number: ");

    //count length
    int lenofn = 0;//length of credit number
    long phfc = n;//place holder for counter
    //dividing by 10 will knock off a number each time
    //for each numb knocked off we add to the counter i = length.
    while (phfc > 0)
    {
        phfc = phfc / 10;
        lenofn++;
    }
    //now check if that number is not 13 15 or 16

    if (lenofn != 13 && lenofn != 15 && lenofn != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    //1. check sum, we need to multiply every other digit by 2,
    //2. then add the digits you didnt *2 together
    //3. then add that to the digits that were multiplied by 2
    //4. take the final result and if the last digit is 0 its valid
    int sum1 = 0;
    int sum2 = 0;
    long x = n;//another placeholder for the card numb
    int total = 0;//total of step
    int lastdig;
    int seconddig;
    int d1;//digit 1 of the anwer to *2 of a digit in the card number
    int d2;//digit 2 of the answer to *2 of a digit in the card number


    do
    {
        //remove the last digit first and add together in sum1 so it will do those ones first
        lastdig =  x % 10;
        x = x / 10;
        sum1 = sum1 + lastdig;

        //remove the second to last digit and add those numbers together
        seconddig = x % 10;
        x = x / 10;

        //double the second to last digits and add digits to sum2
        seconddig = seconddig * 2;
        //this d1 and d2 accounts for if the double of the digit in
        //the second to last digit is more then figure long
        //ie if 6*2 = 12 we want to only add 1 and 2 not 12.
        d1 = seconddig % 10;
        d2 = seconddig / 10;
        sum2 = sum2 + d1 + d2;

    }
    while (x > 0);

    total = sum1 + sum2;

    //check to see if the total of sum1 and 2 is not equal to 0
    //ie if it doesnt satisfy 4. print invalid and stop the program
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //check for the first two numbers of the credit card numb
    long start = n;//set new placeholder variable
    do
    {
        //keep dividing the credit card number by 10
        start = start / 10;
    }
    //this makes it do that this do loop will only run until
    //the result becomes less then 100 (ie 2digits)
    //else it will run until it reaches the last digit
    while (start > 100);

    //see if those starting 2 starting numbers are 5 and 1 2 3 4 5
    if (start == 51 || start == 52 || start == 53 || start == 54 || start == 55)
    {
        printf("MASTERCARD\n");
    }

    //check if they are 34 or 37
    else if (start == 34 || start == 37)
    {
        printf("AMEX\n");
    }

    //check if first digit is 4
    else if ((start / 10 == 4))
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
        return 0;
    }

}