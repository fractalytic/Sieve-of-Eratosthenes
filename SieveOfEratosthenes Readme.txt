Sieve of Eratosthenes v1.00 by Fractalytic
------------------------------------------


Overview
--------

The Sieve of Eratosthenes is a process for determining prime numbers. 

It works by first starting with every number from 2 to some limit written down. 

You look at the first number that is written in the list (in this case 2) and then cross out every multiple of 2 (except for 2 itself). You move on to the next number that isn't crossed out (in this case 3 as that isn't a multiple of 2) and proceed to cross out every multiple of 3 that you haven't already crossed out (except for 3 itself). You go on to the next number that you haven't crossed out (in this case 5 because 4 was crossed out as it's a multiple of 2) and you repeat the process. You continue in this way until you've gone through every number up to your limit and what's left will be the prime numbers.

This program is a simple console based app that does the same thing for any limit that you choose up to 150,000 and will display all of the primes, as well as a count and their sum. It will also time how long it took to create and display the primes.

It's not very interactive but the code can be found on my website and also in the SoloLearn app. Additions could be made such as increasing the minimum and maximum limits but I don't intend to do much else with this one.

If I do update the program the latest version of will be found on my website: http://www.fractalytic.co.uk

Thank you for downloading.



Instructions
------------

The program will generate prime numbers from 2 to a value you specify up to 150,000. After displaying the primes it will ask if you want another go, anything other than y will close the program.



Version History
---------------

v1.00 First release 
