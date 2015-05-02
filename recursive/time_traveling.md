# Time-Traveling Technique for recursion

A simple method to turn recursion into one-time loop:
    1. Find all recursive calls that are not tail-calls
    2. Identfy what works are being done by recursion.
    3. Extend the function with accumulator with default value that does nothing.
    4. Turn the accumulator into tail-call
    5. Repeat until all recursive calls are tail-calls

    def binomial(n, k):
        '''
         given n items, how many ways to select k items
         this is a counting problem, hence recursive solution
         binomial(n,k) = n!/(k!*(n-k)!)
         Notes :
         1. division must be done at the end.
         2. Using python's '//' operator that will throw away
            remainders.
        '''
        if k == 0:
            return 1
        return n*binomial(n-1, k-1)//k

Applying the simple-method, we identify the recursive call:

    def binomial(n, k):
        if k == 0:
            return 1
        return n*binomial(n-1, k-1)//k
                 ^^^^^^^^^^^^^^^^^^
                 recursive call

 We can separate the recursive call from the return statement for added clarity:

    def binomial(n, k):
        if k == 0:
            return 1
        x = binomial(n-1,k-1)
        return n*x//k

Now add in another function and the accumulators

    def work(x,lmul,rdiv):
        return x*lmul//rdiv

    #lmul and rdiv are accumulators
    def binomial(n, k,lmul=1,rdiv=1):
        if k == 0:
            return work(1,lmul,rdiv)
        # doing nothing because lmul and rdiv are both an identity.
        return work(n*binomial(n-1,k-1)//k,lmul,rdiv)

Now we can turn the funciton above into a tail-call recursion


    def binomial(n, k,lmul=1,rdiv=1):
        if k == 0:
            return work(1,lmul,rdiv)
        return binomial(n-1,k-1,n*lmul,k*rdiv)

Now we can turn this into a one-time loop:

    def binomial_iterative(n, k):
        lmul,rdiv=(1,1)
        while k>0:
            (n,k,lmul,rdiv) = (n-1,k-1,n*lmul,k*rdiv)
        return lmul//rdiv

This function is the same as the recursive solution; however this function would not run into stack-overflowing issue.

Explaination: 
    . In a normal binomial calculation, we find the n! first, then multiply k! by (n-k)!. This results in insanely huge number
    . The function binomial_iterative separte the calculation n!/(n-k)! and k!
    . This function is not calculating n! and (n-k)! separately. In fact, the function is calculating n!/(n-k)! altogether.
