#Combinatorial Tools


##Estimating how many digits in a number

Given n!, how many digits are in 'n!'?


##Inclusion-Exclusion formula:

For a set of size N:

N - subset(1 item) +subset(2 items) - subset(3 item) + subset(4 item) ...
= number of subsets left that doesn't belong to any.


## Combination and binomial:

Given a set of size N: number of subsets is 2\*\*n

2\*\*n = (1+1)\*\*n = bino(n,0) + bino(n,1) + bino(n,2) + .. + bino(n,n)

bino(n,k): from a set of n, how many subsets with size k?

Explaination: count the subsets with zero element (exactly 1 null set), count
the subset with exactly 1 element, 2 elements, ... n elements. Then sum them up.
This gives the total number of subsets with size from 0 to n.


## Distribution
Give a set with n element.

Want to distribute n-element into group of n1 element, n2 element, n3 element
.. nk elemnts.

And n1+n2+..+nk = n

Two ways to look at this


### First way of thinking

From n element, we pick n! elements, so there are bino(n,n1).

After picking n1, element, we have left (n-n1) elements. From (n-n1) elements,
we are going to pick n2.... After picking the first element for n1, we pick n2
... so the reuslt is : bino(n,n1)\*bino(n-n1,n2)\*..\*bino(n-nk+1,nk)


### Second way of thinking

We take n1 elements from a permutation of n-element set and give them to group
one. Then take n2 elements and give them to group 2... take nk and give to group
k.

Group 1 has n1 elements, so there are n1! combinations of these elements.

Group 2 has n2! combinations.

Group k has n2! combinations.

Since group 1 has n1! combinations, there are other n-element sets where the
first n1 elements are the same as group 1 but belong to one of the n1!
combinations. From these sets, there are also sets where the next n2 elements
are one of the n2! combinations and so on. How many of of these n-element set
are there? Precisely n1!\*n2!\*..\*nk!. So there are n1!\*n2!\*..\*nk! where the
first n1 elements are the same but in different order, the next n2 elements are
the same but in different order, and so on till nk.

This form one super group, where the first n1 elements are the same but in
different order, the next n2 elements are the same but in different order, ...
until nk.

So we have n1!\*n2!\*..\*nk! ways to arrange the super group.

take n!/n1!\*n2!\*..\*nk! gives the number of these super groups. This number is
the distributions.

**Final Solution: bino(n,n1)\*bino(n-n1,n2)\*..bino(n-k+1,nk) = n!/n!\*n2\*..\*nk!**


*See permu.txt for distribution of a set of { 1,2,3,4,5 } into a group of
size 2 and a group of size 3. The super group has size 2!\*3!=12. 5!=120.Thus,
there are 10 super group. __Notice__ that in each super group, the first
2 elements in the set are the same but in different order; the next 3 elements
of each sets are also the same but in different order.*



## Distribute n identical items to k group, each group get at least one element

[Known as a **stars and bars** problem](http://en.wikipedia.org/wiki/Stars_and_bars_%28combinatorics%29)

Ans: bino(n-1,k-1)

There are two ways to intepret binomail(n,k):

1. from n elements, distributes to k groups where the size of the group is 1.

2. From n elements, distributes to k groups where the size of the group is more
   than 1 and the sum of the size of k groups is exactly n.

The distribution of pennies to k children is exactly case 2. Each child receives
a group of pennies, and total size of all the pennies the children receive is
exactly n.
