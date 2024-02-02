// factorial 

/* #include<stdio.h>

int fact(int n);

int main()
{
    int n;
    printf("enter the number:\n");
    scanf("%d",&n);
    printf("The Factorial of the number %d is %d",n,fact(n));
    return 0;
}

int fact(int n)
{
    if(n==1 || n==0)
    {  
        return 1;   
    }
    else
    {  
        return n*fact(n-1); 
    }
}
*/


// fibonacci series

/* #include<stdio.h>

int fib(int n);

int main()
{
    int n;
    printf("Enter the number at the which you want to know the fibonacci series: ");
    scanf("%d",&n);
    printf("The value of fibonacci series at position %d is %d\n",n,fib(n));
    printf("Fibonacci series for a number %d is: ",n);
    for(int i = 1; i <= n; i++)
    {
        printf("%d\t",fib(i));
    }
    return 0;
}

int fib(int n)
{
    if(n==1)
    {
        return 0;
    }
    else if(n==2)
    {
        return 1;
    }
    else
    {
        return fib(n-1)+fib(n-2);
    }
} */


// Tower of hanoi 


/* #include<stdio.h>
void toh(int n,char A,char B,char C);

int main()
{
    int n=3;
    toh(n,'a','b','c');
}

void toh(int n,char A,char B,char C)
{
    if(n==1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", A, C);
        return;
    }
    toh(n-1,A,B,C);
    printf("\n Move disk %d from rod %c to rod %c", n, A, C);
    toh(n-1,B,A,C);
} */

// Tower of hanoi

/* #include <stdio.h>

void TOH(int n, char A, char C, char B);

int main()
{
	int n ;
	printf("Enter number of disks: ");
	scanf("%d", &n);
	TOH(n,'A','C','B'); 
	return 0;
}

void TOH(int n, char A, char C, char B)
{
	if (n == 1)
	{
		printf("Move disk 1 from rod %c to rod %c\n",A,C);
		return;
	}
	TOH(n-1,A,B,C);
	printf("Move disk %d from rod %c to rod %c\n",n,A,C);
	TOH(n-1,B,C,A);
} */



// Dec_2_bin
/*
#include<stdio.h>

int dectobin(int n);

int main()
{
    int n;
    printf("Enter the number that you want to convert into binary:\n");
    scanf("%d",&n);
    printf("The Binary value is %d:\n",dectobin(n));
    return 0;
}

int dectobin(int n)
{
    if(n==0)
    { 
        return 0;  
    }
    else
    {
        return n % 2 + 10* dectobin(n / 2);
    }
}
*/


// palindrome 

/*
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char sequence[], int start, int end) 
{
    if (start >= end)
        return true;
    
    if (sequence[start] != sequence[end])
        return false;

    return isPalindrome(sequence, start + 1, end - 1);
}

int main() {
    char sequence[100];
    printf("Enter a sequence: ");
    scanf("%s", sequence);

    int length = strlen(sequence);
    bool palindrome = isPalindrome(sequence, 0, length - 1);

    if(palindrome)
        printf("The sequence is a palindrome.\n");
    else
        printf("The sequence is not a palindrome.\n");

    return 0;
}
*/

/* #include <stdio.h>
#include <string.h>

int palindrome(char a[], int s, int e)
{
    if (s >= e)
        return 1;
    
    if (a[s] != a[e])
        return 0;
    return palindrome(a, s + 1, e - 1);
}


int main() 
{
    char a[100];
    printf("Enter a sequence: ");
    scanf("%s", a);

    int l = strlen(a);
    int b = palindrome(a, 0, l - 1);

    if(b)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
 */


// sum of consecutive numbers
/*
#include<stdio.h>

int con(int n);

int main()
{
    int n;
    printf("Enter the number:\n");
    scanf("%d",&n);
    printf("number is %d",con(n));
    return 0;

}

int con(int n)
{
if (n>0){
return n + con(n - 1);}
else if (n==0){
return 0; }
else {
return -1; }
}
*/

// Print the reverse of a string using the recursion function
/* 
#include <stdio.h>  
#include <string.h>  
  
// use recursion function   
void revstr(char *str1)  
{  
    // declare static variable  
    static int i, len, temp;  
    len = strlen(str1); // use strlen() to get the length of str string  
            
    if (i < len/2){  
        // temp variable use to temporary hold the string  
        temp = str1[i];  
        printf("%d\n",temp);
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
        i++;  
        revstr(str1); // recusively calls the revstr() function  
    }  
}  
      
int main()  
{  
    char str1[50]; // size of char string  
    printf (" Enter the string: ");  
    gets(str1); // use gets() function to take string  
          
    printf (" \n Before reversing the string: %s \n", str1);  
          
    // call revstr() function   
    revstr(str1);  
    printf (" After reversing the string: %s", str1);  
    return 0;
}   */

/*
To find the ratio of a number into three parts

#include <stdio.h>


int main() 
{
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    int remainder = number % 5;
    
    if (remainder == 1 || remainder == 2) 
    {
        number -= remainder;
    } 
    else if (remainder == 3 || remainder == 4) 
    {
        number += (5 - remainder);
    }
    
    int countA = number / 5;
    int countB = countA * 2;
    int countC = countA * 2;
    
    printf("Number after conversion: %d\n", number);
    printf("Ratio: %d:%d:%d\n", countA, countB, countC);

    
    return 0;
}

*/
