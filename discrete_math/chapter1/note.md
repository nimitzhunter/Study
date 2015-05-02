### How to count something where order matters
1. How many steps. Say we have N steps. 
2. At each step, how many choices do we have?  Does the number of choices remain constant or how does it shift at each step? 
Example: a set contain positive numbers of up to 10 digits, how many numbers are in the set?
In this example, order matters, 1234 and 4321 are different numbers.
How many steps? 10 steps because each number contain up to 10 digits. 
How have choices do we have in each step? At each digit, we can select any number from 0 to 9, so we have 10 choices. 
Answer is 10**10 numbers.


## how to count something where the order doesn't matter
1. Count the number if order doesn't matter. get N
2. Count the number of shuffling a set, get M
3. Calculate N//M
Example: suppose we are selecting numbers for a lottery tickets. Each number on the lottery is in the range(1,90) and you can't repeat a number. So we need to select 5 numbers, thus the number of step is 5. At each step our number of choices is reduced by one because of the uniqueness rule. Thus, the numbers of lottery combination is 90*89*88*87*86.

However, since the order of selection of the numbers doesn't matter, 1 2 3 4 5 and 5 4 3 2 1 will win the lottery. With 5 numbers in the lottery, a number can be shuffled to any of the 5 position on the ticket, thus there are 5 steps. In the first slot, any five numbers can appear there, on the second lot, any 4 numbers can appear there, and so on. Start with 5 steps and 5 choices, at each step the choices reduce by 1; thus 5*4*3*2*1 ways to shuffle any 5 numbers.

The actual number of lottery tickets are (90*89*88*87*86)//(5*4*3*2*1)



###What is the number of subsets of a non-empty set? 
Let A be a set, and N = |A| be the number of elements of the set, the number of subsets of A is 2**(N). 
####How did we get 2**(n)?
Let a1,a2,...,aN be the elements of A. At each step, we need to decide whether or not to include the element ai for 1<=i<=N into the subset. At each step, we have exactly 2 choices to make, thus the numbers of subset is 2**N


##Converting base ten to binary
In binary form, the last binary digit of an odd number is 1; and 0 for an even number. 

For example: 233 is odd, so in its binary representation, the last binary digit is 1.

Take the binary number and chop off its last digit is equilvalent to dividing the base ten number in half. 233//2=116 which is even; now we know the next digit in the binary sequence is 0. We have '01' so far. 

Shifting to the right again, we get 116//2=58 => our sequence is '101'
    233  =>  1 
    116  =>  01 
    058  =>  001 
    029  =>  1001
    014  =>  01001
    007  =>  101001 
    003  =>  1101001
    001  =>  11101001 
233 => 0b11101001

Algorithm: 
If a base ten number is odd, add 1 to the binary sequence; zero otherwise. then half the binary number and repeat.


exercise:
1.3.1. Let A be a set with N elements
a) which numbers correspond to subsets with 1 element? Ans: let i be the number representation, if i = 2**j where j is any natural number, then *i* correspond to subsets with 1 element. Simpler answer, if i is a power of 2.
b) which numbers correspond to the whole set? Ans: 2**N
c) which numbers correspond to even numbers? Ans: even numbers mean the last binary digit must be 0, and the last binary digits encode the last element of set A. So even numbers correspond to subsets where the last element is not included.

1.3.2 What is the number of subsets of a set with n elements, containing a given element?
Answer: let A be a set of n elements. For every subset S of A, S either contain the element or doesn't. Thus, the number of subsets of a that contain a given element is exactly half the subsets of A, or (2**n)/2 eq= 2**(n-1).


1.3.4 What is the number of integers (positive and negative) with 
a) at most n digits
  Ans: for a number of at most n digits, there are 10 choices (0-9) at each digits, so the choices are 10**n. Since a number can either be positive or negative, we have to double our count 2*10**n. Since 0 can only be counted once, but we have already double it, we need to substract one from our count: 2*10**n-1
b) exactly n digits
  Ans: to be exactly n digits, the first digit cannot be zero; this implies that we only have 9 choices (1-9) for the first digit. The other (n-1) digits have 10 choices(0-9). This implies 9*10**(n-1). Since the number can be either positive or negative, we need to double our count to obtain:
  2*9*10**(n-1). Unlike previous answer, we don't count '0' because '0' isn't exactly n digits for n>1. For n=1, there are 19 numbers because we need to count zero.
