CSCI 340 FALL 2020
Taught by Dr. Anthony Leclerc

Project by: Nathan Bell and Hollande Powell




This program is meant to be able to find through experimentation
	1) how big is a cache block?
	2) how big is the cache?
	3) how long does a reference to main memory take to complete?
	4) how long does a reference that can be satisfied from cache take to complete?
	
	
This README file will go through our findings for each of these questions.

So from the start it seems like this is a project that wont ever be able to find any straight answers.

If we were to be able to get any definitive answer there would be no need for "experimentation" as mentioned in the assignment pdf.

With prefetching it is hard to ensure where data is being pulled from.

And the cpu never being solely used for the program we are running any timing we do will have unpredictable variability.  



How big is a cache block?




How big is the cache?





How long does a reference to main memory take to complete?





HOW LONG DOES A REFERENCE TO THAT CAN BE SATISFIED FROM CACHE TAKE TO COMPLETE?
	In order to try and figure out the answer to this question we came up with the method we call avgCacheTime.
	In that method we get the time in nanoseconds before and after a loop that indexes the first position in an array over and over again for the entire size of the array. 
	Then average the time passed out to find a number that should represent the amount of nanoseconds it takes on average for a reference to cache to be made. 
	
	
	THIS CAME OUT TO AROUND 2.8 NANOSECONDS
	
	
	This likely is a bit longer than what it actually takes but due to external circumstances and processing other lines like the for loop or the line that gets the end time. 
	
